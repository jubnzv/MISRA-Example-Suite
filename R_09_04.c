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
 * R.9.4
 *
 * An element of an object shall not be initialised more than once
 */

#include "mc3_types.h"
#include "mc3_header.h"

static uint16_t glob_arr[3] = {0u};
static uint16_t *glob_p = glob_arr;

static void f4 ( void )
{
    uint16_t a[ 2 ] = { [ 0 ] = *glob_p++, [ 0 ] = 1u };    /* Non-compliant, also breaks R.13.3, R.13.4 */
    use_uint16 ( a[0] );
    use_uint16_ptr ( glob_p );
}

void R_9_4 ( void )
{
   /* Required behaviour using positional initialisation                                                                 */
   int32_t a1[5] = { -5, -4, -3, -2, -1 };                      /* Compliant: a1 is  -5, -4, -3, -2, -1        */

   /* Similar behaviour using designated initialisers                                                                    */
   int32_t a2[5] =  { [0] = -5, [1] = -4, [2] = -3,
                      [3] = -2, [4] = -1 };                     /* Compliant: a2 is  -5, -4, -3, -2, -1        */

   /* Repeated designated initialiser element values overwrite earlier ones                                              */
   int32_t a3[5] = { [0] = -5, [1] = -4, [2] = -3,
                     [2] = -2, [4] = -1 };                      /* Non-compliant: a3 is -5, -4, -2, 0, -1      */

   struct mystruct
     {
         int32_t a;
         int32_t b;
         int32_t c;
         int32_t d;
     };

   /* Required behaviour using positional initialisation                                                                 */
   struct mystruct s1 = { 100, -1, 42, 999 };                             /* Compliant: s1 is 100, -1, 42, 999           */

   /* Similar behaviour using designated initialisers                                                                    */
   struct mystruct s2 = { .a = 100, .b = -1, .c = 42, .d = 999 };         /* Compliant: s2 is 100, -1, 42, 999           */

   /* Repeated designated initialiser element values overwrite earlier ones                                              */
   struct mystruct s3 = { .a = 100, .b = -1, .a = 42, .d = 999 };         /* Non-compliant: s4 is 42, -1, 0, 999         */

   use_int32 ( a1[0] );
   use_int32 ( a2[0] );
   use_int32 ( a3[0] );
   use_int32 ( s1.a + s1.b + s1.c + s1.d );
   use_int32 ( s2.a + s2.b + s2.c + s2.d );
   use_int32 ( s3.a + s3.b + s3.c + s3.d );

   f4( );
   use_uint16_ptr ( glob_p );
}

/* end of R_09_04.c */
