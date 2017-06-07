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
 * R.22.08
 *
 * The value of errno shall be set to zero prior to a call to an
 * errno-setting-function
 *
 */

#include "mc3_types.h"
#include "mc3_header.h"

#include <errno.h>
#include <stdlib.h>

/* Note: strtoul is an errno-setting-function */

void R_22_8 ( void )
{
   const char *c_str = "435 followed by text";
   char *endpt1 = NULL;
   char *endpt2 = NULL;
   char *endpt3 = NULL;
   uint64_t num1;
   uint64_t num2;
   uint64_t num3;

   num1 = strtoul( c_str, &endpt1 ,0 );   /* Non-compliant          */

   if ( 0 == errno )
   {
      use_uint64 ( num1 );
      if ( endpt1 != NULL )
      {
        use_char_ptr ( endpt1 );
      }

      num2 = strtoul(c_str, &endpt2 ,0);    /* Compliant by exception */

      if ( 0 == errno )
      {
        use_uint64 ( num2 );
        if ( endpt2 != NULL )
        {
          use_char_ptr ( endpt2 );
        }
      }
   }
   else
   {
     errno = 0;

     num3 = strtoul(c_str, &endpt3 ,0);   /* Compliant              */

     if ( 0 == errno )
     {
        use_uint64 ( num3 );
        if ( endpt3 != NULL )
        {
          use_char_ptr ( endpt3 );
        }
     }
   }
}


/* end of R_22_08.c */

