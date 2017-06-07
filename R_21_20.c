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
 * R.21.20
 *
 * The pointer returned by the Standard Library functions asctime, ctime, gmtime,
 * localtime, localeconv, getenv, setlocale or strerror shall not be used following
 * a subsequent call to the same function
 *
 */

/* Note: This file also contains violations of rule R.21.6 */


#include "mc3_types.h"
#include "mc3_header.h"

#include <locale.h>
#include <string.h>
#include <stdio.h>

void R_21_20 ( void )
{
   const char *res1;
   const char *res2;
         char  copy[ 128 ];

   res1 = setlocale ( LC_ALL, 0 );

   if ( res1 != NULL )
   {
     ( void ) strcpy ( copy, res1 );

     res2 = setlocale ( LC_MONETARY, "French" );

     if ( res2 != NULL )
     {
        ( void ) printf ( "%s\n", res1 );   /* Non-compliant - use after subsequent call    */
        ( void ) printf ( "%s\n", copy );   /* Compliant - copy made before subsequent call */
        ( void ) printf ( "%s\n", res2 );   /* Compliant - no subsequent call before use    */
     }
   }
 }

/* end of R_21_20.c */

