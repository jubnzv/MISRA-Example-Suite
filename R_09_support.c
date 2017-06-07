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


void R_9_main_support ( void )
{
  R_9_1 ( );
  R_9_2 ( );
  R_9_3 ( );
  R_9_4 ( );
  R_9_5 ( );
}

/* end of R_09_support.c */

