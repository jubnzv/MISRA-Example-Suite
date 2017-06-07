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
 * R.8.3
 *
 * All declarations of an object or function shall use the same names and type
 * qualifiers
 */

#include "R_08_03.h"

/* Note: All uses of basic types    break D.4.6,
 *       Duplicate declarations     breaks R.8.5
 *       Extern only used in 1 file breaks R.8.7
 */

extern void f3 ( signed int x );
       void f3 (        int x );      /* Compliant - Exception:  */


extern void g3 ( const  int * p1 );
       void g3 (        int * p1 );   /* Non-compliant - type qualifiers do not match
                                         Constraint Error - Also violates Rule 1.1 */


extern int16_t func ( int16_t num, int16_t den );
       int16_t func ( int16_t den, int16_t num )   /* Non-compliant - parameter names do not match */
{
  return num / den;
}

extern area_t area ( width_t w, height_t h );
       area_t area ( width_t w, width_t h )  /* Non-compliant - typedef names do not match */
{
   return ( area_t ) w * h;
}


static void fn1 ( bool_t b )
{
   void ( *fp1 ) ( int16_t z ) = b ? f1 : f2;

   fp1 ( 3 );
}

void f3 ( int x )
{
   use_int32 ( x );
}

void g3 ( int * p1 )  /* also breaks R.8.13 */
{
   use_int32 ( *p1 );
}


void R_8_3 ( void )
{
    bool_t bl = get_bool ( );
    int32_t lc = 5;

    (void) func ( 3, 5 );
    (void) area ( 4U, 5U );

    f3 ( 3 );
    g3 ( &lc );

    fn1 ( bl );
}

/* end of R_08_03.c */
