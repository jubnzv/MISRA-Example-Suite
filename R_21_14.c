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
 * R.21.14
 *
 * The Standard Library function memcmp shall not be used to compare
 * null terminated strings
 */

/* Note: Extern only used in 1 file breaks R.8.7 */

#include "R_21_14.h"
#include <string.h>

static void f_14_1 ( void )
{
  ( void ) strcpy ( buffer1, "abc" );
  ( void ) strcpy ( buffer2, "abc" );

  if ( memcmp ( buffer1, buffer2, sizeof ( buffer1 ) ) != 0 ) /* Non-compliant */
  {
    /*
     * The strings stored in buffer1 and buffer 2 are reported to be
     * different, but this may actually be due to differences in the
     * uninitialised characters stored after the null terminators.
     */
  }
}

static bool_t f_14_2 ( const uint8_t *packet )
{
  uint8_t headerStart[ 6 ] = { 'h', 'e', 'a', 'd', 0, 164 }; /* Breaks R.10.3 */
  bool_t ok;

  if ( ( NULL != packet ) &&
        ( memcmp( packet, headerStart, 6 ) == 0 ) /* Compliant */
      )
  {
     ok = true;
    /*
     * Comparison of values having essentially unsigned type reports that
     * contents are the same. Any null terminator is simply treated as a
     * zero value and any differences beyond it are significant.
     */
  }
  else
  {
     ok = false;
  }
  return ok;
}


void R_21_14 ( void )
{
  uint8_t loc_data[ 6 ] = { 1U, 2U, 3U, 4U, 5U, 6U };
  bool_t result;

  f_14_1 ( );
  result = f_14_2 ( loc_data );
  use_bool ( result );
}

/* end of R_21_14.c */

