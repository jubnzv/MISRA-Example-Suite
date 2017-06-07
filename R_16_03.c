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
 * R.16.3
 *
 * An unconditional break statement shall terminate every switch-clause
 */

#include "mc3_types.h"
#include "mc3_header.h"

void R_16_3 ( void )
{
   int16_t x = get_int16 ( );
   int16_t a = get_int16 ( );
   int16_t b = get_int16 ( );

   switch ( x )
   {
      case 0:
         break;                /* Compliant - unconditional break */
      case 1:
      case 2:                  /* Compliant - empty fall through */
         break;
      case 4:
         a = b;                /* Non-compliant - break omitted */
      case 5:
         if ( a == b )
         {
            ++a;
            break;             /* Non-compliant - conditional break  */

         }
      default:
         ;                    /* Non-compliant - default must also have a break  */
   }

   use_int16 ( a );
}

/* end of R_16_03.c */
