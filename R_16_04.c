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
 * R.16.4
 *
 * Every switch statement shall have a default label
 */

#include "mc3_types.h"
#include "mc3_header.h"

enum Colours { RED, GREEN, BLUE };

static enum Colours get_colour ( void )
{
   int32_t value = get_int32 ( );
   return (enum Colours) value;   /* breaks R.10.5 */
}


void R_16_4 ( void )
{
   int16_t x = get_int16 ( );
   int16_t errorflag = 0;

   switch ( x )
   {
      case 0:
         ++x;
         break;
     case 1:
     case 2:
         break;
                   /* Non-compliant - default label is required */
   }
   use_int16 ( x );
   x = get_int16 ( );

   switch ( x )
   {
      case 0:
         ++x;
         break;
      case 1:
      case 2:
         break;
      default:     /* Compliant - default is the final label */
        errorflag = 1;
        break;
   }
   use_int16 ( x + errorflag );


   enum Colours colour = get_colour ( );
   enum Colours next = RED;

   switch ( colour )
   {
      case RED :
         next = GREEN;
         break;
      case GREEN :
         next = BLUE;
         break;
      case BLUE :
         next = RED;
         break;
         /* Non-compliant - no default label.
          * Even though all values of the enumeration are
          * handled there is no guarantee that colour takes
          * one of those values */
   }

   use_int32 ( ( int32_t ) next );
}

/* end of R_16_04.c */
