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
 * R.18.1
 *
 * A pointer resulting from arithmetic on a pointer operand shall address an 
 * element of the same array as that pointer operand
 */

/* The use of the + operator on a pointer violates R.18.4. */


#include "mc3_types.h"
#include "mc3_header.h"


static int32_t f1 ( const int32_t * const a1, const int32_t a2 [ 10 ] )
{
   const int32_t * p = &a1 [ 1 ];   /* Compliant/non-compliant - a1 may not be pointer to array */
   return *( a2 + 9 );              /* Compliant */
}


static void f2 ( void )
{
   int32_t index = get_int32 ( );
   int32_t data;
   int32_t b = 0;
   int32_t c [ 10 ] = { 0 };
   int32_t d [ 5 ] [ 2 ] = { 0 };

   int32_t * p1 = &c [ 0  ];   /* Compliant */
   int32_t * p2 = &c [ 10 ];   /* Compliant     - points to one beyond  */
   int32_t * p3 = &c [ 11 ];   /* Non-compliant - undefined, points to two beyond  */

   data = *p2;                 /* Non-compliant - undefined, dereference one beyond */
   use_int32 ( data );

   data = f1 ( &b, c );
   use_int32 ( data );
   data = f1 ( c, c );
   use_int32 ( data );

   p1++;                       /* Compliant */
   use_int32 ( p1 [ 0 ] );
   c[ -1 ] = 0;                /* Non-compliant - undefined, array bounds exceeded  */

   data = c [ 10 ];            /* Non-compliant - undefined, dereference of address one beyond */
   use_int32 ( data );

   data = *( &data + 0 );      /* Compliant - C treats data as an array of size 1 */
   use_int32 ( data );

   d[ 3 ][ 1 ]  = 0;           /* Compliant */
   data = *( *( d + 3 ) + 1 ); /* Compliant */
   use_int32 ( data );

   data = d[ 2 ][ 3 ];         /* Non-compliant - undefined, internal boundary exceeded */
   use_int32 ( data );

   p1 = d [ 1 ];               /* Compliant */
   data = p1 [ 1 ];            /* Compliant - p1 addresses an array element of size 2 */

   if ( p2 > &c[ index ] )
   {
      use_int32 (  data );
   }

}


static void f3 ( void )
{
   struct {
      uint16_t x;
      uint16_t y;
      uint16_t z;
      uint16_t a[ 10 ];
   } st = { 0U };

   uint16_t *p;
   p = &st.x;

   ++p;                        /* Compliant - p points one beyond s.x    */

   p[ 0 ] = 1;                 /* Non-compliant - undefined, dereference
                                  of address one beyond s.x which is not
                                  necessarily the same as s.y            */
   p[ 1 ] = 2;                 /* Non-compliant - undefined              */

   p = &st.a[ 0 ];              /* Compliant - p points into s.a          */
   p = p + 8;                  /* Compliant - p still points into s.a    */
   p = p + 3;                  /* Non-compliant - undefined, p points
                                  more than one beyond s.a               */
   use_uint16_ptr ( p );
   use_uint16 ( st.y + st.z );
}


void R_18_1 ( void )
{
   int32_t array [ 10 ] = { 0 };
   int32_t *ptr = get_int32_ptr ( );

   ( void ) f1 ( ptr, array );
   f2 ( );
   f3 ( );
}

/* end of R_18_01.c */
