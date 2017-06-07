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
 * R.18.2
 *
 * Subtraction between pointers shall only be applied to pointers that address 
 * elements of the same array
 */

#include "mc3_types.h"
#include "mc3_header.h"

void R_18_2 ( void )
{
   int32_t a1[ 10 ];
   int32_t a2[ 10 ];
   int32_t *p1 = &a1[ 1 ];
   int32_t *p2 = &a2[ 10 ];
   int32_t *ptr = get_int32_ptr ( );
   ptrdiff_t diff;

   diff = p1 - a1;          /* Compliant           */
   use_ptrdiff ( diff );

   diff = p2 - a2;          /* Compliant           */
   use_ptrdiff ( diff );

   diff = p1 - p2;          /* Non-compliant   */
   use_ptrdiff ( diff );

   diff = ptr - p1;         /* Non-compliant   */
   use_ptrdiff ( diff );

}

/* end of R_18_02.c */
