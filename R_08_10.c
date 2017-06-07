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
 * R.8.10
 *
 * An inline function shall be declared with the static storage class
 */

/* Note: Extern only used in 1 file breaks R.8.7. */


#include "mc3_types.h"
#include "mc3_header.h"

inline int32_t max ( int32_t val1, int32_t val2 );  /* Non-compliant */

inline int32_t max ( int32_t val1, int32_t val2 )    /* Non-compliant */
{
  return (val1 > val2) ? val1 : val2;
}

void R_8_10 ( void )
{
   int32_t xmax = max (3, 5);
   use_int32 ( xmax );
}

/* end of R_08_10.c */
