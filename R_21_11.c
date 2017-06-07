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
 * R.21.11
 *
 * The standard header file <tgmath.h> shall not be used
 */

#include "mc3_types.h"
#include "mc3_header.h"
#include <tgmath.h>        /* Non-compliant */


void R_21_11 ( void )
{
   float32_t f1;
   float32_t f2 = get_float32 ( );

   f1 = sqrt ( f2 );       /* Non-compliant - generic sqrt used      */
   use_float32 ( f1 );

   f1 = sqrtf ( f2 );      /* Compliant - float version of sqrt used  */
   use_float32 ( f1 );

}
/* end of R_21_11.c */

