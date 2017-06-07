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
 * R.21.17
 *
 * Use of the string handling functions from <string.h> shall not result in
 * accesses beyond the bounds of the objects referenced by their pointer parameters
 *
 */

#include "mc3_types.h"
#include "mc3_header.h"

#include <string.h>


static void f_17 ( const char *str )
{
  char string[ ] = "Short";

  use_char_ptr ( string );

  /* strcpy results in writes beyond the end of 'string' */
  ( void ) strcpy ( string, "Too long to fit" );  /* Non-compliant - Also breaks R.21.18 */

  use_char_ptr ( string );

  /* 'string' is only modified if 'str' will fit. */
  if ( strlen ( str ) < ( sizeof ( string ) - 1U ) ) /* Compliant */
  {
    ( void ) strcpy ( string, str );
  }

  use_char_ptr ( string );
}

static void  g_17 ( void )
{
  size_t sz;
  char text[ 5 ] = "Token";

  /* Reads beyond the end of 'text' as there is no null terminator.  */
  sz = strlen ( text );  /* Non-compliant */
  if ( sz > 1U )
  {
    use_sizet ( sz );
  }
}


void R_21_17 ( void )
{
  f_17 ( "small" );
  g_17 ( );
}

/* end of R_21_17.c */

