#ifdef BETA0
#define ATL_INT int
#include <stdio.h>
#include <stdint.h>
#include <pmmintrin.h>

#define I_UNROLL 1
#define J_UNROLL 1
/* Is prefetched data written or just read? */
#define PF_READONLY 0
#define PF_READWRITE 1
#define PF_NO_REUSE 0

/* Default temporality of cache prefetch (1-3) */
#define PF_DEF 1
#define CACHE_LINE_SIZE 64
#define MMCAST( a ) (a)
#define MMCASTStore( a ) (a)
#define MMCASTStoreintrin( a ) (a)
#define TYPE float
void ATL_USERMM( const ATL_INT M, const ATL_INT N, const ATL_INT K,
                 const TYPE alpha, const TYPE *A, const ATL_INT lda,
                 const TYPE *B, const ATL_INT ldb,
                 const TYPE beta, TYPE *C, const ATL_INT ldc )
{
   register ATL_INT i, j, k;
   
   /* Vector registers to hold the elements of C */
   __m128 c0_0;
   /* Temporary vector registers for use in inner loop */
   __m128 temp; 
   /* Pointer adjustments */  
   register const ATL_INT ldc_bytes = ldc;
   
   register TYPE const *B0_off = B;
      
   
   /* Unroll A */
   __m128 A0, a0;
   /* Unroll B */
   __m128 B0, B1;
   

   register const ATL_INT unroll_a = I_UNROLL*KB;
   register TYPE* cPtr = C;
   

   /* =======================================
    * Begin generated inner loops for case Non aligned
    * ======================================= */
   for( j=-48; j!=0; j+=J_UNROLL) 
   {
      register TYPE const *A0_off = A; 
      
      register TYPE *cPtrI0 = cPtr;
      

      for( i=-48; i != 0; i+= I_UNROLL )
      {
         /* K_Unrolling0 */
         A0 = _mm_load_ps( MMCAST(A0_off) );
         B0 = _mm_load_ps( MMCAST(B0_off) );
         c0_0 = B0;
         c0_0 = _mm_mul_ps( A0, c0_0 );
         
         for( k=4; k<48; k+=4 )
         {
            /* k_partialUnrolling: 0 */
            B0 = _mm_load_ps( MMCAST( B0_off + k ) );
            A0 = _mm_load_ps( MMCAST(A0_off + k));
            temp = _mm_mul_ps( B0, A0 );
            c0_0 = _mm_add_ps( temp, c0_0 );
         }
         /* Single Scalar Compression */
         /* additional remaining step */
         c0_0 = _mm_hadd_ps( c0_0, c0_0 );
         c0_0 = _mm_hadd_ps( c0_0, c0_0 );
         /* Applying Beta */
         /* No beta will be appied */
         /* Move pointers to next iteration */  
         A0_off += unroll_a;
         
         /* Store results back to memory  */
         _mm_store_ss( cPtrI0,  c0_0 );
         cPtrI0 += I_UNROLL;
         

      } /* End i/MB loop */

      B0_off += J_UNROLL*KB;
      cPtr += J_UNROLL*ldc_bytes;
   } /* End j/NB loop */
   /* End of generated inner loops */
}
#elif defined(BETAX)
#define ATL_INT int
#include <stdio.h>
#include <stdint.h>
#include <pmmintrin.h>

#define I_UNROLL 1
#define J_UNROLL 1
/* Is prefetched data written or just read? */
#define PF_READONLY 0
#define PF_READWRITE 1
#define PF_NO_REUSE 0

