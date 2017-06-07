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
 * D.4.11
 *
 * The validity of values passed to library functions shall be checked
 */

#include "mc3_types.h"
#include "mc3_header.h"

#include <limits.h>
#include <stdlib.h>


void D_4_11 ( void )
{
   int32_t c = get_int32 ( );
   int32_t d;

   if ( c > INT_MIN )
   {
       d = abs ( c );  /* Compliant - input range checked  */
   }
   else
   {
       d = INT_MAX;
   }
   use_int32 ( d );

   c = get_int32 ( );
   d = abs ( c );      /* Non-compliant - c may be negative */

   use_int32 ( c );
   use_int32 ( d );
}
/* end of D_04_11.c */
