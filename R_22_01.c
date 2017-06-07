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
 * R.22.1
 *
 * All resources obtained dynamically by means of Standard Library functions 
 * shall be explicitly released
 */

/* Note: This file also contains violations of rules R.21.3 and 21.6 */

#include "mc3_types.h"
#include "mc3_header.h"

#include <stdlib.h>
#include <stdio.h>

static int32_t R_22_1_heap ( void )
{
   void *b = malloc ( 40 );

   use_void_ptr ( b );

   /* Non-compliant - dynamic memory not released */
   return 1;
}


static int32_t R_22_1_file1 ( void )
{
   int32_t value;

   FILE *fp1 = fopen ( "tmp", "r" );

   ( void ) fscanf ( fp1, "%d", &value );

   /* Non-compliant - file not closed */
   return value;
}


static int32_t R_22_1_file2 ( void )
{
   FILE * fp;
   fp = fopen ( "tmp-1", "w" );

   ( void ) fprintf ( fp, "*" );
   /* File "tmp-1" should be closed here, but stream 'leaks'. */

   fp = fopen ( "tmp-2", "w" );  /*Non-compliant */

   ( void ) fprintf ( fp, "!" );

   ( void ) fclose ( fp );

   return ( 0 );
}


void R_22_1 ( void )
{
   ( void ) R_22_1_heap ( );
   ( void ) R_22_1_file1 ( );
   ( void ) R_22_1_file2 ( );
}

/* end of R_22_01.c */

