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
 * R.5.9
 *
 * Identifiers that define objects or functions with internal linkage should be
 * unique
 */

#include "R_05_09.h"


static int8_t count;          /* Non-compliant - "count" has internal
                                 linkage but clashes with other
                                 identifiers of the same name          */

static void foo9 ( void )     /* Non-compliant - "foo9" has internal
                                 linkage but clashes with a function
                                 of the same name                      */
{
   int32_t index;             /* Compliant - both "index" and "nbytes" */
   int16_t nbytes;            /* are not unique but have no linkage    */

   index = get_int32 ( );
   use_int32 ( index );
   nbytes = get_int16 ( );
   use_int16 ( nbytes );
   count = get_int8 ( );
   use_int8 ( count );
}


static void bar2 ( void )
{
   static uint8_t nbytes;     /* Compliant - "nbytes" is not unique
                                 but has no linkage so the storage class is irrelevant   */
   nbytes = get_uint8 ( );
   use_uint8 ( nbytes );
}


void R_5_9_2 ( void )
{
   use_int8 ( count );
   foo9 ( );
   bar2 ( );
   bar1 ( );
}

/* End of R_05_09_2.c */


