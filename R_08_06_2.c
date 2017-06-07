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
 * R.8.6
 *
 * An identifier with external linkage shall have exactly one external
 * definition
 */

#include "R_08_06.h"

int16_t i = 10;   /* Non-compliant - two definitions */

int16_t k;        /*  Non-compliant - Tentative definition - becomes external,
                                     also breaks R.8.4     */


void R_8_6_2 ( void )
{
   use_int16 ( i + k );
}

/* end of R_08_06_2.c */

