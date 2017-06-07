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
 * R.15.6
 *
 * The body of an iteration-statement or a selection-statement shall be a 
 * compound statement
 */

#include "R_15_06.h"

void R_15_6 ( void )
{
   bool_t flag = get_bool();
   bool_t flag_1 = get_bool();
   bool_t flag_2 = get_bool();
   bool_t data_available = get_bool();

   while ( data_available )
      data_available = process_data ( );        /* Non-compliant */

   if ( flag_1 )
       if ( flag_2 )           /* Non-compliant */
          action_1 ( );        /* Non-compliant */
   else
       action_2 ( );           /* Non-compliant */


   if ( flag_1 )
   {
      action_1 ( );
   }
   else if ( flag_2 )          /* Compliant by exception */
   {
      action_2 ( );
   }
   else
   {
      ;  /* no action */
   }

   while ( flag );             /* Non-compliant */
   {
      flag = fn ( );
      use_bool ( flag );
   }

   while ( !data_available )
   {
      data_available = process_data ( );
   }

}
/* end of R_15_06.c */
