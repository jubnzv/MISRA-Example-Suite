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
 * R.17.4
 *
 * All exit paths from a function with non-void return type shall have an 
 * explicit return statement with an expression
 */

#include "mc3_types.h"
#include "mc3_header.h"

#define V_MIN 1U
#define V_MAX 4U


static int32_t absolute ( int32_t v )
{
   if ( v < 0 )
   {
     return v;
   }
   /* Non-compliant - control can reach this point without
    * returning a value, also breaks R.15.5
    */
}


static uint16_t lookup ( const uint16_t table[ 5 ], uint16_t v )
{
   if ( ( v < V_MIN ) || ( v > V_MAX ) )
   {
     /* Non-compliant - no value returned. Constraint in C99 */
     return;
   }
   return table[ v ];  /* Also breaks R.15.5 */
}


void R_17_4 ( void )
{
   const uint16_t tabs[ 5 ] = { 1U, 2U, 3U, 4U, 5U };
   uint16_t index = get_uint16 ( );

   uint16_t result = lookup ( tabs, index );
   use_uint16 ( result );

   ( void ) absolute ( 5 );
}

/* end of R_17_04.c */

