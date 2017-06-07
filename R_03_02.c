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
 * R.3.2
 *
 * Line-splicing shall not be used in // comments
 */

#include "mc3_types.h"
#include "mc3_header.h"

void R_3_2 ( void )
{
   bool_t  b = get_bool ( );
   int32_t x;
   int32_t y = get_int32 ( );

   /* Non-compliant - logically equivalent to x = y + 1 */
   x = y + // comment \
         + z
         + 1;

   use_int32 ( x );

   /* Compliant - intention is made explicit             */
   x = y + // comment
           // + z
         + 1;

   use_int32 ( x );

   /* Non-compliant */
   x = 0; // comment \
   if ( b )
   {
     use_int32 ( x );          /* This is always executed     */
   }

   use_bool ( b );
}

/* end of R_03_02.c */
