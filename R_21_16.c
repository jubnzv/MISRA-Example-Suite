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
 * R.21.16
 *
 * The pointer arguments to the Standard Library function memcmp shall point to
 * either a pointer type, an essentially signed type, an essentially unsigned type,
 * an essentially Boolean type or an essentially enum type
 */

/* Note: This file also contains violations of rule R.19.2 */


#include "mc3_types.h"
#include "mc3_header.h"

#include <string.h>

struct S16 { int8_t m1; int8_t m2; };
union U16 { uint32_t range; uint32_t height; };


/*
 * Return value may indicate that 's1' and 's2' are different due to padding.
 */
static void f_16 ( const struct S16 *s1, const struct S16 *s2 )
{
  if ( memcmp ( s1, s2, sizeof ( struct S16 ) ) != 0 )    /* Non-compliant */
  {
     use_int8 ( s1->m1 + s2->m2 );
  }
  else
  {
     use_int8 ( s2->m1 + s1->m2 );
  }
}


/*
 * Return value may indicate that 'u1' and 'u2' are the same
 * due to unintentional comparison of 'range' and 'height'.
 */
static void g_16 ( const union U16 *u1, const union U16 *u2 )
{
  if ( memcmp ( u1, u2, sizeof ( union U16 ) ) != 0 )    /* Non-compliant */
  {
     use_uint32( u1->range + u2->height );
  }
  else
  {
     use_uint32( u2->range + u1->height );
  }
}


/*
 * Return value may incorrectly indicate strings are different as the
 * length of 'a' (4) is less than the number of bytes compared (6).
 */
static void  h_16 ( const char b[ 6 ] )
{
  const char a[ 6 ] = "task";

  if ( memcmp ( a, b, 6 ) != 0 )    /* Non-compliant - also break R.21.14 */
  {
     use_char( a[ 0 ] );
  }
  else
  {
     use_char( a[ 3 ] );
  }
}



void R_21_16 ( void )
{
  struct S16 sloc1 = { 1, 2 };
  struct S16 sloc2 = { 3, 4 };
  union U16 uloc1 = { 45U };
  union U16 uloc2 = { 100U };
  char arr[6] = "task10";

  f_16( &sloc1, &sloc2 );

  g_16( &uloc1, &uloc2 );

  h_16( arr );
}

/* end of R_21_16.c */

