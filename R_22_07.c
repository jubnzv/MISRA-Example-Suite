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
 * R.22.07
 *
 * The macro EOF shall only be compared with the unmodified return value from
 * any Standard Library function capable of returning EOF
 *
 */

/* Note: This file also contains violations of rule R.21.6 */

#include "mc3_types.h"
#include "mc3_header.h"

#include <stdio.h>

static void f_7 ( void )
{
  char ch;
  ch = ( char ) getchar ( );

  /*
   * The following test is not reliable as the return value
   * is cast to a narrower type before checking for EOF.
   */
  if ( EOF != ( int32_t ) ch )  /* Non-compliant */
  {
     use_char ( ch );
  }
}


static void g_7 ( void )
{
  char ch;
  ch = ( char ) getchar ( );

  if ( feof ( stdin ) != 0 )    /* Compliant */
  {
     use_char ( ch );           /* Breaks D.4.14 */
  }
}

static void h_7 ( void )
{
  int32_t i_ch;
  i_ch = getchar ();

  /*
   * The following test is reliable as the unconverted
   * return value is used when checking for EOF.
   */
  if ( EOF != i_ch )    /* Compliant */
  {
    char ch;
    ch = ( char ) i_ch;
    use_char ( ch );
  }
}


void R_22_7 ( void )
{
   f_7 ( );
   g_7 ( );
   h_7 ( );
}

/* end of R_22_07.c */

