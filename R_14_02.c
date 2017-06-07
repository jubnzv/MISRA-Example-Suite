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
 * R.14.2
 *
 * A for loop shall be well-formed
 */


#include "mc3_types.h"
#include "mc3_header.h"

static void set_val ( int32_t *ind )
{
    *ind = 0;
}


void R_14_2 ( void )
{
   bool_t flag = false;
   bool_t C = get_bool ( );

   for ( int16_t i = 0; ( i < 5 ) && !flag; i++ )
   {
     if ( C )
     {
       flag = true; /* Compliant - allows early termination of loop */
     }

     i = i + 3;     /* Non-compliant - altering the loop counter */
   }

   int32_t index;
   for ( set_val( &index );  index < 10; index++ ) /* compliant - index assigned a value within set_val */
   {
       use_int32( index );
   }

   use_bool ( flag );
}

/* end of R_14_02.c */

