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
 * R.18.4
 *
 * The +, -, += and -= operators should not be applied to an expression of
 * pointer type
 */

#include "mc3_types.h"
#include "mc3_header.h"

static void fn1 ( void )
{
   uint8_t a[ 10 ];
   uint8_t * ptr;
   uint8_t index = 0U;

   index = index + 1U; /* Compliant - rule only applies to pointers */

   a[ index ] = 0U;    /* Compliant */
   ptr = &a[ 5 ];      /* Compliant */
   use_uint8_ptr ( ptr );

   ptr = a;
   ptr++;              /* Compliant - increment operator not + */
   *( ptr + 5 ) = 0U;  /* Non-compliant */
   ptr[ 5 ] = 0U;      /* Compliant */

   use_uint8_ptr ( ptr );
}


static void fn2 ( void )
{
   uint8_t array_2_2[ 2 ] [ 2 ] = { { 1U, 2U }, { 4U, 5U } };
   uint8_t i;
   uint8_t j;
   uint8_t sum = 0U;

   for ( i = 0U; i < 2U; i++ )
   {
      uint8_t *row = array_2_2[ i ];

      for ( j = 0U; j < 2U; j++ )
      {
         sum += row[ j ]; /* Compliant  */

      }
   }

  use_uint8 ( sum );
}


static void fn3 ( uint8_t *p1, uint8_t p2[ ] )
{
   /* Note: Altering p1 and p2 also breaks R.17.8 and may violate R.18.1 depending on values */
   p1++;              /* Compliant     */
   p1 = p1 + 5;       /* Non-compliant */
   p1[ 5 ] = 0U;      /* Compliant     */

   p2++;              /* Compliant     */
   p2--;              /* Compliant     */
   ++p2;              /* Compliant     */
   --p2;              /* Compliant     */
   p2 = p2 + 3;       /* Non-compliant */
   p2[ 3 ] = 0U;      /* Compliant     */
}



void R_18_4 ( void )
{
   uint8_t a1[ 16 ] = { 0U };
   uint8_t a2[ 16 ] = { 0U };
   uint8_t data = 0U;

   fn1 ( );
   fn2 ( );
   fn3 ( a1, a2 );
   fn3 ( & data, &a2[ 4] );

   use_uint8 ( a1[ 0 ] + a2[ 0 ] + data );
}



/* end of R_18_04.c */
