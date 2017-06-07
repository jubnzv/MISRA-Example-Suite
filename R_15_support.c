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


void R_15_main_support ( void )
{
  R_15_1 ( );
  R_15_2 ( );
  R_15_3 ( );
  R_15_4 ( );
  R_15_5 ( );
  R_15_6 ( );
  R_15_7 ( );
}

/* end of R_15_support.c */

