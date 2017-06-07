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
 * R.16.2
 *
 * A switch label shall only be used when the most closely-enclosing compound 
 * statement is the body of a switch statement
 */

#include "mc3_types.h"
#include "mc3_header.h"

void R_16_2 ( void )
{
   int16_t x = get_int16 ( );
   bool_t flag = get_bool ( );

   switch ( x )
   {
      case 1:
         if ( flag )
         {
      case 2:           /* Non-compliant */
            x = 1;
         }
         break;
      default:
         /* no action */
         break;
    }

   use_int16 ( x );
}

/* end of R_16_02.c */
