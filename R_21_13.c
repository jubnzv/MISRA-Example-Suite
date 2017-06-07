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
 * R.21.13
 *
 * Any value passed to a function in <ctype.h> shall be representable
 * as an unsigned char or be the value EOF
 */

#include "mc3_types.h"
#include "mc3_header.h"

#include <ctype.h>
#include <stdio.h>

static bool_t f_13 ( uint8_t a )
{
  return (
              ( isdigit ( ( int32_t )   a ) != 0 )  /* Compliant     */
           && ( isalpha ( ( int32_t ) 'b' ) != 0 )  /* Compliant     */
           && ( islower (             EOF ) != 0 )  /* Compliant     */
           && ( isalpha (            256  ) != 0 )  /* Non-compliant */
         );
}

void R_21_13 ( void )
{
  bool_t bl;
  bl = f_13( 3U );
  use_bool( bl );
}

/* end of R_21_13.c */

