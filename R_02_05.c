/*
 * Release: 2016-11-01
 *
 * Example from MISRA C:2012 ( THIS IS NOT A TEST SUITE )
 *
 * Copyright HORIBA MIRA Limited.
 *
 * See file READ_ME.txt for full copyright, license and release instructions.
 */

/*
 * R.2.5
 *
 * A project should not contain unused macro declarations
 */


#include "mc3_types.h"
#include "mc3_header.h"

void R_2_5 ( void )
{

#define SIZE 4
/* Non-compliant - DATA not used */
#define DATA 3

/* Compliant - #undef counts as use of M1 */
#define M1 This

   use_int16 ( SIZE );

#undef M1  /* breaks R.20.5 */
}

/* end of R_02_05.c */
