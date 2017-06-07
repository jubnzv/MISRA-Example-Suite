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
 * R.17.6
 *
 * The declaration of an array parameter shall not contain the static keyword 
 * between the [ ]
 */

#include "mc3_types.h"
#include "mc3_header.h"

static uint16_t total ( uint16_t n,
                        const uint16_t a [ static 20 ] /* Non-compliant */ )
{
   uint16_t i;
   uint16_t sum = 0U;

   /* Undefined behaviour if a has fewer than 20 elements */
   for ( i = 0U; i < n; ++i )
   {
      sum = sum + a [ i ];
   }

   return sum;
}


void R_17_6 ( void )
{
   uint16_t x;
   uint16_t v1 [ 10 ] = { 0U };
   uint16_t v2 [ 20 ] = { 0U };

   x = total ( 10U, v1 ); /* Undefined: v1 has 10 elements but needs at least 20 */
                          /* Also breaks R.17.5                                  */
   use_uint16 ( x );

   x = total ( 20U, v2 ); /* Defined but non-compliant */

   use_uint16( x + v1[0] + v2[0] );

}

/* end of R_17_06.c */
