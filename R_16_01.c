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
 * R.16.1
 *
 * All switch statements shall be well-formed
 */

#include "mc3_types.h"
#include "mc3_header.h"


void R_16_1 ( void )
{
    uint8_t zwitch = get_uint8 ( );
    uint8_t zwitched = get_uint8 ( );

    switch ( zwitch )
    {
       uint8_t decl;   /* Non-compliant */
       case 0U:
       {
          zwitched += 1U;
          decl = zwitched;
          use_uint8 ( decl );
          break;
       }
       case 1U:
       {
          uint8_t local = zwitched;
          use_uint8 ( local );
          break;
       }
       case 2U:
         use_uint8 ( zwitched );
         break;
       default:
       {
          break;
       }
    }

    use_uint8 ( zwitched );
}

/* end of R_16_01.c */
