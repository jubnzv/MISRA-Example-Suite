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
 * R.21.6
 *
 * The Standard Library input/output routines shall not be used
 */

#include "mc3_types.h"
#include "mc3_header.h"
#include <stdio.h>             /* Non-compliant */

void R_21_6 ( void )
{
     (void) printf ( "The library stdio shall not be used\n" ); /* Non-compliant */
}

/* end of R_21_06.c */

