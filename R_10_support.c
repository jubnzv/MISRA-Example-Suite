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


void R_10_main_support ( void )
{
  R_10_1 ( );
  R_10_2 ( );
  R_10_3 ( );
  R_10_4 ( );
  R_10_5 ( );
  R_10_6 ( );
  R_10_7 ( );
  R_10_8 ( );
}

/* end of R_10_support.c */

