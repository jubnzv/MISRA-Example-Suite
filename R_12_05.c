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
 * R.12.5
 *
 * The sizeof operator shall not have an operand which is a function
 * parameter declared as "array of type"
 */

#include "mc3_types.h"
#include "mc3_header.h"

static int32_t glbA[ ] = { 1, 2, 3, 4, 5 };

static int32_t fn_5 ( int32_t Ar[ 4 ] )
{
   /*
    * The following is non-compliant as it always gives the same answer,
    * irrespective of the number of members that appear to be in the array
    * (4 in this case), because A has type int32_t * and not int32_t[ 4 ].
    * As sizeof ( int32_t * ) is often the same as sizeof ( int32_t ),
    * numElements is likely to always have the value 1.
    */
   uint32_t numElements = sizeof ( Ar ) / sizeof ( int32_t ); /* Non-compliant */
   /*
    * The following is compliant as numElements_glbA will be given the
    * expected value of 5.
    */
   uint32_t numElements_glbA = sizeof ( glbA ) / sizeof ( glbA[ 0 ] );

   use_uint32 ( numElements +  numElements_glbA );

   return Ar[ 0 ] + glbA[ 0 ] ;
}

void R_12_5 ( void )
{
  int32_t loc_A[ 4 ] = { 1, 2, 3, 4 };

  int32_t retval;
  retval = fn_5 (loc_A );

  use_int32 ( retval + glbA[ 0 ] );

}

/* end of R_12_05.c */
