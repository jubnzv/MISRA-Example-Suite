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
 * R.14.1
 *
 * A loop counter shall not have essentially floating type
 */


#include "mc3_types.h"
#include "mc3_header.h"

void R_14_1 ( void )
{
   uint32_t sum = 0u;

   for ( float32_t f1 = 0.0f; f1 < 1.0f; f1 += 0.001f ) /* Non-compliant */
   {
     ++sum;
   }
   use_uint32 ( sum );


   float32_t f;
   for ( uint32_t counter = 0u; counter < 1000u; ++counter )  /* compliant */
   {
      f = ( float32_t ) counter * 0.001f;
      use_float32 ( f );
   }


   f = 0.0f;
   while ( f < 1.0f ) /* Non-compliant */
   {
      f += 0.001f;
   }
   use_float32 ( f );


   uint32_t u32a;
   f = get_float32 ( ) ;
   do
   {
      u32a = get_uint32 ( );
      /* f does not change in the loop so cannot be a loop counter */
   } while ( ( ( float32_t ) u32a - f ) > 10.0f );  /* compliant */

   use_float32(f);

}

/* end of R_14_01.c */

