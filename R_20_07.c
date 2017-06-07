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
 * R.20.7
 *
 * Expressions resulting from the expansion of macro parameters shall be 
 * enclosed in parentheses
 */

#include "mc3_types.h"
#include "mc3_header.h"

/* Note: Some of the #defines also break D.4.9 */

#define M1( x, y ) ( x * y )

#define M2( x, y ) ( ( x ) * ( y ) )

#define M3( x ) a ## x = ( x )         /* x without ( ) is not used as an expression, also breaks R.20.10 */

#define GET_MEMBER( S, M ) ( S ).M     /* M is a structure member name, not an expression */

#define F( X ) G( X )
#define G( Y ) ( ( Y ) + 1 )

void R_20_7 ( void )
{
   int8_t r;

   r = M1 ( 1 + 2, 3 + 4 );           /* Non-compliant - result is 11, also breaks R.12.1 */
   use_int8 ( r );
   r = M1 ( ( 1 + 2 ), ( 3 + 4 ) );   /* Compliant     - result is 21 */
   use_int8 ( r );

   r = M2 ( 1 + 2, 3 + 4 );           /* Compliant     - result is 21 */
   use_int8 ( r );

   int16_t M3 ( 0 );
   use_int16 ( a0 );

   int8_t v;
   struct { int8_t minval; } s1 = { 2 };
   v = GET_MEMBER ( s1, minval );
   use_int8 ( v );

   int16_t x = F ( 2 );
   use_int16 ( x );

}

/* end of R_20_07.c */
