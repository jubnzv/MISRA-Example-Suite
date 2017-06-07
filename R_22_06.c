/*
 * Release: 2016-11-01
 *
 * Example from MISRA C:2012 ( THIS IS NOT A TEST SUITE )
 *
 * Copyright HORIBA MIRA Limited.
 *
 * See file READ_ME.txt for full copyright, license and release instructions.
 */

/*
 * R.22.6
 *
 * The value of a pointer to a FILE shall not be used after the associated 
 * stream has been closed
 */

/* Note: This file also contains violations of rule R.21.6 */

#include "R_22_06.h"

#include <stdio.h>


static void fn6 ( void )
{
   FILE *fp;

   fp = fopen ( "tmp", "w" );

   if ( fp == NULL )                /* Compliant */
   {
      error_action ( );
   }
   else
   {
     void *p;

     ( void ) fclose ( fp );

     ( void ) fprintf ( fp, "?" );   /* Non-compliant */

     p = fp;                         /* Non-compliant */

     use_void_ptr ( p );
  }
}

void R_22_6 ( void )
{
   fn6 ( );
}

/* end of R_22_06.c */
