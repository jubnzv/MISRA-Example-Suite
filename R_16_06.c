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
 * R.16.6
 *
 * Every switch statement shall have at least two switch-clauses
 */

#include "mc3_types.h"
#include "mc3_header.h"

void R_16_6 ( void )
{
   int16_t x = get_int16 ( );
   int16_t y = get_int16 ( );
   int16_t z = get_int16 ( );

   switch ( x )
   {
      default:        /* Non-compliant */
         x = x + 1;
         break;
   }


   switch ( y )
   {
      case 1:
      default:        /* Non-compliant */
         y = y + 1;
         break;
   }


   switch ( z )
   {
      case 1 :
         z = 2;
         break;
      default :       /* Compliant */
         z = 0;
         break;
   }

   use_int16 ( x + y + z);
}

/* end of R_16_06.c */
