/*
 * Release: 2016-11-01
 *
 * Example from MISRA C:2012 AMD1 ( THIS IS NOT A TEST SUITE )
 *
 * Copyright HORIBA MIRA Limited.
 *
 * See file READ_ME.txt for full copyright, license and release instructions.
 */

/*
 * R.21.15
 *
 * The pointer arguments to the Standard Library functions memcpy, memmove and
 * memcmp shall be pointers to qualified or unqualified versions of compatible types
 */

#include "mc3_types.h"
#include "mc3_header.h"

#include <string.h>

static void f_15 ( uint8_t s1[ 8 ], uint16_t s2[ 8 ] )
{
  ( void ) memcpy ( s1, s2, 8 );    /* Non-compliant */
}


void R_21_15 ( void )
{
   uint8_t loc_s1[ 8 ];
   uint16_t loc_s2[ 8 ] = { 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U };

   f_15 ( loc_s1, loc_s2 );
   use_uint8 ( loc_s1[ 5 ]);
}

/* end of R_21_15.c */

