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
 * R.4.1
 *
 * Octal and hexadecimal escape sequences shall be terminated
 */

#include "mc3_types.h"
#include "mc3_header.h"

void R_4_1 ( void )
{
   const char *s1 = "\x41g";     /* Non-compliant */
   const char *s2 = "\x41" "g";  /* Compliant - terminated by end of literal */
   const char *s3 = "\x41\x67";  /* Compliant - terminated by another escape */

   int32_t c1 = '\141t';       /* Non-compliant */
   int32_t c2 = '\141\t';      /* Compliant - terminated by another escape */

   use_const_char_ptr ( s1 );
   use_const_char_ptr ( s2 );
   use_const_char_ptr ( s3 );
   use_int32 ( c1 + c2 );
}

/* end of R_04_01.c */
