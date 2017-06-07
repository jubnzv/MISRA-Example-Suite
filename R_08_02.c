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
 * R.8.2
 *
 * Function types shall be in prototype form with named parameters
 */

/* Note: Extern only used in 1 file breaks R.8.7 */

#include "mc3_types.h"
#include "mc3_header.h"


extern int16_t func1 ( int16_t n );   /* Compliant */
extern void func2 ( int16_t );        /* Non-compliant - parameter name not specified */

static int16_t func3 ( );             /* Non-compliant - no prototype */
extern int16_t func4 ( void );        /* Compliant */


int16_t func1 ( int16_t n )           /* Compliant */
{
  return n;
}


static int16_t func3 ( vec, n )       /* Non-compliant - old style identifier and declaration list -
                                         Also violates Rule 8.13 */
int16_t *vec;
int16_t  n;
{
   return vec[ n - 1 ];
}



typedef int16_t ( *pf2_t )( int16_t );   /* Non-compliant - parameter name not specified */
typedef int16_t ( *pf3_t )( int16_t n ); /* Compliant */

static int16_t get_pf ( int16_t n )
{
   return n;
}


void R_8_2 ( void )
{
   int16_t ( *pf0 ) ( );                    /* Non-compliant - no prototype */
   int16_t ( *pf0v ) ( void );              /* Compliant - prototype specifies 0 parameters */

   pf2_t p_fn2 = &get_pf;
   pf3_t p_fn3 = &get_pf;

   int16_t n1 = p_fn2 ( 2 );
   int16_t n2 = p_fn3 ( 2 );
   int16_t arr[ 3 ] = { 0 };

   pf0 = &get_int16;
   pf0v = &get_int16;
   use_int16 ( pf0 ( ) + pf0v ( ) );

   ( void ) func1 ( n1 );
   func2 ( n1 );
   ( void ) func3 ( arr, n2 );
   ( void ) func4 ( );
}

/* end of R_08_02.c */
