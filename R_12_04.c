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
 * R.12.4
 *
 * Evaluation of constant expressions should not lead to unsigned integer wrap-around
 *
 * NOTE: This example assumes a 32-bit int
 */

#include "mc3_types.h"
#include "mc3_header.h"

#define BASE         4294966784u

#define DELAY        1000000000u
#define WIDTH        4000000000u

static void fixed_pulse ( void )
{
   uint32_t off_time32 = DELAY + WIDTH;    /* Non-compliant  */
   use_uint32 ( off_time32 );
}


static void f4 ( void )
{   const uint32_t c = 0xffffffffu;
    uint32_t y = c + 1u;                 /* Compliant   */

    use_uint32 ( y );
}


static void g4 ( void )
{
   bool_t   b = get_bool ( );
   uint32_t x = ( 0u == 0u ) ? 0u : ( 0u - 1u );   /* Compliant, but breaks R.14.3 */
   uint32_t y = b ? 0u : ( 0u - 1u );              /* Non-compliant                */

   use_uint32 ( x );
   use_uint32 ( y );
}


static void h4 ( void )
{
   use_int32 ( 1 );
}

void R_12_4 ( void )
{
   uint32_t x = get_uint32 ( );

   switch ( x )
   {
      case BASE + 0u:
         f4 ( );
         break;
      case BASE + 1u:
         g4 ( );
         break;
      case BASE + 512u: /* Non-compliant - wraps around to 0       */
         h4 ( );
         break;
      default:
         /* no action */
         break;
   }

#if  1u + ( 0u - 10u )    /* Non-compliant - ( 0u - 10u ) wraps, also breaks R.20.8  */
   use_uint32 ( x );
#endif

   fixed_pulse ( );
}

/* end of R_12_04.c */
