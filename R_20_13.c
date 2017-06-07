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
 * R.20.13
 *
 * A line whose first token is # shall be a valid preprocessing directive
 */

#include "mc3_types.h"
#include "mc3_header.h"

/*
#start is not a token in a comment
*/

#define AAA 2

static int32_t foo ( void )
{
   int32_t x = 0;

 #ifndef AAA
    x = 1;
 #else1            /* Non-compliant */
    x = AAA;
 #endif

    return x;
}


void R_20_13 ( void )
{
   int32_t x;
   x = foo ( );
   use_int32 ( x );
}

/* end of R_20_13.c */

