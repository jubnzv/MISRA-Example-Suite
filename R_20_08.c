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
 * R.20.8
 *
 * The controlling expression of a #if or #elif preprocessing directive shall 
 * evaluate to 0 or 1
 */

#include "mc3_types.h"
#include "mc3_header.h"


#define FALSE 0

#if FALSE                 /* Compliant     */
#endif

#if 10                    /* Non-compliant */
#endif


#if ! defined ( X )        /* Compliant    */
#endif

#define A 10
#define B 5

#if  A > B                 /* Compliant    */
#endif

void R_20_8 ( void )
{
  use_int32 ( 3 );
}

/* end of R_20_08.c */
