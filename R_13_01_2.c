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
 * R.13.1
 *
 * Initialiser lists shall not contain persistent side-effects
 */

#include "R_13_01.h"


void R_13_1_2 ( void )
{
  vol = get_uint16 ( );
}

/* end of R_13_01_2.c */
