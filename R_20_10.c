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
 * R.20.10
 *
 * The # and ## preprocessor operators should not be used
 */

#include "mc3_types.h"
#include "mc3_header.h"


#define A( x )    #x            /* Non-compliant */
#define B( x, y ) x##y = 0      /* Non-compliant */


void R_20_10 ( void )
{
   const char * string_literal = A ( 10 );
   use_char ( *string_literal );

   int32_t aval;
   B ( a, val );
   use_int32 ( aval );
}

/* end of R_20_10.c */

