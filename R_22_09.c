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
 * R.22.09
 *
 * The value of errno shall be tested against zero after calling an
 * errno-setting-function
 *
 */

/* Note: This file also contains violations of rule R.21.6 */

#include "mc3_types.h"
#include "mc3_header.h"

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

/* Note: strtoul is an errno-setting-function */

static void handleError ( int32_t errval )
{
   ( void ) printf ( "Error value %d\n", errval );
}


static void f_9 ( void )
{
  const char *c_str = "435 followed by text";
  char *endpt1 = NULL;
  char *endpt2 = NULL;
  uint64_t num1;
  uint64_t num2;

  errno = 0;

  num1 = strtoul( c_str, &endpt1 ,0 ); /* Non-compliant - followed by function call */

  use_int32 ( 3 );

  if ( 0 != errno )
  {
     use_uint64 ( num1 );
     if ( endpt1 != NULL )
     {
       use_char_ptr ( endpt1 );
     }
  }


  errno = 0;

  num2 = strtoul( c_str, &endpt2 ,0 );

   if ( 0 != errno )   /* Compliant */
   {
      handleError ( errno );
   }
   else
   {
      use_uint64 ( num2 );
      if ( endpt2 != NULL )
      {
        use_char_ptr ( endpt2 );
      }
   }
}


static void g_9 (const FILE *f, const fpos_t *pos )
{
   errno = 0;

   if ( fsetpos ( f, pos ) == 0 )
   {
     /* Compliant by exception - no need to test errno as no out-of-band error reported. */
   }
   else
   {
     /* Something went wrong - errno holds an implementation-defined positive value. */
     handleError ( errno );
   }
}


void R_22_9 ( void )
{
  FILE *fptr = fopen ( "tmp.txt", "w+" );
  fpos_t position;

  if ( fptr != NULL )
  {
     errno = 0;
     ( void ) fgetpos ( fptr, &position );
     if ( errno == 0 )
     {
       ( void ) fputs ( "Hello World", fptr);
        g_9 ( fptr, &position );
     }
  }

  ( void ) fclose ( fptr );

  f_9 ( );
}


/* end of R_22_09.c */

