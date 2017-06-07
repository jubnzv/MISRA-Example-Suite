/*
 * Release: 2016-01-01
 *
 * Example from MISRA C:2012  (  THIS IS NOT A TEST SUITE )
 *
 * Copyright HORIBA MIRA Limited.
 *
 * See file READ_ME.txt for full copyright, license and release instructions.
 */

/*
 * R.7.3
 *
 * The lowercase character 'l' shall not be used in a literal suffix
 */

#include "mc3_types.h"
#include "mc3_header.h"

void R_7_3 ( void )
{
   const int64_t a = 0L;
   const int64_t b = 0l;        /* Non-compliant */
   const uint64_t c = 0Lu;
   const uint64_t d = 0lU;      /* Non-compliant */
   const uint128_t e = 0ULL;
   const uint128_t f = 0Ull;     /* Non-compliant */
   const int128_t g = 0LL;
   const int128_t h = 0ll;      /* Non-compliant */
   const float128_t m = 1.2L;
   const float128_t n = 2.4l;   /* Non-compliant */

   use_int64 ( a );
   use_int64 ( b );
   use_uint64 ( c );
   use_uint64 ( d );
   use_uint128 ( e );
   use_uint128 ( f );
   use_int128 ( g );
   use_int128 ( h );
   use_float128 ( m );
   use_float128 ( n );

}

/* end of R_07_03.c */
