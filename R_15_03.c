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
 * R.15.3
 *
 * Any label referenced by a goto statement shall be declared in the same 
 * block, or in a block enclosing the goto statement
 */

#include "mc3_types.h"
#include "mc3_header.h"

/* Note: All uses of goto also break R.15.1 */

static void f1 ( int32_t a )
{
   if ( a <= 0 )
   {
     goto L2;            /* Non-compliant */
   }

   goto L1;              /* Compliant     */

   if ( a == 0 )         /* breaks R.2.1  */
   {
     goto L1;            /* Compliant     */
   }

   goto L2;              /* Non-compliant */

 L1:
   if ( a > 0 )          /* breaks R.14.3 */
   {
   L2:
     ;
   }

   use_int32 ( a );
}

void R_15_3 ( void )
{
  int32_t x = get_int32 ( );
  int32_t y = get_int32 ( );

  switch ( x )
  {
     case 0:
        if ( x == y )
        {
           goto L1;            /* Non-compliant */
        }
        break;
     case 1:
        y = x;
 L1:
        ++x;
        break;
     default :
        /* no action */
        break;
  }

  f1 ( x + y );

}

/* end of R_15_03.c */
