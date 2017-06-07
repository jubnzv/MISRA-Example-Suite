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
 * R.5.3
 *
 * An identifier declared in an inner scope shall not hide an identifier 
 * declared in an outer scope
 */


#include "R_05_03.h"

static void fn1 ( void )
{
   int16_t i;
   {
      int16_t i;                       /* Non-compliant  */

      i = 3;           /* Could be confusing as to which "i" this refers */

      use_int16 ( i );
   }
}




static int16_t xyz = 0;                /* Declare an object "xyz" */

static void fn2 ( struct astruct xyz ) /* Non-compliant - outer "xyz" is now hidden by parameter name */
                                       /* Also breaks R.5.9 */
{
   g ( &xyz );
}


static uint16_t speed;

static void fn3 ( void )
{
   typedef float32_t speed;            /* Non-compliant - type hides object */
                                       /* Also breaks R.5.6, R.5.9 */
   speed sp = 1.0f;

   use_float32 ( sp );
}



void R_5_3 ( void )
{
   struct astruct loc_st = { 0 };
   fn1 ( );
   fn2 ( loc_st );
   fn3 ( );
}

/* end of R_05_03.c */
