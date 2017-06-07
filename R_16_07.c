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
 * R.16.7
 *
 * A switch-expression shall not have essentially Boolean type
 */

#include "mc3_types.h"
#include "mc3_header.h"

void R_16_7 ( void )
{
   int16_t x = get_int16 ( );
   int16_t y;
   int16_t z = get_int16 ( );

    switch ( x == 0 )            /* Non-compliant */
    {
       case false:
          y = x;
          break;
       default:
          y = z;
          break;
    }

   use_int16 ( x + y + z );
}

/* end of R_16_07.c */
