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
 * R.20.11
 *
 * A macro parameter immediately following a # operator shall not immediately 
 * be followed by a ## operator
 */

#include "mc3_types.h"
#include "mc3_header.h"

/* Note: The use of # and ## also breaks R.20.10 */

#define A( x )    #x            /* Compliant     */
#define B( x, y ) x ## y        /* Compliant     */
#define C( x, y ) #x ## y       /* Non-compliant */


void R_20_11 ( void )
{
  const char *x1 = A ( 0 );
  const char *B( x, 2 ) = x1;
  const char *x3 = C ( a, string ); /* syntax error unless ## is evaluated before # */

  use_char ( *x1 );
  use_char ( *x2 );
  use_char ( *x3 );
}

/* end of R_20_11.c */

