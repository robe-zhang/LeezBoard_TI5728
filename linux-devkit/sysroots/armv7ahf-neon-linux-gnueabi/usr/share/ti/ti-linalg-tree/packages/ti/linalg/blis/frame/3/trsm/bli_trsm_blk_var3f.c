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

void bli_trsm_blk_var3f( obj_t*  a,
                         obj_t*  b,
                         obj_t*  c,
                         trsm_t* cntl,
                         trsm_thrinfo_t* thread )
{
    obj_t  c_pack_s;
    obj_t  a1_pack_s, b1_pack_s;

    obj_t  a1, b1;
    obj_t* a1_pack = NULL;
    obj_t* b1_pack = NULL;
    obj_t* c_pack = NULL;
#ifdef BLIS_ENABLE_C66X_EDMA
    obj_t a1_dma_s, b1_dma_s;
	obj_t *a1_dma = NULL;
	obj_t *b1_dma = NULL;
#endif

	dim_t  i;
	dim_t  b_alg;
	dim_t  k_trans;
#ifdef BLIS_ENABLE_C66X_EDMA
	dim_t b_alg_next;
#endif

	// Initialize pack objects for C that are passed into packm_init().
    if( thread_am_ochief( thread ) ) {
	    bli_obj_init_pack( &c_pack_s );

        // Initialize object for packing C.
        bli_packm_init( c, &c_pack_s,
                        cntl_sub_packm_c( cntl ) );

        // Scale C by beta (if instructed).
        bli_scalm_int( &BLIS_ONE,
                       c,
                       cntl_sub_scalm( cntl ) );
    }
    c_pack = thread_obroadcast( thread, &c_pack_s );

    if( thread_am_ichief( thread ) ) {
#ifdef BLIS_ENABLE_C66X_EDMA
    	bli_obj_init_dma( &a1_dma_s);
    	bli_obj_init_dma( &b1_dma_s );
#endif
        bli_obj_init_pack( &a1_pack_s );
        bli_obj_init_pack( &b1_pack_s );
    }
#ifdef BLIS_ENABLE_C66X_EDMA
    a1_dma = thread_ibroadcast( thread, &a1_dma_s);
    b1_dma = thread_ibroadcast( thread, &b1_dma_s);
#endif
    a1_pack = thread_ibroadcast( thread, &a1_pack_s );
    b1_pack = thread_ibroadcast( thread, &b1_pack_s );

	// Pack C (if instructed).
	bli_packm_int( c, c_pack,
	               cntl_sub_packm_c( cntl ),
                   trsm_thread_sub_opackm( thread ) );

	// Query dimension in partitioning direction.
	k_trans = bli_obj_width_after_trans( *a );

	// Partition along the k dimension.
	for ( i = 0; i < k_trans; i += b_alg )
	{
#ifdef BLIS_ENABLE_C66X_EDMA
		//printf("i = %d\n ", i);

		if (i == 0)
		{
			b_alg = bli_trsm_determine_kc_f( i, k_trans, b,
					cntl_blocksize( cntl ) );

			// Acquire partitions for A1 and B1.
			bli_acquire_mpart_l2r( BLIS_SUBPART1,
					i, b_alg, a, &a1 );
			bli_acquire_mpart_t2b( BLIS_SUBPART1,
					i, b_alg, b, &b1 );
			if( thread_am_ichief( thread ) )
			{
				// DMA control leaf unrolling for A
				//printf("Init DMA A2\n");
				//printf("b1_dma %x ", bli_mem_buffer(&(b1_dma->dma_mem)));
				bli_dmam_init( &a1, a1_dma, cntl_sub_dmam_a( cntl ) );
				bli_dmam_init( &b1, b1_dma, cntl_sub_dmam_b( cntl ) );
			}
			thread_ibarrier( thread );
			bli_dmam_int( &a1, a1_dma, cntl_sub_dmam_a( cntl ), (dmam_thrinfo_t *) trsm_thread_sub_ipackm( thread ) );
			bli_dmam_int( &b1, b1_dma, cntl_sub_dmam_b( cntl ), (dmam_thrinfo_t *) trsm_thread_sub_ipackm( thread ) );

		}
		else
		{
			b_alg = b_alg_next;
		}

		bli_dmam_wait(a1_dma, cntl_sub_dmam_a( cntl ), (dmam_thrinfo_t *) trsm_thread_sub_ipackm( thread ));
		bli_dmam_wait(b1_dma, cntl_sub_dmam_b( cntl ), (dmam_thrinfo_t *) trsm_thread_sub_ipackm( thread ));
		thread_ibarrier( thread );

		// Initialize objects for packing A1 and B1.
		if( thread_am_ichief( thread ) ) {
			bli_packm_init( a1_dma, a1_pack,
					cntl_sub_packm_a( cntl ) );
			bli_packm_init( b1_dma, b1_pack,
					cntl_sub_packm_b( cntl ) );
		}
		thread_ibarrier( thread );
		//printf("b1_pack %x ", bli_mem_buffer(&(b1_pack->pack_mem)));
		//printf("b_alg = %d offm %d offn %d \n ", b_alg, bli_obj_row_offset(b1), bli_obj_col_offset(b1));

		// Pack A1 (if instructed).
		bli_packm_int( a1_dma, a1_pack,
				cntl_sub_packm_a( cntl ),
				trsm_thread_sub_ipackm( thread ) );

		// Pack B1 (if instructed).
		bli_packm_int( b1_dma, b1_pack,
				cntl_sub_packm_b( cntl ),
				trsm_thread_sub_ipackm( thread ) );

		//printf("blk_var3: b: m %d n %d\n", bli_obj_length( b1 ), bli_obj_width( b1));
		//printf("blk_var3: b: m_panel %d n_panel %d\n", bli_obj_panel_length( *b1_pack ), bli_obj_panel_width( *b1_pack ));

		//Get the next partition and start DMA
		if( (i+b_alg) < k_trans ) //Making sure we aren't at the end of the matrix
		{
			if ( i == 0 && thread_am_ichief( thread ) )
			{
				bli_obj_scalar_reset( a );
				bli_obj_scalar_reset( b );
			}
			b_alg_next = bli_trsm_determine_kc_f( i+b_alg, k_trans, b,
			                                 cntl_blocksize( cntl ) );

			// Acquire partitions for A1 and B1.
			bli_acquire_mpart_l2r( BLIS_SUBPART1,
			                       i+b_alg, b_alg_next, a, &a1 );
			bli_acquire_mpart_t2b( BLIS_SUBPART1,
			                       i+b_alg, b_alg_next, b, &b1 );

			if( thread_am_ichief( thread ) )
			{
				// DMA control leaf unrolling for A
				//printf("Init DMA A2\n");
				bli_dmam_init( &a1, a1_dma, cntl_sub_dmam_a( cntl ) );
				bli_dmam_init( &b1, b1_dma, cntl_sub_dmam_b( cntl ) );
			}
			thread_ibarrier( thread );
			bli_dmam_int( &a1, a1_dma, cntl_sub_dmam_a( cntl ), (dmam_thrinfo_t *) trsm_thread_sub_ipackm( thread ) );
			bli_dmam_int( &b1, b1_dma, cntl_sub_dmam_b( cntl ), (dmam_thrinfo_t *) trsm_thread_sub_ipackm( thread ) );

		}


#else
		// Determine the current algorithmic blocksize.
		// NOTE: We call a trsm-specific function to determine the kc
		// blocksize so that we can implement the "nudging" of kc to be
		// a multiple of mr, as needed.
		b_alg = bli_trsm_determine_kc_f( i, k_trans, b,
		                                 cntl_blocksize( cntl ) );

		// Acquire partitions for A1 and B1.
		bli_acquire_mpart_l2r( BLIS_SUBPART1,
		                       i, b_alg, a, &a1 );
		bli_acquire_mpart_t2b( BLIS_SUBPART1,
		                       i, b_alg, b, &b1 );

		// Initialize objects for packing A1 and B1.
        if( thread_am_ichief( thread ) ) {
            bli_packm_init( &a1, a1_pack,
                            cntl_sub_packm_a( cntl ) );
            bli_packm_init( &b1, b1_pack,
                            cntl_sub_packm_b( cntl ) );
        }
        thread_ibarrier( thread );

		// Pack A1 (if instructed).
		bli_packm_int( &a1, a1_pack,
		               cntl_sub_packm_a( cntl ),
                       trsm_thread_sub_ipackm( thread ) );

		// Pack B1 (if instructed).
		bli_packm_int( &b1, b1_pack,
		               cntl_sub_packm_b( cntl ),
                       trsm_thread_sub_ipackm( thread ) );
#endif
		// Perform trsm subproblem.
		bli_trsm_int( &BLIS_ONE,
		              a1_pack,
		              b1_pack,
		              &BLIS_ONE,
		              c_pack,
		              cntl_sub_trsm( cntl ),
                      trsm_thread_sub_trsm( thread ) );

		// This variant executes multiple rank-k updates. Therefore, if the
		// internal alpha scalars on A/B and C are non-zero, we must ensure
		// that they are only used in the first iteration.
        if ( i == 0 ) thread_ibarrier( thread );
		if ( i == 0 && thread_am_ichief( thread ) ) { 
#ifndef BLIS_ENABLE_C66X_EDMA
            bli_obj_scalar_reset( a );
            bli_obj_scalar_reset( b );
#endif
            bli_obj_scalar_reset( c_pack ); 
        }
	}

    thread_obarrier( thread );

	// Unpack C (if C was packed).
    bli_unpackm_int( c_pack, c,
                     cntl_sub_unpackm_c( cntl ),
                     trsm_thread_sub_opackm( thread ) );

	// If any packing buffers were acquired within packm, release them back
	// to the memory manager.
    if( thread_am_ochief( thread ) ) {
	    bli_obj_release_pack( c_pack , cntl_sub_packm_c(cntl) );
    }
    if( thread_am_ichief( thread ) ) {
#ifdef BLIS_ENABLE_C66X_EDMA
        bli_obj_release_dma( a1_dma, cntl_sub_dmam_a(cntl) );
        bli_obj_release_dma( b1_dma, cntl_sub_dmam_b(cntl) );
		bli_obj_release_emt_handle( a1_dma );
		bli_obj_release_emt_handle( b1_dma );
#endif
        bli_obj_release_pack( a1_pack, cntl_sub_packm_a(cntl) );
        bli_obj_release_pack( b1_pack, cntl_sub_packm_b(cntl) );
    }
}

