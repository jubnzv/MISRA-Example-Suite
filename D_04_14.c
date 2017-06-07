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
 * D.4.14
 *
 * The validity of values received from external sources shall be checked
 */

/* Note: This file also contains a violation of rule R.21.6 */

#include "mc3_types.h"
#include "mc3_header.h"

#include <stdio.h>

void D_4_14 ( void )
{
   char input [ 128 ];

   ( void ) scanf ( "%128c", input );

   ( void ) printf ( "%s", input );      /* Non-compliant */

}
/* end of D_04_14.c */
