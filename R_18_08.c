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
 * R.18.8
 *
 * Variable-length array types shall not be used
 */

#include "mc3_types.h"
#include "mc3_header.h"


static void f8 ( int16_t n )
{
   uint16_t vla[ n ]; /* Non-compliant - Undefined if n is negative or zero */

   vla[ 0 ] = 1u;
   use_uint16 ( vla[ 0 ] );
}

static void g8 ( void )
{
   f8 ( 0 );  /* Undefined */
   f8 ( -1 ); /* Undefined */
   f8 ( 10 ); /* Defined */
}


static void h8 ( uint16_t n,
                uint16_t a [ 10 ][ n ] )  /* Non-compliant */
{
   uint16_t ( *p )[ 20 ];

   /* Undefined unless n == 20: incompatible types otherwise */
   p = a;

   use_uint16 ( p[ 9 ][ 0 ] );
}


void R_18_8 ( void )

{
   uint16_t n = 5;

   typedef uint16_t Vector[ n ]; /* Non-compliant - has 5 elements */

   n = 7;

   Vector   a1;                  /*  has 5 elements */

   uint16_t a2[ n ];             /* Non-compliant  -  has 7 elements */


   uint16_t arr[ 10 ][ 10 ] = { 0u };
   h8 ( 20u, arr );

   a1[ 0 ] = get_uint16 ( );
   a2[ 0 ] = get_uint16 ( );
   use_uint16 ( a1[ 0 ] );
   use_uint16 ( a2[ 0 ] );

   g8 ( );
}

/* end of R_18_08.c */
