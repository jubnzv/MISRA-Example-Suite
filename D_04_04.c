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
 * D.4.4
 *
 * Sections of code should not be 'commented out'
 */

#include "mc3_types.h"
#include "mc3_header.h"

void D_4_4 ( void )
{
   int32_t a;

   /* a = 3;   Non-compliant  */
   a = 1;
   // a = 3;   Non-compliant

   use_int32 ( a );
}

/* end of D_04_04.c */

