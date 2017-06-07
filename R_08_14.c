/*
 * Release: 2016-01-01
 *
 * Example from MISRA C:2012 ( THIS IS NOT A TEST SUITE )
 *
 * Copyright HORIBA MIRA Limited.
 *
 * See file READ_ME.txt for full copyright, license and release instructions.
 */

/*
 * R.8.14
 *
 * The restrict type qualifier shall not be used
 */

#include "mc3_types.h"
#include "mc3_header.h"



static void user_copy (void * restrict p,       /* Non-compliant */
                       const void * restrict q,  /* Non-compliant */
                       int16_t n)
{
   p = ( void * )q;    /* breaks R.11.8, R.17.8 */
   use_void_ptr ( p );
   use_int16 ( n );
}

void R_8_14 ( void )
{
   int16_t arr1[ 3 ];
   int16_t arr2[ 3 ] = { 0, 1, 2 };
   user_copy ( arr1, arr2, 3 );

}

/* end of R_08_14.c */
