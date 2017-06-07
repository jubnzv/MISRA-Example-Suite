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
 * R.15.2
 *
 * The goto statement shall jump to a label declared later in the same function
 */

#include "mc3_types.h"
#include "mc3_header.h"


/* Note: All uses of goto also break R.15.1 */

void R_15_2 ( void )
{
   int32_t j = 0;

   L1:
      ++j;

      if ( 10 == j )
      {
         goto L2;       /* Compliant     */
      }

      goto L1;          /* Non-compliant */

   L2:
      ++j;

   use_int32 ( j );

}

/* end of R_15_02.c */
