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
 * R.5.8
 *
 * Identifiers that define objects or functions with external linkage shall be 
 * unique
 */

#include "R_05_08.h"


static void foo8 (void)       /* Non-compliant */
                              /* Already defined with external linkage in R_05_08_01.c */
{
   int16_t count8;            /* Non-compliant                   */
                              /* "count8" has no linkage but clashes with an
                                identifier with external linkage */

   int32_t index;            /* Compliant - "index" has no linkage */

   index = get_int32 ( );
   use_int32 ( index );
   count8 = get_int16 ( );
   use_int16 ( count8 );
}

void R_5_8_2 ( void )
{
   foo8 ( );
}

/* End of R_05_08_02.c */


