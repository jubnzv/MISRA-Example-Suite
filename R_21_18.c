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
 * R.21.18
 *
 * The size_t argument passed to any function in <string.h> shall have
 * an appropriate value
 *
 */

/* Note: This file also contains violations of rule R.21.14 */

#include "mc3_types.h"
#include "mc3_header.h"

#include <string.h>

void R_21_18 ( void )
{
   const char buf1[  5 ] = "12345";
   const char buf2[ 10 ] = "1234567890";

   if ( memcmp ( buf1, buf2, 5 ) == 0 )                  /* Compliant     */
   {
     use_char ( buf1[ 0 ] );
   }

   if ( memcmp ( buf1, buf2, 6 ) == 0 )                  /* Non-compliant */
   {
     use_char ( buf2[ 0 ]);
   }
}

/* end of R_21_18.c */

