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
 * R.21.12
 *
 * The exception handling features of <fenv.h> should not be used
 */

#include "mc3_types.h"
#include "mc3_header.h"
#include <fenv.h>

static void f ( float32_t x, float32_t y )
{
   float32_t z;

   ( void ) feclearexcept ( FE_DIVBYZERO );      /* Non-compliant */

   z = x / y;

   if ( fetestexcept ( FE_DIVBYZERO ) != 0 ) /* Non-compliant */
   {
   }
   else
   {
#pragma STDC FENV_ACCESS on
       z = x * y;
   }

   if ( z > x )
   {
#pragma STDC FENV_ACCESS off
      if ( fetestexcept ( FE_OVERFLOW ) != 0 ) /* Non-compliant */
      {
      }
   }

}

void R_21_12 ( void )
{
   float32_t x = get_float32 ( );
   float32_t y = get_float32 ( );

   f ( x, y );
}

/* end of R_21_12.c */

