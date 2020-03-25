#ifndef ATL_RESTRICT
#if defined(__STDC_VERSION__) && (__STDC_VERSION__/100 >= 1999)
   #define ATL_RESTRICT restrict
#else
   #define ATL_RESTRICT
#endif
#endif
#include "atlas_prefetch.h"

#ifndef ATL_RESTRICT
#if defined(__STDC_VERSION__) && (__STDC_VERSION__/100 >= 1999)
   #define ATL_RESTRICT restrict
#else
   #define ATL_RESTRICT
#endif
#endif
#include "atlas_prefetch.h"

static void ATL_zJIK0x0x12TN1x1x12_a1_bX
   (const int M, const int N, const int K, const double alpha, const double * ATL_RESTRICT A, const int lda, const double * ATL_RESTRICT B, const int ldb, const double beta, double * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=0, NB=0, KB=12, 
 * lda=12, ldb=12, ldc=0, mu=1, nu=1, ku=12, pf=1
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.2)
 */
{
   #define Mb M
   #define Nb N
   const double *stM = A + (((Mb) << 3)+((Mb) << 2));
   const double *stN = B + (((Nb) << 3)+((Nb) << 2));
   const double *pfA = stM;
   const int incPFA0 = (((int)(stM - A))*1*1)/(M*N*sizeof(double));
   const int incPFA = (1 > incPFA0) ? 1 : incPFA0;
   #define incAk 12
   const int incAm = 0, incAn = -(((Mb) << 3)+((Mb) << 2));
   #define incBk 12
   const int incBm = -12, incBn = 12;
   const int incAk0 = ((incAk) / 12), incBk0 = ((incBk) / 12);
   #define incCm 2
   const int incCn = (((ldc) << 1)) - (((Mb) << 1));
   double *pC0=C;
   const double *pA0=A;
   const double *pB0=B;
   register int k;
   register double rA0;
   register double rB0;
   register double m0, m1, m2, m3, m4, m5;
   register double rC0_0;
   do /* N-loop */
   {
      do /* M-loop */
      {
         ATL_pfl1R(pfA);
         pfA += incPFA;
         rA0 = beta;
         rC0_0 = *pC0;
         rC0_0 *= rA0;
/*
 *       Start pipeline
 */
         rA0 = *pA0;
         rB0 = *pB0;
         m0 = rA0 * rB0;
         rA0 = pA0[1];
         rB0 = pB0[1];
         m1 = rA0 * rB0;
         rA0 = pA0[2];
         rB0 = pB0[2];
         m2 = rA0 * rB0;
         rA0 = pA0[3];
         rB0 = pB0[3];
         m3 = rA0 * rB0;
         rA0 = pA0[4];
         rB0 = pB0[4];
         m4 = rA0 * rB0;
         rA0 = pA0[5];
         rB0 = pB0[5];
         m5 = rA0 * rB0;
         rA0 = pA0[6];
         rB0 = pB0[6];

/*
 *       Completely unrolled K-loop
 */
         rC0_0 += m0;
         m0 = rA0 * rB0;
         rA0 = pA0[7];
         rB0 = pB0[7];
         rC0_0 += m1;
         m1 = rA0 * rB0;
         rA0 = pA0[8];
         rB0 = pB0[8];
         rC0_0 += m2;
         m2 = rA0 * rB0;
         rA0 = pA0[9];
         rB0 = pB0[9];
         rC0_0 += m3;
         m3 = rA0 * rB0;
         rA0 = pA0[10];
         rB0 = pB0[10];
         rC0_0 += m4;
         m4 = rA0 * rB0;
         rA0 = pA0[11];
         rB0 = pB0[11];
/*
 *       Drain pipe on last iteration of K-loop
 */
         rC0_0 += m5;
         m5 = rA0 * rB0;
         rC0_0 += m0;
         rC0_0 += m1;
         rC0_0 += m2;
         rC0_0 += m3;
         rC0_0 += m4;
         rC0_0 += m5;
         pA0 += incAk;
         pB0 += incBk;
         *pC0 = rC0_0;
         pC0 += incCm;
         pA0 += incAm;
         pB0 += incBm;
      }
      while(pA0 != stM);
      pC0 += incCn;
      pA0 += incAn;
      pB0 += incBn;
   }
   while(pB0 != stN);
}
#ifdef incAm
   #undef incAm
