/*
 * Release: 2016-11-01
 *
 * Example from MISRA C:2012  (  THIS IS NOT A TEST SUITE  )
 *
 * Copyright HORIBA MIRA Limited.
 *
 * See file READ_ME.txt for full copyright, license and release instructions.
 */

/*
 * R.9.3
 *
 * Arrays shall not be partially initialized
 */

#include "mc3_types.h"
#include "mc3_header.h"

#define PI 3.14f

void R_9_3 (  void  )
{
   int32_t x[ 3 ] = { 0, 1, 2 };                     /* Compliant                                               */
   int32_t y[ 3 ] = { 0, 1 };                        /* Non-compliant: y[ 2 ] is implicitly initialised           */

   float32_t t[ 4 ]  = { [ 1 ] = 1.0f, 2.0f };           /* Non-compliant: t[ 0 ] and t[ 3 ] are implicitly initialised */
   float32_t z[ 50 ] = { [ 1 ] = 1.0f, [ 25 ] = 2.0f };  /* Compliant by exception 2: designated initialisers for sparse matrix    */

   float32_t arr[ 3 ][ 2 ] =
   {
      { 0.0f, 0.0f },
      { PI / 4.0f, -PI / 4.0f },
      { 0 }                           /* { 0 } initialises all elements of array subobject arr[ 3 ]  */
   };

   char_t ac_5[ 5 ] = { '\0' };            /* Non-compliant */

   uint16_t au_3_2[ 3 ][ 2 ] = { 0U };     /* Non-compliant */

   uint16_t au_3[ 3 ] = { 0U };            /* Non-compliant */

   float32_t af_3_2[ 3 ][ 2 ]  = { 0.0F }; /* Non-compliant */

   float32_t arr2[ 3 ][ 2 ] = { 0 };  /* Compliant by exception 1 */

   char h[ 10 ] = "Hello";            /* Compliant by exception 3 */

   use_char ( h[ 0 ] );
   use_char ( ac_5[ 0 ] );
   use_uint16 ( au_3_2[ 0 ][ 0 ] );
   use_uint16 ( au_3[ 0 ] );
   use_int32 ( x[ 0 ] );
   use_int32 ( y[ 0 ] );
   use_float32 ( t[ 0 ] );
   use_float32 ( z[ 0 ] );
   use_float32 ( arr[ 0 ][ 0 ] );
   use_float32 ( af_3_2[ 0 ][ 0 ] );
   use_float32 ( arr2[ 0 ][ 0 ] );

}
/* end of R_09_03.c */
