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
 * R.8.12
 *
 * Within an enumerator list, the value of an implicitly-specified enumeration
 * constant shall be unique
 */

#include "mc3_types.h"
#include "mc3_header.h"

void R_8_12 ( void )
{
   enum colour { red=3, blue, green, yellow=5 }; /* Non-compliant - green also 5 */

   enum colour favourite = red;

   use_int32 ( ( int32_t ) favourite );

}

/* end of R_08_12.c */
