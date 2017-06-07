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
 * R.20.14
 *
 * All #else, #elif and #endif preprocessor directives shall reside in the same 
 * file as the #if, #ifdef or #ifndef directive to which they are related
 */

#include "mc3_types.h"
#include "mc3_header.h"

#define A

#ifdef A            /* Compliant     */
#include "R_20_14_1.h"
#endif


#if 1               /* Non-compliant */
#include "R_20_14_2.h"


void R_20_14 ( void )
{
  use_int32 ( 3 );
}

/* end of R_20_14.c */
