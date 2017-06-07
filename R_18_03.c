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
 * R.18.3
 *
 * The relational operators >, >=, < and <= shall not be applied to objects of 
 * pointer type except where they point into the same object
 */

#include "mc3_types.h"
#include "mc3_header.h"

static void f3_1 ( void )
{
   int32_t a1[ 10 ] = { 0 };
   int32_t a2[ 10 ] = { 0 };
   int32_t *p1 = a1;

   if ( p1 < a1 ) /* Compliant, but breaks Rule 14.3 */
   {
   }
   if ( p1 < a2 ) /* Non-compliant */
   {
      use_int32 ( a2[ 0 ] );
   }

   use_int32 ( a1[ 0 ] );

}


struct limits
{
   int32_t lwb;
   int32_t upb;
};

static void f3_2 ( void )
{
   struct limits limits_1 = { 2, 5 };
   struct limits limits_2 = { 10, 5 };

   if ( &limits_1.lwb <= &limits_1.upb ) /* Compliant , but breaks Rule 14.3 */
   {
   }

   if ( &limits_1.lwb > &limits_2.upb ) /* Non-Compliant */
   {
   }

   use_int32 ( limits_1.lwb + limits_1.upb + limits_2.lwb + limits_2.upb );
}


void R_18_3 ( void )
{
   f3_1 ( );
   f3_2 ( );
}

/* end of R_18_03.c */
