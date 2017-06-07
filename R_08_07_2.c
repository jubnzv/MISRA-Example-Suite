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
 * R.8.7
 *
 * Functions and objects should not be defined with external linkage if they
 * are referenced in only one translation unit
 */


#include "R_08_07.h"

void R_8_7_2 ( void )
{
   extern_required = get_int32 ( );
}

/* end of R_08_07_2.c */
