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
 * R.12.1
 *
 * The precedence of operators within expressions should be made explicit
 */

#include "R_12_01.h"

#include <stddef.h>

typedef struct { uint16_t m; uint16_t n;} struct_smn;

#define XX 1
#define YY 2
#define ZZ 3

void R_12_1 ( void )
{
   uint16_t a = get_uint16 ( );
   uint16_t b = get_uint16 ( );
   uint16_t c = get_uint16 ( );
   uint16_t d = get_uint16 ( );
   uint16_t i = get_uint16 ( );
   uint16_t x;
   uint16_t y = get_uint16 ( );
   bool   bj = get_bool ( );
   bool   bk = get_bool ( );
   bool   bl = get_bool ( );
   uint16_t uarr[ 5 ] = { 0 };
   uint16_t *p = uarr;
   struct_smn smn_val = { 1U, 1U };
   struct_smn *arr[ 2 ] = { &smn_val, &smn_val };
   size_t sz;

   /* Operands are primary_expressions or top-level operator level 15 */
   if ( arr[ i ] != NULL )
   {
      arr[ i ]->n = 0U;     /* Compliant no need to write ( arr[ i ] )->n */
      use_uint16 ( arr [ i ]->n );
   }

   *p++;                    /* Compliant no need to write *(p++), but breaks R.2.2 */
   use_uint16_ptr ( p );

   sz = sizeof x + y;       /* Non-compliant - write sizeof (x)+y or sizeof (x+y) */
   use_sizet ( sz );

   /* Same precedence - all are compliant */
    x = a + b;
    use_uint16 ( x );
    x = a + b + c;
    use_uint16 ( x );
    x = (a + b) + c;
    use_uint16 ( x );
    x = a + (b + c);
    use_uint16 ( x );
    x = a + b - c + d;
    use_uint16 ( x );
    x = (a + b) - (c + d);
    use_uint16 ( x );

   /* Different precedence */
   x = f ( a + b, c ); /* Compliant - no need to write f ((a + b), c) */
   use_uint16 ( x );

   /* Operands of conditional operator (precedence 2) are:
   * == precedence 8 needs parentheses
   * a precedence 16 does not need parentheses
   * - precedence 11 needs parentheses
   */
   x = a == b ? a : a - b;          /* Non-compliant */
   use_uint16 ( x );
   x = ( a == b ) ? a : ( a - b );  /* Compliant */
   use_uint16 ( x );

   /* Operands of << operator (precedence 10) are:
   * a precedence 16 does not need parentheses
   * (E) precedence 16 already parenthesised
   */
   x = a << ( b + c );             /* Compliant */
   use_uint16 ( x );

   /* Operands of && operator (precedence 4) are:
   * a precedence 16 does not need parentheses
   * && precedence 4 does not need parentheses
   */
   if ( bj && bk && bl )          /* Compliant */
   {
   }
   use_bool ( bj );
   use_bool ( bk );
   use_bool ( bl );

   /* Operands of && operator (precedence 4) are:
   * defined(XX) precedence 14 does not need parentheses
   * (E) precedence 16 already parenthesised
   */
#if defined( XX ) && ( ( XX + YY ) > ZZ ) /* Compliant */
   use_bool ( bj );
#endif

   /* Compliant
    * Operands of && operator (precedence 4) are:
    *   !defined(XZ) precedence 14 does not need parentheses
    *    defined(YZ) precedence 14 does not need parentheses
    * Operand of ! operator (precedence 14) is:
    *    defined(XZ) precedence 14 does not need parentheses
    */
#if !defined( XZ ) && defined( YZ )    /* Compliant */
   use_bool ( bj );
#endif


   x = a, b;        /* Compliant - parsed as (x = a) , b - violates R.2.2 and R.12.3 */
   use_uint16 ( x );
   use_uint16 ( smn_val.m + smn_val.n );

}

/* end of R_12_01.c */
