/*
 * Release: 2016-01-01
 *
 * Example from MISRA C:2012 ( THIS IS NOT A TEST SUITE )
 *
 * Copyright HORIBA MIRA Limited.
 *
 * See file READ_ME.txt for full copyright, license and release instructions.
 */

/* Support file so that external functions are called more than once */

#include "mc3_types.h"
#include "mc3_header.h"


void R_7_main_support ( void )
{
  R_7_1 ( );
  R_7_2 ( );
  R_7_3 ( );
  R_7_4 ( );
}

/* end of R_07_support.c */

