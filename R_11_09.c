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
 * R.11.9
 *
 * The macro NULL shall be the only permitted form of integer null pointer constant
 */

#include "mc3_types.h"
#include "mc3_header.h"

#include <stddef.h>  /* To obtain macro NULL */
/* Could also be stdio.h, stdlib.h and others in hosted environments */


#define MY_NULL_1 0
#define MY_NULL_2 ( void * ) 0
#define MY_NULL_3 NULL

extern void f9 ( uint8_t *p );

void R_11_9 ( void )
{
   int32_t *p1 = 0;              /* Non-compliant */
   int32_t *p2 = ( void * ) 0;   /* Compliant     */
   int32_t *p3 = MY_NULL_3;      /* Compliant     */

   if ( p1 == MY_NULL_1 )   /* Non-compliant - also breaks R.14.3 */
   {
   }
   if ( p2 == MY_NULL_2 )   /* Compliant - but breaks R.14.3 */
   {
   }

   f9 ( NULL );             /* Compliant for any conforming definition of
                             * NULL, such as:
                             *       0
                             *       (void *)0
                             *       (((0)))
                             *       (((1 - 1)))
                             */
}

/* end of R_11_09.c */
