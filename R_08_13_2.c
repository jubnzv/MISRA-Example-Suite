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
 * R.8.13
 *
 * A pointer should point to a const-qualified type whenever possible.
 */

#include "R_08_13.h"

void h13 ( const uint16_t *p )
{
   *p = 0;  /* Constraint Error */
}

/* end of R_08_13.c */
