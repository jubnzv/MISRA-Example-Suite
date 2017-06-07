/*
 * Release: 2016-11-01
 *
 * Example from MISRA C:2012 ( THIS IS NOT A TEST SUITE )
 *
 * Copyright HORIBA MIRA Limited.
 *
 * See file READ_ME.txt for full copyright, license and release instructions.
 */

/*
 * R.12.3
 *
 * The comma operator should not be used
 */

#include "mc3_types.h"
#include "mc3_header.h"

static void f3 ( int16_t arg1, int16_t arg2 )
{
   use_int16 ( arg1 + arg2 );
}

#define N 10

void R_12_3 ( void )
{
   f3 ( ( 1, 2 ), 3 ); /* Non-compliant - Also breaks R.2.2  */

   int16_t i;
   int16_t a[ N ] = { 0 };
   int16_t *p;

   /* also violates R.14.2 */
   for ( i = 0, p = &a[ 0 ];  /* Non-compliant */
         i < N;
         ++i, ++p )           /* Non-compliant */
   {
   }
}

/* end of R_12_03.c */
