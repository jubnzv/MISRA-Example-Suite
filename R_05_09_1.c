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
 * R.5.9
 *
 * Identifiers that define objects or functions with internal linkage should be
 * unique
 */

#include "R_05_09.h"



static int32_t count;         /* "count" has internal linkage              */

static void foo9 (void)       /* "foo9" has internal linkage               */
{
   int16_t count;             /* Non-compliant - also breaks R.5.3         */
                              /* "count" has no linkage but clashes with an
                                 identifier with internal linkage          */

   int16_t index;             /* "index" has no linkage                    */

   index = get_int16 ( );
   use_int16 ( index );
   count = get_int16 ( );
   use_int16 ( count );
}

void bar1 (void)
{
   static int16_t count;      /* Non-compliant - also breaks R.5.3        */
                              /* "count" has no linkage but clashes with an
                                 identifier with internal linkage         */

   int16_t index;             /* Compliant - "index" is not unique
                                 but has no linkage                       */
   foo9 ( );

   index = get_int16 ( );
   use_int16 ( index );
   count = get_int16 ( );
   use_int16 ( count );
}


static void R_5_9_1 ( void )
{
   use_int32 ( count );
}

void R_5_9 ( void )
{
   R_5_9_1 ( );
   use_int32 ( count );
   foo9 ( );
   bar1 ( );
   R_5_9_2 ( );
}


/* End of R_05_09_1.c */