#endif
#ifdef incAn
   #undef incAn
#endif
#ifdef incAk
   #undef incAk
#endif
#ifdef incBm
   #undef incBm
#endif
#ifdef incBn
   #undef incBn
#endif
#ifdef incBk
   #undef incBk
#endif
#ifdef incCm
   #undef incCm
#endif
#ifdef incCn
   #undef incCn
#endif
#ifdef incCk
   #undef incCk
#endif
#ifdef Mb
   #undef Mb
#endif
#ifdef Nb
   #undef Nb
#endif
#ifdef Kb
   #undef Kb
#endif
void ATL_zJIK0x0x12TN12x12x0_a1_bX
   (const int M, const int N, const int K, const double alpha, const double * ATL_RESTRICT A, const int lda, const double * ATL_RESTRICT B, const int ldb, const double beta, double * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=0, NB=0, KB=12, 
 * lda=12, ldb=12, ldc=0, mu=10, nu=1, ku=12, pf=1
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.2)
 */
{
   const int Mb = (M/10)*10;
   #define Nb N
   const double *ca=A, *cb=B;
   double *cc=C;
   const double *stM = A + (((Mb) << 3)+((Mb) << 2));
   const double *stN = B + (((Nb) << 3)+((Nb) << 2));
   const double *pfA = stM;
   const int incPFA0 = (((int)(stM - A))*10*1)/(M*N*sizeof(double));
   const int incPFA = (1 > incPFA0) ? 1 : incPFA0;
   #define incAk 12
   const int incAm = 108, incAn = -(((Mb) << 3)+((Mb) << 2));
   #define incBk 12
   const int incBm = -12, incBn = 12;
   const int incAk0 = ((incAk) / 12), incBk0 = ((incBk) / 12);
   #define incCm 20
   const int incCn = (((ldc) << 1)) - (((Mb) << 1));
   double *pC0=C;
   const double *pA0=A;
   const double *pB0=B;
   register int k;
   register double rA0, rA1, rA2, rA3, rA4, rA5, rA6, rA7, rA8, rA9;
   register double rB0;
   register double m0, m1, m2, m3, m4;
   register double rC0_0, rC1_0, rC2_0, rC3_0, rC4_0, rC5_0, rC6_0, rC7_0, rC8_0, rC9_0;
   if (pA0 != stM)
   {
      do /* N-loop */
      {
         do /* M-loop */
         {
            ATL_pfl1R(pfA);
            pfA += incPFA;
            rA0 = beta;
            rC0_0 = *pC0;
            rC0_0 *= rA0;
            rC1_0 = pC0[2];
            rC1_0 *= rA0;
            rC2_0 = pC0[4];
            rC2_0 *= rA0;
            rC3_0 = pC0[6];
            rC3_0 *= rA0;
            rC4_0 = pC0[8];
            rC4_0 *= rA0;
            rC5_0 = pC0[10];
            rC5_0 *= rA0;
            rC6_0 = pC0[12];
            rC6_0 *= rA0;
            rC7_0 = pC0[14];
            rC7_0 *= rA0;
            rC8_0 = pC0[16];
            rC8_0 *= rA0;
            rC9_0 = pC0[18];
            rC9_0 *= rA0;
/*
 *          Start pipeline
 */
            rA0 = *pA0;
            rB0 = *pB0;
            m0 = rA0 * rB0;
            rA1 = pA0[12];
            rA2 = pA0[24];
            m1 = rA1 * rB0;
            rA3 = pA0[36];
            rA4 = pA0[48];
            m2 = rA2 * rB0;
            rA5 = pA0[60];
            rA6 = pA0[72];
            m3 = rA3 * rB0;
            rA7 = pA0[84];
            rA8 = pA0[96];
            m4 = rA4 * rB0;
            rA9 = pA0[108];

/*
 *          Completely unrolled K-loop
 */
            rC0_0 += m0;
            m0 = rA5 * rB0;
            rC1_0 += m1;
            m1 = rA6 * rB0;
            rC2_0 += m2;
            m2 = rA7 * rB0;
            rC3_0 += m3;
            m3 = rA8 * rB0;
            rC4_0 += m4;
            m4 = rA9 * rB0;
            rA0 = pA0[1];
            rB0 = pB0[1];
            rA1 = pA0[13];
            rA2 = pA0[25];
            rC5_0 += m0;
            m0 = rA0 * rB0;
            rA3 = pA0[37];
            rA4 = pA0[49];
            rC6_0 += m1;
            m1 = rA1 * rB0;
            rA5 = pA0[61];
            rA6 = pA0[73];
            rC7_0 += m2;
            m2 = rA2 * rB0;
            rA7 = pA0[85];
            rA8 = pA0[97];
            rC8_0 += m3;
            m3 = rA3 * rB0;
            rA9 = pA0[109];
            rC9_0 += m4;
            m4 = rA4 * rB0;
            rC0_0 += m0;
            m0 = rA5 * rB0;
            rC1_0 += m1;
            m1 = rA6 * rB0;
            rC2_0 += m2;
            m2 = rA7 * rB0;
            rC3_0 += m3;
            m3 = rA8 * rB0;
            rC4_0 += m4;
            m4 = rA9 * rB0;
            rA0 = pA0[2];
            rB0 = pB0[2];
            rA1 = pA0[14];
            rA2 = pA0[26];
            rC5_0 += m0;
            m0 = rA0 * rB0;
            rA3 = pA0[38];
            rA4 = pA0[50];
            rC6_0 += m1;
            m1 = rA1 * rB0;
            rA5 = pA0[62];
            rA6 = pA0[74];
            rC7_0 += m2;
            m2 = rA2 * rB0;
            rA7 = pA0[86];
            rA8 = pA0[98];
            rC8_0 += m3;
            m3 = rA3 * rB0;
            rA9 = pA0[110];
            rC9_0 += m4;
            m4 = rA4 * rB0;
            rC0_0 += m0;
            m0 = rA5 * rB0;
            rC1_0 += m1;
            m1 = rA6 * rB0;
            rC2_0 += m2;
            m2 = rA7 * rB0;
            rC3_0 += m3;
            m3 = rA8 * rB0;
            rC4_0 += m4;
            m4 = rA9 * rB0;
            rA0 = pA0[3];
            rB0 = pB0[3];
            rA1 = pA0[15];
            rA2 = pA0[27];
            rC5_0 += m0;
            m0 = rA0 * rB0;
            rA3 = pA0[39];
            rA4 = pA0[51];
            rC6_0 += m1;
            m1 = rA1 * rB0;
            rA5 = pA0[63];
            rA6 = pA0[75];
            rC7_0 += m2;
            m2 = rA2 * rB0;
            rA7 = pA0[87];
            rA8 = pA0[99];
            rC8_0 += m3;
            m3 = rA3 * rB0;
            rA9 = pA0[111];
            rC9_0 += m4;
            m4 = rA4 * rB0;
            rC0_0 += m0;
            m0 = rA5 * rB0;
            rC1_0 += m1;
            m1 = rA6 * rB0;
            rC2_0 += m2;
            m2 = rA7 * rB0;
            rC3_0 += m3;
            m3 = rA8 * rB0;
            rC4_0 += m4;
            m4 = rA9 * rB0;
            rA0 = pA0[4];
            rB0 = pB0[4];
            rA1 = pA0[16];
            rA2 = pA0[28];
            rC5_0 += m0;
            m0 = rA0 * rB0;
            rA3 = pA0[40];
            rA4 = pA0[52];
            rC6_0 += m1;
            m1 = rA1 * rB0;
            rA5 = pA0[64];
            rA6 = pA0[76];
            rC7_0 += m2;
            m2 = rA2 * rB0;
            rA7 = pA0[88];
            rA8 = pA0[100];
            rC8_0 += m3;
            m3 = rA3 * rB0;
            rA9 = pA0[112];
            rC9_0 += m4;
            m4 = rA4 * rB0;
            rC0_0 += m0;
            m0 = rA5 * rB0;
            rC1_0 += m1;
            m1 = rA6 * rB0;
            rC2_0 += m2;
            m2 = rA7 * rB0;
            rC3_0 += m3;
            m3 = rA8 * rB0;
            rC4_0 += m4;
            m4 = rA9 * rB0;
            rA0 = pA0[5];
            rB0 = pB0[5];
            rA1 = pA0[17];
            rA2 = pA0[29];
            rC5_0 += m0;
            m0 = rA0 * rB0;
            rA3 = pA0[41];
            rA4 = pA0[53];
            rC6_0 += m1;
            m1 = rA1 * rB0;
            rA5 = pA0[65];
            rA6 = pA0[77];
            rC7_0 += m2;
            m2 = rA2 * rB0;
            rA7 = pA0[89];
            rA8 = pA0[101];
            rC8_0 += m3;
            m3 = rA3 * rB0;
            rA9 = pA0[113];
            rC9_0 += m4;
            m4 = rA4 * rB0;
            rC0_0 += m0;
            m0 = rA5 * rB0;
            rC1_0 += m1;
            m1 = rA6 * rB0;
            rC2_0 += m2;
            m2 = rA7 * rB0;
            rC3_0 += m3;
            m3 = rA8 * rB0;
            rC4_0 += m4;
            m4 = rA9 * rB0;
            rA0 = pA0[6];
            rB0 = pB0[6];
            rA1 = pA0[18];
            rA2 = pA0[30];
            rC5_0 += m0;
            m0 = rA0 * rB0;
            rA3 = pA0[42];
            rA4 = pA0[54];
            rC6_0 += m1;
            m1 = rA1 * rB0;
            rA5 = pA0[66];
            rA6 = pA0[78];
            rC7_0 += m2;
            m2 = rA2 * rB0;
            rA7 = pA0[90];
            rA8 = pA0[102];
            rC8_0 += m3;
            m3 = rA3 * rB0;
            rA9 = pA0[114];
            rC9_0 += m4;
            m4 = rA4 * rB0;
            rC0_0 += m0;
            m0 = rA5 * rB0;
            rC1_0 += m1;
            m1 = rA6 * rB0;
            rC2_0 += m2;
            m2 = rA7 * rB0;
            rC3_0 += m3;
            m3 = rA8 * rB0;
            rC4_0 += m4;
            m4 = rA9 * rB0;
            rA0 = pA0[7];
            rB0 = pB0[7];
            rA1 = pA0[19];
            rA2 = pA0[31];
            rC5_0 += m0;
            m0 = rA0 * rB0;
            rA3 = pA0[43];
            rA4 = pA0[55];
            rC6_0 += m1;
            m1 = rA1 * rB0;
            rA5 = pA0[67];
            rA6 = pA0[79];
            rC7_0 += m2;
            m2 = rA2 * rB0;
            rA7 = pA0[91];
            rA8 = pA0[103];
            rC8_0 += m3;
            m3 = rA3 * rB0;
            rA9 = pA0[115];
            rC9_0 += m4;
            m4 = rA4 * rB0;
            rC0_0 += m0;
            m0 = rA5 * rB0;
            rC1_0 += m1;
            m1 = rA6 * rB0;
            rC2_0 += m2;
            m2 = rA7 * rB0;
            rC3_0 += m3;
            m3 = rA8 * rB0;
            rC4_0 += m4;
            m4 = rA9 * rB0;
            rA0 = pA0[8];
            rB0 = pB0[8];
            rA1 = pA0[20];
            rA2 = pA0[32];
            rC5_0 += m0;
            m0 = rA0 * rB0;
            rA3 = pA0[44];
            rA4 = pA0[56];
            rC6_0 += m1;
            m1 = rA1 * rB0;
            rA5 = pA0[68];
            rA6 = pA0[80];
            rC7_0 += m2;
            m2 = rA2 * rB0;
            rA7 = pA0[92];
            rA8 = pA0[104];
            rC8_0 += m3;
            m3 = rA3 * rB0;
            rA9 = pA0[116];
            rC9_0 += m4;
            m4 = rA4 * rB0;
            rC0_0 += m0;
            m0 = rA5 * rB0;
            rC1_0 += m1;
            m1 = rA6 * rB0;
            rC2_0 += m2;
            m2 = rA7 * rB0;
            rC3_0 += m3;
            m3 = rA8 * rB0;
            rC4_0 += m4;
            m4 = rA9 * rB0;
            rA0 = pA0[9];
            rB0 = pB0[9];
            rA1 = pA0[21];
            rA2 = pA0[33];
            rC5_0 += m0;
            m0 = rA0 * rB0;
            rA3 = pA0[45];
            rA4 = pA0[57];
            rC6_0 += m1;
            m1 = rA1 * rB0;
            rA5 = pA0[69];
            rA6 = pA0[81];
            rC7_0 += m2;
            m2 = rA2 * rB0;
            rA7 = pA0[93];
            rA8 = pA0[105];
            rC8_0 += m3;
            m3 = rA3 * rB0;
            rA9 = pA0[117];
            rC9_0 += m4;
            m4 = rA4 * rB0;
            rC0_0 += m0;
            m0 = rA5 * rB0;
            rC1_0 += m1;
            m1 = rA6 * rB0;
            rC2_0 += m2;
            m2 = rA7 * rB0;
            rC3_0 += m3;
            m3 = rA8 * rB0;
            rC4_0 += m4;
            m4 = rA9 * rB0;
            rA0 = pA0[10];
            rB0 = pB0[10];
            rA1 = pA0[22];
            rA2 = pA0[34];
            rC5_0 += m0;
            m0 = rA0 * rB0;
            rA3 = pA0[46];
            rA4 = pA0[58];
            rC6_0 += m1;
            m1 = rA1 * rB0;
            rA5 = pA0[70];
            rA6 = pA0[82];
            rC7_0 += m2;
            m2 = rA2 * rB0;
            rA7 = pA0[94];
            rA8 = pA0[106];
            rC8_0 += m3;
            m3 = rA3 * rB0;
            rA9 = pA0[118];
            rC9_0 += m4;
            m4 = rA4 * rB0;
            rC0_0 += m0;
            m0 = rA5 * rB0;
            rC1_0 += m1;
            m1 = rA6 * rB0;
            rC2_0 += m2;
            m2 = rA7 * rB0;
            rC3_0 += m3;
            m3 = rA8 * rB0;
            rC4_0 += m4;
            m4 = rA9 * rB0;
            rA0 = pA0[11];
            rB0 = pB0[11];
            rA1 = pA0[23];
            rA2 = pA0[35];
            rC5_0 += m0;
            m0 = rA0 * rB0;
            rA3 = pA0[47];
            rA4 = pA0[59];
            rC6_0 += m1;
            m1 = rA1 * rB0;
            rA5 = pA0[71];
            rA6 = pA0[83];
            rC7_0 += m2;
            m2 = rA2 * rB0;
            rA7 = pA0[95];
            rA8 = pA0[107];
            rC8_0 += m3;
            m3 = rA3 * rB0;
            rA9 = pA0[119];
            rC9_0 += m4;
            m4 = rA4 * rB0;
/*
 *          Drain pipe on last iteration of K-loop
 */
            rC0_0 += m0;
            m0 = rA5 * rB0;
            rC1_0 += m1;
            m1 = rA6 * rB0;
            rC2_0 += m2;
            m2 = rA7 * rB0;
            rC3_0 += m3;
            m3 = rA8 * rB0;
            rC4_0 += m4;
            m4 = rA9 * rB0;
            rC5_0 += m0;
            rC6_0 += m1;
            rC7_0 += m2;
            rC8_0 += m3;
            rC9_0 += m4;
            pA0 += incAk;
            pB0 += incBk;
            *pC0 = rC0_0;
            pC0[2] = rC1_0;
            pC0[4] = rC2_0;
            pC0[6] = rC3_0;
            pC0[8] = rC4_0;
            pC0[10] = rC5_0;
            pC0[12] = rC6_0;
            pC0[14] = rC7_0;
            pC0[16] = rC8_0;
            pC0[18] = rC9_0;
            pC0 += incCm;
            pA0 += incAm;
            pB0 += incBm;
         }
         while(pA0 != stM);
         pC0 += incCn;
         pA0 += incAn;
         pB0 += incBn;
      }
      while(pB0 != stN);
   }
   if (k=M-Mb)
      ATL_zJIK0x0x12TN1x1x12_a1_bX(k, N, 12, alpha, ca + (((Mb) << 3)+((Mb) << 2)), lda, cb, ldb, beta, cc + (((Mb) << 1)), ldc);
}
#ifdef incAm
   #undef incAm
#endif
#ifdef incAn
   #undef incAn
#endif
#ifdef incAk
   #undef incAk
#endif
#ifdef incBm
   #undef incBm
#endif
#ifdef incBn
   #undef incBn
#endif
#ifdef incBk
   #undef incBk
#endif
#ifdef incCm
   #undef incCm
#endif
#ifdef incCn
   #undef incCn
#endif
#ifdef incCk
   #undef incCk
#endif
#ifdef Mb
   #undef Mb
#endif
#ifdef Nb
   #undef Nb
#endif
#ifdef Kb
   #undef Kb
#endif