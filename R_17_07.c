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
 * R.17.7
 *
 * The value returned by a function having non-void return type shall be used
 */

#include "mc3_types.h"
#include "mc3_header.h"


static uint16_t func (  uint16_t para1 )
{
   return para1;
}


static void discarded ( uint16_t para2 )
{
    uint16_t x;

    func ( para2 );            /* Non Compliant - value discarded  */

    ( void ) func ( para2 );   /* Compliant  */

     x = func ( para2 );       /* Compliant  */

    use_uint16 ( x );
}


void R_17_7 ( void )
{
   discarded ( 3U );
}
/* end of R_17_07.c */
