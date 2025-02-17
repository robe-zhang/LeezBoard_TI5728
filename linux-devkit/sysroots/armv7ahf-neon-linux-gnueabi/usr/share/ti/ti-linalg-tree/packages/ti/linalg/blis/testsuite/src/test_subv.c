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
static char*     op_str                    = "subv";
static char*     o_types                   = "vv";  // x y
static char*     p_types                   = "c";   // conjx
static thresh_t  thresh[BLIS_NUM_FP_TYPES] = { { 1e-04, 1e-05 },   // warn, pass for s
                                               { 1e-04, 1e-05 },   // warn, pass for c
                                               { 1e-13, 1e-14 },   // warn, pass for d
                                               { 1e-13, 1e-14 } }; // warn, pass for z

// Local prototypes.
void libblis_test_subv_deps( test_params_t* params,
                             test_op_t*     op );

void libblis_test_subv_experiment( test_params_t* params,
                                   test_op_t*     op,
                                   iface_t        iface,
                                   num_t          datatype,
                                   char*          pc_str,
                                   char*          sc_str,
                                   unsigned int   p_cur,
                                   perf_t*        perf,
                                   double*        resid );

void libblis_test_subv_impl( iface_t   iface,
                             obj_t*    x,
                             obj_t*    y );

void libblis_test_subv_check( obj_t*  alpha,
                              obj_t*  beta,
                              obj_t*  x,
                              obj_t*  y,
                              double* resid );



void libblis_test_subv_deps( test_params_t* params, test_op_t* op )
{
	libblis_test_setv( params, &(op->ops->setv) );
	libblis_test_normfv( params, &(op->ops->normfv) );
}



void libblis_test_subv( test_params_t* params, test_op_t* op )
{

	// Return early if this test has already been done.
	if ( op->test_done == TRUE ) return;

	// Return early if operation is disabled.
	if ( op->op_switch == DISABLE_ALL ||
	     op->ops->l1v_over == DISABLE_ALL ) return;

	// Call dependencies first.
	if ( TRUE ) libblis_test_subv_deps( params, op );

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
		                        libblis_test_subv_experiment );
	}
}



void libblis_test_subv_experiment( test_params_t* params,
                                   test_op_t*     op,
                                   iface_t        iface,
                                   num_t          datatype,
                                   char*          pc_str,
                                   char*          sc_str,
                                   unsigned int   p_cur,
                                   perf_t*        perf,
                                   double*        resid )
{
	double       time_min  = 1e9;
	double       time;

	dim_t        m;

	conj_t       conjx;

	obj_t        alpha, beta;
	obj_t        x, y;


	// Map the dimension specifier to an actual dimension.
	m = libblis_test_get_dim_from_prob_size( op->dim_spec[0], p_cur );

	// Map parameter characters to BLIS constants.
	bli_param_map_char_to_blis_conj( pc_str[0], &conjx );

	// Create test scalars.
	bli_obj_scalar_init_detached( datatype, &alpha );
	bli_obj_scalar_init_detached( datatype, &beta );

	// Create test operands (vectors and/or matrices).
	libblis_test_vobj_create( params, datatype, sc_str[0], m, &x );
	libblis_test_vobj_create( params, datatype, sc_str[1], m, &y );

	// Initialize alpha and beta.
	bli_setsc( 1.0, 1.0, &alpha );
	bli_setsc( 3.0, 3.0, &beta );

	// Set x and y to alpha and beta, respectively.
	bli_setv( &alpha, &x );
	bli_setv( &beta,  &y );

	// Apply the parameters.
	bli_obj_set_conj( conjx, x );

	// Disable repeats since bli_copyv() is not yet tested. 
	//for ( i = 0; i < n_repeats; ++i )
	{
		time = bli_clock();

		libblis_test_subv_impl( iface, &x, &y );

		time_min = bli_clock_min_diff( time_min, time );
	}

	// Estimate the performance of the best experiment repeat.
	perf->gflops = ( 2.0 * m ) / time_min / FLOPS_PER_UNIT_PERF;
	if ( bli_obj_is_complex( x ) ) perf->gflops *= 2.0;
	perf->time = time_min;

	// Perform checks.
	libblis_test_subv_check( &alpha, &beta, &x, &y, resid );

	// Zero out performance and residual if output vector is empty.
	libblis_test_check_empty_problem( &y, perf, resid );

	// Free the test objects.
	bli_obj_free( &x );
	bli_obj_free( &y );
}



void libblis_test_subv_impl( iface_t   iface,
                             obj_t*    x,
                             obj_t*    y )
{
	switch ( iface )
	{
		case BLIS_TEST_SEQ_FRONT_END:
		bli_subv( x, y );
		break;

		default:
		libblis_test_printf_error( "Invalid interface type.\n" );
	}
}



void libblis_test_subv_check( obj_t*  alpha,
                              obj_t*  beta,
                              obj_t*  x,
                              obj_t*  y,
                              double* resid )
{
	num_t  dt      = bli_obj_datatype( *x );
	num_t  dt_real = bli_obj_datatype_proj_to_real( *x );
	dim_t  m       = bli_obj_vector_dim( *x );

	conj_t conjx   = bli_obj_conj_status( *x );

	obj_t  aminusb;
	obj_t  alpha_conj;
	obj_t  norm_r, m_r, temp_r;

	double junk;

	//
	// Pre-conditions:
	// - x is set to alpha.
	// - y_orig is set to beta.
	// Note:
	// - alpha and beta should have non-zero imaginary components in the
	//   complex cases in order to more fully exercise the implementation.
	//
	// Under these conditions, we assume that the implementation for
	//
	//   y := y_orig - conjx(x)
	//
	// is functioning correctly if
	//
	//   normfv(y) - sqrt( absqsc( beta - conjx(alpha) ) * m )
	//
	// is negligible.
	//

	bli_obj_scalar_init_detached( dt,      &aminusb );
	bli_obj_scalar_init_detached( dt_real, &temp_r );
	bli_obj_scalar_init_detached( dt_real, &norm_r );
	bli_obj_scalar_init_detached( dt_real, &m_r );

	bli_obj_scalar_init_detached_copy_of( dt, conjx, alpha, &alpha_conj );

	bli_normfv( y, &norm_r );

	bli_copysc( beta, &aminusb );
	bli_subsc( &alpha_conj, &aminusb );

	bli_setsc( ( double )m, 0.0, &m_r );

	bli_absqsc( &aminusb, &temp_r );
	bli_mulsc( &m_r, &temp_r );
	bli_sqrtsc( &temp_r, &temp_r );
	bli_subsc( &temp_r, &norm_r );

	bli_getsc( &norm_r, resid, &junk );
}

