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
 * R.7.1
 *
 * Octal constants shall not be used
 */

#include "mc3_types.h"
#include "mc3_header.h"

void R_7_1 ( void )
{
   uint16_t code[ 10 ];

   code[ 0 ] = 109;      /* Compliant     - decimal 109    */
   code[ 1 ] = 100;      /* Compliant     - decimal 100    */
   code[ 2 ] = 052;      /* Non-Compliant - decimal 42     */
   code[ 3 ] = 071;      /* Non-Compliant - decimal 57     */

   use_uint16 ( code[ 0 ] );
   use_uint16 ( code[ 1 ] );
   use_uint16 ( code[ 2 ] );
   use_uint16 ( code[ 3 ] );
}

/* end of R_07_01.c */
