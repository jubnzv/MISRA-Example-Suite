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
 * R.2.1
 *
 * A project shall not contain unreachable code
 */

#include "R_02_01.h"


enum light next_light ( enum light c )
{
   enum light res = red;

   switch ( c )
   {
      case red:         res = red_amber; break;
      case red_amber:   res = green;     break;
      case green:       res = amber;     break;
      case amber:       res = red;       break;
      default:
      {
         /*
          * This default may or may not be reachable depending on the range of values held by
          * the parameter c.
          */
         error_handler ();
         break;
      }
   }

   return res;
   res = c;   /* Non-compliant - this statement is
               * certainly unreachable */
}


/* end of R_02_01_1.c */
