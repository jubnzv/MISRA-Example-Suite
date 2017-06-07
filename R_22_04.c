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
 * R.22.4
 *
 * There shall be no attempt to write to a stream which has been opened as read-only
 */

/* Note: This file also contains violations of rule R.21.6 */


#include "mc3_types.h"
#include "mc3_header.h"

#include <stdio.h>

static void fn4 ( void )
{
   FILE *fp = fopen ( "tmp", "r" );

   ( void ) fprintf ( fp, "What happens now?" );   /* Non-compliant */

   ( void ) fclose ( fp );
}

void R_22_4 ( void )
{
   fn4 ( );
}
/* end of R_22_04.c */
