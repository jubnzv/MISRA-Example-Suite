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
 * R.15.1
 *
 * The goto statement should not be used
 */

#include "mc3_types.h"
#include "mc3_header.h"

void R_15_1 ( void )
{
   goto lab1;       /* Non-compliant */
lab1:
   use_int32 ( 3 );
}
/* end of R_15_01.c */

