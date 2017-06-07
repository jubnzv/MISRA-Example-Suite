/*
 * Release: 2016-11-01
 *
 * Example from MISRA C:2012 AMD1 ( THIS IS NOT A TEST SUITE )
 *
 * Copyright HORIBA MIRA Limited.
 *
 * See file READ_ME.txt for full copyright, license and release instructions.
 */

/*
 * R.22.10
 *
 * The value of errno shall only be tested when the last function to be called
 * was an errno-setting-function
 *
 */

#include "mc3_types.h"
#include "mc3_header.h"

#include <errno.h>
#include <stdlib.h>

/* Note: atof may or may not set errno when an error is detected
 *       strtod is an errno-setting-function.
 */



void R_22_10 ( void )
{
   float64_t f64a;
   float64_t f64b;

   errno = 0;

   f64a = atof ( "A.12" );

   if ( 0 == errno )                /* Non-compliant */
   {
     /* f64a may not have a valid value in here.      */
      use_float64 ( f64a );
   }


   errno = 0;

   f64b = strtod ( "A.12", NULL );

   if ( 0 == errno )                /* Compliant     */
   {
     /* f64b will have a valid value in here.         */
     use_float64 ( f64b );
   }

}


/* end of R_22_10.c */

