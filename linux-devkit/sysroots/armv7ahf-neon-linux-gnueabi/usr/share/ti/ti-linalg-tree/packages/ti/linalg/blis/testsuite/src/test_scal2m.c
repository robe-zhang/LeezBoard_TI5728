/*

   BLIS    
   An object-based framework for developing high-performance BLAS-like
   libraries.

   Copyright (C) 2014, The University of Texas at Austin

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    - Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    - Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    - Neither the name of The University of Texas at Austin nor the names
      of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
   HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#include "blis.h"
#include "test_libblis.h"


// Static variables.
static char*     op_str                    = "scal2m";
static char*     o_types                   = "mm";  // x y
static char*     p_types                   = "h";   // conjx
static thresh_t  thresh[BLIS_NUM_FP_TYPES] = { { 1e-04, 1e-05 },   // warn, pass for s
                                               { 1e-04, 1e-05 },   // warn, pass for c
                                               { 1e-13, 1e-14 },   // warn, pass for d
                                               { 1e-13, 1e-14 } }; // warn, pass for z

// Local prototypes.
void libblis_test_scal2m_deps( test_params_t* params,
                               test_op_t*     op );

void libblis_test_scal2m_experiment( test_params_t* params,
                                     test_op_t*     op,
                                     iface_t        iface,
                                     num_t          datatype,
                                     char*          pc_str,
                                     char*          sc_str,
                                     unsigned int   p_cur,
                                     perf_t*        perf,
                                     double*        resid );

void libblis_test_scal2m_impl( iface_t   iface,
                               obj_t*    alpha,
                               obj_t*    x,
                               obj_t*    y );

void libblis_test_scal2m_check( obj_t*  alpha,
                                obj_t*  x,
                                obj_t*  y,
                                obj_t*  y_save,
                                double* resid );



void libblis_test_scal2m_deps( test_params_t* params, test_op_t* op )
{
	libblis_test_randm( params, &(op->ops->randm) );
	libblis_test_normfm( params, &(op->ops->normfm) );
	libblis_test_subm( params, &(op->ops->subm) );
	libblis_test_copym( params, &(op->ops->copym) );
	libblis_test_scalm( params, &(op->ops->scalm) );
}



void libblis_test_scal2m( test_params_t* params, test_op_t* op )
{

	// Return early if this test has already been done.
	if ( op->test_done == TRUE ) return;

	// Return early if operation is disabled.
	if ( op->op_switch == DISABLE_ALL ||
	     op->ops->l1m_over == DISABLE_ALL ) return;

	// Call dependencies first.
	if ( TRUE ) libblis_test_scal2m_deps( params, op );

	// Execute the test driver for each implementation requested.
	if ( op->front_seq == ENABLE )
	{
		libblis_test_op_driver( params,
		                        op,
		                        BLIS_TEST_SEQ_FRONT_END,
		                        op_str,
		                        p_types,
		                        o_types,
		                        thresh,
		                        libblis_test_scal2m_experiment );
	}
}



void libblis_test_scal2m_experiment( test_params_t* params,
                                     test_op_t*     op,
                                     iface_t        iface,
                                     num_t          datatype,
                                     char*          pc_str,
                                     char*          sc_str,
                                     unsigned int   p_cur,
                                     perf_t*        perf,
                                     double*        resid )
{
	unsigned int n_repeats = params->n_repeats;
	unsigned int i;

	double       time_min  = 1e9;
	double       time;

	dim_t        m, n;

	trans_t      transx;

	obj_t        alpha, x, y;
	obj_t        y_save;


	// Map the dimension specifier to actual dimensions.
	m = libblis_test_get_dim_from_prob_size( op->dim_spec[0], p_cur );
	n = libblis_test_get_dim_from_prob_size( op->dim_spec[1], p_cur );

	// Map parameter characters to BLIS constants.
	bli_param_map_char_to_blis_trans( pc_str[0], &transx );

	// Create test scalars.
	bli_obj_scalar_init_detached( datatype, &alpha );

	// Create test operands (vectors and/or matrices).
	libblis_test_mobj_create( params, datatype, transx,
	                          sc_str[0], m, n, &x );
	libblis_test_mobj_create( params, datatype, BLIS_NO_TRANSPOSE,
	                          sc_str[0], m, n, &y );
	libblis_test_mobj_create( params, datatype, BLIS_NO_TRANSPOSE,
	                          sc_str[0], m, n, &y_save );

	// Set alpha.
	if ( bli_obj_is_real( y ) )
		bli_setsc( -2.0,  0.0, &alpha );
	else
		bli_setsc(  0.0, -2.0, &alpha );

	// Randomize and save y.
	bli_randm( &x );
	bli_setm( &BLIS_ONE, &y );
	bli_copym( &y, &y_save );

	// Apply the parameters.
	bli_obj_set_conjtrans( transx, x );

	// Repeat the experiment n_repeats times and record results. 
	for ( i = 0; i < n_repeats; ++i )
	{
		bli_copym( &y_save, &y );

		time = bli_clock();

		libblis_test_scal2m_impl( iface, &alpha, &x, &y );

		time_min = bli_clock_min_diff( time_min, time );
	}

	// Estimate the performance of the best experiment repeat.
	perf->gflops = ( 2.0 * m * n ) / time_min / FLOPS_PER_UNIT_PERF;
	if ( bli_obj_is_complex( y ) ) perf->gflops *= 4.0;
	perf->time = time_min;

	// Perform checks.
	libblis_test_scal2m_check( &alpha, &x, &y, &y_save, resid );

	// Zero out performance and residual if output matrix is empty.
	libblis_test_check_empty_problem( &y, perf, resid );

	// Free the test objects.
	bli_obj_free( &x );
	bli_obj_free( &y );
	bli_obj_free( &y_save );
}



void libblis_test_scal2m_impl( iface_t   iface,
                               obj_t*    alpha,
                               obj_t*    x,
                               obj_t*    y )
{
	switch ( iface )
	{
		case BLIS_TEST_SEQ_FRONT_END:
		bli_scal2m( alpha, x, y );
		break;

		default:
		libblis_test_printf_error( "Invalid interface type.\n" );
	}
}



void libblis_test_scal2m_check( obj_t*  alpha,
                                obj_t*  x,
                                obj_t*  y,
                                obj_t*  y_orig,
                                double* resid )
{
	num_t  dt      = bli_obj_datatype( *y );
	num_t  dt_real = bli_obj_datatype_proj_to_real( *y );

	dim_t  m       = bli_obj_length( *y );
	dim_t  n       = bli_obj_width( *y );

	obj_t  x_temp;
	obj_t  norm;

	double junk;

	//
	// Pre-conditions:
	// - x is randomized.
	// - y_orig is set to one.
	// Note:
	// - alpha should have a non-zero imaginary component in the complex
	//   cases in order to more fully exercise the implementation.
	//
	// Under these conditions, we assume that the implementation for
	//
	//   y := alpha * conjx(x)
	//
	// is functioning correctly if
	//
	//   normf( y - alpha * conjx(x) )
	//
	// is negligible.
	//

	bli_obj_scalar_init_detached( dt_real, &norm );

    bli_obj_create( dt, m, n, 0, 0, &x_temp );

    bli_copym( x, &x_temp );

    bli_scalm( alpha, &x_temp );

    bli_subm( &x_temp, y );
    bli_normfm( y, &norm );
    bli_getsc( &norm, resid, &junk );

    bli_obj_free( &x_temp );
}

