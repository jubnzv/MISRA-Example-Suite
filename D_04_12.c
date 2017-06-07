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
 * D.4.12
 *
 * Dynamic memory allocation shall not be used
 */

#include "mc3_types.h"
#include "mc3_header.h"

#include <stdlib.h>

static void f ( void )
{
   char *p = ( char * ) malloc ( 10 );  /* Non-compliant, also breaks R.21.3 */
   char *q;

   free ( p );                          /* Non-compliant, also breaks R.21.3 */
   q = p;                               /* Breaks R.22.2  Undefined behaviour - value of p is indeterminate */
   use_char_ptr ( q );

   p = ( char * ) malloc ( 20 );        /* Non-compliant, also breaks R.21.3 */
   free ( p );                          /* Non-compliant, also breaks R.21.3 */

   p = NULL; /* Assigning NULL to freed pointer makes it determinate, breaks R.2.2 */
}

void D_4_12 ( void )
{
   f ( );
}
/* end of D_04_12.c */
