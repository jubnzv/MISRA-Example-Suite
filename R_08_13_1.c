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
 * R.8.13
 *
 * A pointer should point to a const-qualified type whenever possible.
 */

#include "R_08_13.h"
#include <string.h>


static uint16_t f13 ( uint16_t *p )         /* Non-compliant */
{
  return *p;
}

static uint16_t g13 ( const uint16_t *p )   /* Compliant */
{
  return *p;
}


static char last_char ( char * const s )           /* Non-compliant */
{
    return s[ strlen ( s ) - 1u ];
}

static char last_char_ok (const char * const s)    /* Compliant */
{
    return s[ strlen ( s ) - 1u ];
}


static int16_t first ( int16_t a5[ 5 ] )           /* Non-compliant */
{
   return a5[0];
}

static int16_t first_ok ( const int16_t a5[ 5 ] )  /* Compliant */
{
   return a5[0];
}

void R_8_13 ( void )
{
   uint16_t val1 = 5u;
   uint16_t *ptr1 = &val1;
   const uint16_t val2 = 5u;
   const uint16_t *ptr2 = &val2;

   use_uint16 ( f13( ptr1 ) );
   use_uint16 ( g13( ptr2 ) );
   h13 ( ptr2 );

   int16_t arr1[ 5 ] = { 0, 1, 2, 3, 4 };
   ( void ) first ( arr1 );
   ( void ) first_ok ( arr1 );

   char * str13 = get_char_ptr ( );
   ( void ) last_char ( str13 );
   ( void ) last_char_ok ( "astring" );

}

/* end of R_08_13.c */
