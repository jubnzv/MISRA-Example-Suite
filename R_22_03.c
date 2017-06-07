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
 * R.22.3
 *
 * The same file shall not be open for read and write access at the same time 
 * on different streams 
 */

/* Note: This file also contains violations of rule R.21.6 */


#include "mc3_types.h"
#include "mc3_header.h"

#include <stdio.h>

static void fn3 ( void )
{
   int32_t value1;
   int32_t value2;

   FILE *fw = fopen ( "tmp3", "r+" );
   FILE *fr = fopen ( "tmp3", "r" );   /* Non_compliant */

   ( void ) fscanf ( fw, "%d", &value1 );
   ( void ) fscanf ( fw, "%d", &value2 );

   use_int32 ( value1 + value2 );

   ( void ) fclose ( fw );
   ( void ) fclose ( fr );
 }

void R_22_3 ( void )
{
   fn3 ( );
}
/* end of R_22_03.c */
