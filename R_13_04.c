/*
 * Release: 2016-11-01
 *
 * Example from MISRA C:2012 ( THIS IS NOT A TEST SUITE )
 *
 * Copyright HORIBA MIRA Limited.
 *
 * See file READ_ME.txt for full copyright, license and release instructions.
 */

/*
 * R.13.4
 *
 * The result of an assignment operator should not be used
 */

#include "mc3_types.h"
#include "mc3_header.h"

static int32_t f4 ( void )
{
   return get_int32 ( );
}

void R_13_4 ( void )
{
   int32_t x;
   int32_t y = get_int32 ( );
   int32_t a[ 4 ] = { 0 };
   int32_t b = get_int32 ( );
   int32_t c = get_int32 ( );

   x = y;                                     /* Compliant */
   use_int32 ( x );

   a[ x ] = a[ x = y ];                       /* Non-compliant - also breaks R.13.2 */
   use_int32 ( x );

   bool_t bool_var = get_bool ( );
   use_bool ( bool_var );
   if ( bool_var = false )                    /* Non-compliant - also breaks R.14.3 */
   {
   }
   use_bool ( bool_var );

   if ( ( 0u == 0u ) || ( bool_var = true ) ) /* Non-compliant, also breaks R.13.5, R.14.3 */
   {
   }
   use_bool ( bool_var );


   if ( ( x = f4 ( ) ) != 0 )                  /* Non-compliant */
   {
   }

   a[ b += c ] = a[ b ];                     /* Non-compliant - also breaks R.13.2  */
   use_int32 ( b + x );

   x = b = c = 1;                            /* Non-compliant */

   use_int32 ( x + a[ 0 ] + b + c );
}

/* end of R_13_04.c */
