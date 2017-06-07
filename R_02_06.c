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
 * R.2.6
 *
 * A function should not contain unused label declarations
 */

#include "mc3_types.h"
#include "mc3_header.h"

void R_2_6 ( void )
{
   int16_t x = 6;
label1:   /* Non Compliant */
   use_int16 ( x );
}

/* end of R_02_06.c */
