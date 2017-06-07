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
 * R.15.4
 *
 * There should be no more than one break or goto statement used to terminate 
 * any iteration statement
 */

#include "R_15_04.h"

#define LIMIT 100u

/* Note: All uses of goto also break R.15.1 */

void R_15_4 ( void )
{
   uint32_t x;
   uint32_t y;
   uint32_t z;

    for ( x = 0; x < LIMIT; ++x )
    {
      if ( ExitNow ( x ) )
      {
         break;   /* compliant - single exit from outer loop */
      }

      for ( y = 0; y < x; ++y )
      {
         if ( ExitNow ( LIMIT - y ) )
         {
            break;  /* compliant - single exit from inner loop */
         }
      }
    }


   for ( x = 0; x < LIMIT; ++x )
   {
      if ( BreakNow ( x ) )
      {
         break;
      }
      else if ( GotoNow ( x ) )
      {
         goto EXIT;   /* Non-compliant - break and goto in loop */
      }
      else
      {
         KeepGoing ( x );
      }
   }

EXIT: ;

   x = get_uint32 ( );
   y = get_uint32 ( );

   while ( x != 0u )
   {
      x = get_uint32 ( );

      if ( x == 1u )
      {
         break;
      }

      while ( y != 0u )
      {
         y = get_uint32 ( );

         if ( y == 1u )
         {
            goto L1;  /* Non-compliant (outer loop) Compliant (inner loop)   */
                      /* goto causes early exit of both inner and outer loop */
         }
      }
   }
   L1:
   z = x + y;

   use_uint32 ( z );

}


/* end of R_15_04.c */