/* Default temporality of cache prefetch (1-3) */
#define PF_DEF 1
#define CACHE_LINE_SIZE 64
#define MMCAST( a ) (a)
#define MMCASTStore( a ) (a)
#define MMCASTStoreintrin( a ) (a)
#define TYPE float
void ATL_USERMM( const ATL_INT M, const ATL_INT N, const ATL_INT K,
                 const TYPE alpha, const TYPE *A, const ATL_INT lda,
                 const TYPE *B, const ATL_INT ldb,
                 const TYPE beta, TYPE *C, const ATL_INT ldc )
{
   register ATL_INT i, j, k;
   
   /* Vector registers to hold the elements of C */
   __m128 c0_0;
   /* Vector register to hold C*beta */
   __m128 bc0_0;
   /* Temporary vector registers for use in inner loop */
   __m128 temp; 
   const __m128 betaV = _mm_set1_ps( beta ); 
   /* Pointer adjustments */  
   register const ATL_INT ldc_bytes = ldc;
   
   register TYPE const *B0_off = B;
      
   
   /* Unroll A */
   __m128 A0, a0;
   /* Unroll B */
   __m128 B0, B1;
   

   register const ATL_INT unroll_a = I_UNROLL*KB;
   register TYPE* cPtr = C;
   

   /* =======================================
    * Begin generated inner loops for case Non aligned
    * ======================================= */
   for( j=-48; j!=0; j+=J_UNROLL) 
   {
      register TYPE const *A0_off = A; 
      
      register TYPE *cPtrI0 = cPtr;
      

      for( i=-48; i != 0; i+= I_UNROLL )
      {
         /* K_Unrolling0 */
         A0 = _mm_load_ps( MMCAST(A0_off) );
         B0 = _mm_load_ps( MMCAST(B0_off) );
         c0_0 = B0;
         c0_0 = _mm_mul_ps( A0, c0_0 );
         
         for( k=4; k<48; k+=4 )
         {
            /* k_partialUnrolling: 0 */
            B0 = _mm_load_ps( MMCAST( B0_off + k ) );
            A0 = _mm_load_ps( MMCAST(A0_off + k));
            temp = _mm_mul_ps( B0, A0 );
            c0_0 = _mm_add_ps( temp, c0_0 );
         }
         /* Single Scalar Compression */
         /* additional remaining step */
         c0_0 = _mm_hadd_ps( c0_0, c0_0 );
         c0_0 = _mm_hadd_ps( c0_0, c0_0 );
         /* Applying Beta */
            /* Apply Beta Factor */
            /* Load C from memory */
            /* 1 remaining */
            bc0_0 = _mm_load_ss( cPtrI0+0 );
            bc0_0 = _mm_mul_ss( betaV, bc0_0 );
            /* C = (beta*C) + (matrix multiply) */
            c0_0 = _mm_add_ss( bc0_0, c0_0 );
         /* Move pointers to next iteration */  
         A0_off += unroll_a;
         
         /* Store results back to memory  */
         _mm_store_ss( cPtrI0,  c0_0 );
         cPtrI0 += I_UNROLL;
         

      } /* End i/MB loop */

      B0_off += J_UNROLL*KB;
      cPtr += J_UNROLL*ldc_bytes;
   } /* End j/NB loop */
   /* End of generated inner loops */
}
#else
#define ATL_INT int
#include <stdio.h>
#include <stdint.h>
#include <pmmintrin.h>

#define I_UNROLL 1
#define J_UNROLL 1
/* Is prefetched data written or just read? */
#define PF_READONLY 0
#define PF_READWRITE 1
#define PF_NO_REUSE 0

/* Default temporality of cache prefetch (1-3) */
#define PF_DEF 1
#define CACHE_LINE_SIZE 64
#define MMCAST( a ) (a)
#define MMCASTStore( a ) (a)
#define MMCASTStoreintrin( a ) (a)
#define TYPE float
void ATL_USERMM( const ATL_INT M, const ATL_INT N, const ATL_INT K,
                 const TYPE alpha, const TYPE *A, const ATL_INT lda,
                 const TYPE *B, const ATL_INT ldb,
                 const TYPE beta, TYPE *C, const ATL_INT ldc )
{
   register ATL_INT i, j, k;
   
   /* Vector registers to hold the elements of C */
   __m128 c0_0;
   /* Vector register to hold C*beta */
   __m128 bc0_0;
   /* Temporary vector registers for use in inner loop */
   __m128 temp; 
   /* Pointer adjustments */  
   register const ATL_INT ldc_bytes = ldc;
   
   register TYPE const *B0_off = B;
      
   
   /* Unroll A */
   __m128 A0, a0;
   /* Unroll B */
   __m128 B0, B1;
   

   register const ATL_INT unroll_a = I_UNROLL*KB;
   register TYPE* cPtr = C;
   

   /* =======================================
    * Begin generated inner loops for case Non aligned
    * ======================================= */
   for( j=-48; j!=0; j+=J_UNROLL) 
   {
      register TYPE const *A0_off = A; 
      
      register TYPE *cPtrI0 = cPtr;
      

      for( i=-48; i != 0; i+= I_UNROLL )
      {
         /* K_Unrolling0 */
         A0 = _mm_load_ps( MMCAST(A0_off) );
         B0 = _mm_load_ps( MMCAST(B0_off) );
         c0_0 = B0;
         c0_0 = _mm_mul_ps( A0, c0_0 );
         
         for( k=4; k<48; k+=4 )
         {
            /* k_partialUnrolling: 0 */
            B0 = _mm_load_ps( MMCAST( B0_off + k ) );
            A0 = _mm_load_ps( MMCAST(A0_off + k));
            temp = _mm_mul_ps( B0, A0 );
            c0_0 = _mm_add_ps( temp, c0_0 );
         }
         /* Single Scalar Compression */
         /* additional remaining step */
         c0_0 = _mm_hadd_ps( c0_0, c0_0 );
         c0_0 = _mm_hadd_ps( c0_0, c0_0 );
         /* Applying Beta */
            /* Apply Beta Factor */
            /* Load C from memory */
            /* 1 remaining */
            bc0_0 = _mm_load_ss( cPtrI0+0 );
            /* C = (beta*C) + (matrix multiply) */
            c0_0 = _mm_add_ss( bc0_0, c0_0 );
         /* Move pointers to next iteration */  
         A0_off += unroll_a;
         
         /* Store results back to memory  */
         _mm_store_ss( cPtrI0,  c0_0 );
         cPtrI0 += I_UNROLL;
         

      } /* End i/MB loop */

      B0_off += J_UNROLL*KB;
      cPtr += J_UNROLL*ldc_bytes;
   } /* End j/NB loop */
   /* End of generated inner loops */
}
#endif
