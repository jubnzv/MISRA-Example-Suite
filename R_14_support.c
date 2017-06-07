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


void R_14_main_support ( void )
{
  R_14_1 ( );
  R_14_2 ( );
  R_14_3 ( );
  R_14_4 ( );
}

/* end of R_14_support.c */

