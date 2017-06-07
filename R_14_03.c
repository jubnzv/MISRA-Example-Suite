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
 * R.14.3
 *
 * Controlling expressions shall not be invariant
 */


#include "mc3_types.h"
#include "mc3_header.h"


static void f3 ( void )
{
   uint16_t n = 100U; /* Differs from Example in document as given specific value */
   uint16_t sum;
   sum = 0;

   for ( uint16_t i = ( n - 6u ); i < n; ++i )
   {
      sum += i;
   }

   if ( ( sum % 2u ) == 0u )
   {
   /*
   * Non-compliant - sum is the sum of 6 consecutive non-negative
   * integer so must be an odd number. The controlling expression
   * of the if statement will always be false.
   */
      use_uint16 ( sum );
   }
}

static void g3 ( void )
{
  const uint8_t numcyl = 4u;
  const volatile uint8_t numcyl_cal = 4u;

  if ( numcyl == 4u )      /* Non-compliant - always 4 */
  {
  }

  if ( numcyl_cal == 4u )  /* Compliant - volatile may change */
  {
  }

  use_uint8 ( numcyl + numcyl_cal );
}


void R_14_3 ( void )
{
   uint16_t  u16a = get_uint16 ( );
   int8_t    s8a;

   f3 ( );
   g3 ( );

   s8a = ( u16a < 0u  ) ? 0 : 1;       /* Non-compliant - u16a always >= 0 */
   use_int8 ( s8a );

   if ( u16a <= 0xffffu )              /* Non-compliant - always true */
   {
   }
   use_uint16 ( u16a );

   if ( 2 > 3 )                        /* Non-compliant - always false */
   {
   }

   s8a = get_int8 ( );
   if ( ( s8a < 10 ) && ( s8a > 20 ) ) /* Non-compliant - always false */
   {
   }

   if ( ( s8a < 10 ) || ( s8a > 5 ) )  /* Non-compliant - always true */
   {
   }

   while ( s8a > 10 )
   {
      if ( s8a > 5 )                   /* Non-compliant - s8a always > 5 as not volatile */
      {
      }
      break;
   }

   do
   {
   } while ( 0u == 1u );               /* Compliant by exception */


   for ( s8a = 0; s8a < 130; ++s8a )   /* Non-compliant - always true, also breaks R.2.1 */
   {
   }


   while ( true )                      /* Compliant by exception, but breaks R.2.1 */
   {
   }

}
/* end of R_14_03.c */

