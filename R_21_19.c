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
 * R.21.19
 *
 * The pointers returned by the Standard Library functions localeconv,
 * getenv, setlocale or, strerror shall only be used as if they have
 * pointer to const-qualified type
 *
 */

#include "mc3_types.h"
#include "mc3_header.h"

#include <locale.h>
#include <string.h>

static void f_19 ( void )
{
  char         *s1   = setlocale ( LC_ALL, 0 );   /* Non-compliant declaration      */
  struct lconv *conv = localeconv ();             /* Non-compliant declaration      */

  if( s1 != NULL )
  {
    s1[ 1 ]             = 'A';                    /* Non-compliant use - Undefined behaviour */
    use_char_ptr ( s1 );
  }

  if( conv != NULL )
  {
    conv->decimal_point = "^";                    /* Non-compliant use - Undefined behaviour */
    use_char_ptr ( conv->decimal_point );
  }
}


static void g_19 ( void )
{
  char str[ 128 ];

  ( void ) strcpy ( str,
                    setlocale ( LC_ALL, 0 ) );   /* Compliant - 2nd parameter to
                                                    strcpy takes a const char *  */
  if( str != NULL )
  {
    use_char_ptr ( str );
  }

  const struct lconv *conv = localeconv ();      /* Compliant                    */

  if( conv != NULL )
  {
    conv->decimal_point = "^";                   /* Constraint violation         */
    use_char_ptr ( conv->decimal_point );
  }
}


static void h_19 ( void )
{
  const struct lconv *conv = localeconv ();      /* Compliant     */

  if( conv != NULL )
  {
    conv->grouping[ 2 ] = 'x';                     /* Non-compliant */
    use_char ( conv->grouping[ 2 ] );
  }

}


void R_21_19 ( void )
{
  f_19 ( );
  g_19 ( );
  h_19 ( );
}

/* end of R_21_19.c */

