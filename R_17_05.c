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
 * R.17.5
 *
 * The function argument corresponding to a parameter declared to have an array 
 * type shall have an appropriate number of elements
 */


#include "mc3_types.h"
#include "mc3_header.h"


/* Intent is that function does not access outside of [0]..[3]   */
static void fn1( const int32_t array1[ 4 ] )
{
   use_int32 ( array1[ 3 ] );
}

/* Intent is that function handles arrays of any size               */
static void fn2( const int32_t array2[ ] )
{
   use_int32 ( array2 [ 0 ] );
}


static void fn ( const int32_t *ptr  )
{
   int32_t arr3 [ 3 ] = { 1, 2, 3 };
   int32_t arr4 [ 4 ] = { 0, 1, 2, 3 };

   fn1 ( arr4 );     /* Compliant - size of array matches the prototype */

   fn1 ( arr3 );     /* Non-compliant - size of array does not match prototype */

   if ( ptr != NULL )
   {
      fn1 ( ptr );   /* Compliant only if ptr points to at least 4 elements */
   }

   fn2 ( arr4 );    /* Compliant */

   if ( ptr != NULL )
   {
      fn2 ( ptr );  /* Compliant */
   }
}

void R_17_5 ( void )
{
   int32_t *ptr = get_int32_ptr ( );

   fn ( ptr );
}


/* end of R_17_05.c */
