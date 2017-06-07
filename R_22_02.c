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
 * R.22.2
 *
 * A block of memory shall only be freed if it was allocated by means of a 
 * Standard Library function
 */

/* Note: This file also contains violations of rule R.21.3 */

#include "mc3_types.h"
#include "mc3_header.h"

#include <stdlib.h>

static void fn ( void )
{
   int32_t a;

   free ( &a );                        /* Non-compliant - a does not point to allocated storage    */
}


static void  g ( void )
{
   char *p = ( char * ) malloc ( 512 );
   char *q = p;

   if ( p != NULL )
   {
      *p = 'A';
      use_char ( *p );
      use_char ( *q );
   }

   free ( p );
   free ( q );                         /* Non-compliant: allocated block freed a second time       */

   p = ( char * )realloc ( p, 1024 );  /* Non-compliant: allocated block may be freed a third time */

   free ( p );
}

void  R_22_2 (void)
{
  fn ( );
  g ( );
}

/* end of R_22_02.c */
