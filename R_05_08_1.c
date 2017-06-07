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


int32_t count8;           /* "count8" has external linkage - Note: breaks R.8.4 */

/* Note: foo8 has intentionally no separate declaration, breaks R.8.4 */
void foo8 ( void )        /* "foo8" has external linkage   */
{
   int16_t index;         /* compliant - "index" has no linkage       */

   index = get_int16 ( );
   use_int16 ( index );
   use_int32 ( count8 );
}

void R_5_8 ( void )
{
   count8 = get_int32 ( );
   foo8 ( );
   R_5_8_2 ( );
}


/* End of R_05_08_01.c */


