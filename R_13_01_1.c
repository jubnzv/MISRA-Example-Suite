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
 * R.13.1
 *
 * Initialiser lists shall not contain persistent side-effects
 */

#include "R_13_01.h"

volatile uint16_t vol;

static void f1 ( void )
{
   /* Non-compliant - volatile access is persistent side effect */
   uint16_t a[ 2 ] = { vol, 0 };

   use_uint16 ( a[ 0 ]+ a[ 1 ] );
}

static void g1 ( uint16_t x, uint16_t y )
{
   /* Compliant - no side effects */
   uint16_t a[ 2 ] = { x + y, x - y };

   use_uint16 ( a[ 0 ]+ a[ 1 ] );
}


static void h1 ( void )
{
   uint16_t x = 0u;
   /* Non-compliant - two side effects - Also breaks R.13.3 */
   use_arr ( ( uint16_t[ 2 ] ) { x++, x++ } );

   use_uint16 ( x );
}


void R_13_1 ( void )
{
   R_13_1_2 ( );
   f1 ( );
   g1 ( 3u, 5u );
   h1 ( );
}

/* end of R_13_01_1.c */
