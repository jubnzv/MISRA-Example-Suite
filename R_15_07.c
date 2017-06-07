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
 * R.15.7
 *
 * All if ... else if constructs shall be terminated with an else statement
 */

#include "R_15_07.h"


void R_15_7 ( void )
{
   bool_t flag_1 = get_bool ( );
   bool_t flag_2 = get_bool ( );

   if ( flag_1 )
   {
      action_f1 ( );
   }
   else if ( flag_2 )
   {
      action_f2 ( );
   }
   /* Non-compliant */

   if ( flag_1 )
    {
       action_f1 ( );
    }
    else if ( flag_2 )
    {
       action_f2 ( );
    }
    else
    {
       ; /* No action required - ; is optional */
    }

}

/* end of R_15_07.c */
