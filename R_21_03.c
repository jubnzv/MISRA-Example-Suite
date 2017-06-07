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
 * R.21.3
 *
 * The memory allocation and deallocation functions of <stdlib.h> shall not be used
 */

#include "mc3_types.h"
#include "mc3_header.h"
#include <stdlib.h>

void R_21_3 ( void )
{
   char_t  * p ;

   p = ( char_t* ) malloc ( 11U );                  /* Non-compliant: use of malloc  */

   if ( p != NULL)
   {
     (void) realloc ( p, 20U );                     /* Non-compliant: use of realloc */
   }

   free ( p );                                      /* Non-compliant: use of free    */

   p = ( char_t* ) calloc (10, sizeof ( char_t ) ); /* Non-compliant: use of calloc */

   free ( p );                                      /* Non-compliant: use of free    */

}

/* end of R_21_03.c */

