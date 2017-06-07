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
 * R.9.2
 *
 * The initializer for an aggregate or union shall be enclosed in braces
 */

#include "mc3_types.h"
#include "mc3_header.h"

void R_9_2 ( void  )
{
   int16_t y1[ 3 ][ 2 ] = { 1, 2, 0, 0, 5, 6 };             /* Non-compliant */
   int16_t y2[ 3 ][ 2 ] = { { 1, 2 }, { 0 }, { 5, 6 } };    /* Compliant     */
   int16_t y3[ 3 ][ 2 ] = { { 1, 2 }, { 0, 0 }, { 5, 6 } }; /* Compliant     */

   int16_t z1[ 2 ][ 2 ] = { { 0 }, [ 1 ][ 1 ] = 1 };       /* Compliant      */
   int16_t z2[ 2 ][ 2 ] = { { 0 },
                            [ 1 ][ 1 ] = 1, [ 1 ][ 0 ] = 0
                          };                               /* Compliant      */
   int16_t z3[ 2 ][ 2 ] = { { 0 }, [ 1 ][ 0 ] = 0, 1 };    /* Non-compliant  */
   int16_t z4[ 2 ][ 2 ] = { [ 0 ][ 1 ] = 0, { 0, 1 } };    /* Compliant      */

   float32_t a1[ 3 ][ 2 ] = { 0 };                         /* Compliant      */
   float32_t a2[ 3 ][ 2 ] = { { 0 }, { 0 }, { 0 } };       /* Compliant      */
   float32_t a3[ 3 ][ 2 ] = { { 0.0f, 0.0f },
                              { 0.0f, 0.0f },
                              { 0.0f, 0.0f }
                            };                             /* Compliant     */

   union                                                  /* breaks R.19.2 */
   {
      int16_t   i16;
      float32_t f32;
   } u = { 0 };                                           /* Compliant     */

   struct
   {
     uint16_t len;
     char     buf[ 8 ];
   } s[ 3 ] = {
       { 5u, { 'a', 'b', 'c', 'd', 'e', '\0', '\0', '\0' } },
       { 2u, { 0 } },
       { .len = 0u }                      /* Compliant - buf initialized implicitly */
     };                                   /* Compliant - s[ ] fully initialized     */


   use_int16 ( y1[ 0 ][ 0 ] );
   use_int16 ( y2[ 0 ][ 0 ] );
   use_int16 ( y3[ 0 ][ 0 ] );

   use_int16 ( z1[ 0 ][ 0 ] );
   use_int16 ( z2[ 0 ][ 0 ] );
   use_int16 ( z3[ 0 ][ 0 ] );
   use_int16 ( z4[ 0 ][ 0 ] );

   use_float32 ( a1[ 0 ][ 0 ] );
   use_float32 ( a2[ 0 ][ 0 ] );
   use_float32 ( a3[ 0 ][ 0 ] );

   use_int16 ( u.i16 );
   use_float32 ( u.f32 );
   use_uint16 ( s[ 0 ].len );
   use_char ( s[ 0 ].buf[ 0 ] );
}

/* end of R_09_02.c */
