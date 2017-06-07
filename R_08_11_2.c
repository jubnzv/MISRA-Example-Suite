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
 * R.8.11
 *
 * When an array with external linkage is declared, its size should be
 * explicitly specified
 */

#include "R_08_11.h"

int32_t array1 [ 10 ] = { 0 };
int32_t array2 [ ] = { 1, 2, 3 };

void R_8_11_2 ( void )
{
  use_int32 ( array1[ 0 ] + array2[ 0 ] );
}

/* end of R_08_11_2.c */
