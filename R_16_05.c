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
 * R.16.5
 *
 * A default label shall appear as either the first or the last switch label of
 * a switch statement
 */

#include "mc3_types.h"
#include "mc3_header.h"

void R_16_5 ( void )
{
    int16_t x = get_int16 ( );

    switch ( x )
    {
       default:     /* Compliant - default is the first label */
       case 0:
          ++x;
          break;
       case 1:
       case 2:
          break;
    }


    switch ( x )
    {
       case 0:
          ++x;
          break;
      default:      /* Non-compliant - default is mixed with the case labels */
          x = 0;
          break;
      case 1:
      case 2:
          break;
    }


    switch ( x )
    {
       case 0:
          ++x;
          break;
       case 1:
       case 2:
          break;
       default:     /* Compliant - default is the final label */
          x = 0;
          break;
    }

    use_int16 ( x );
}

/* end of R_16_05.c */
