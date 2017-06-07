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
 * R.17.3
 *
 * A function shall not be declared implicitly
 */

#include "mc3_types.h"
#include "mc3_header.h"

/* extern float64_t power (float64_t d, int32_t n);
 *  not visible at use
 */



void R_17_3 ( void )
{
   float64_t sq1 = power ( 1, 2.0 );    /* Non-compliant  */

   use_float64 ( sq1 );
}

/* end of R_17_03.c */
