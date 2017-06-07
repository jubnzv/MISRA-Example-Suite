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
 * R.2.3
 *
 * A project should not contain unused type declarations
 */

#include "mc3_types.h"
#include "mc3_header.h"


static int16_t unusedtype ( void )
{
   typedef int16_t local_Type;   /* Non-compliant */

   return 67;
}

void R_2_3 ( void )
{
   use_int16 ( unusedtype ( ) );
}

/* end of R_02_03.c */
