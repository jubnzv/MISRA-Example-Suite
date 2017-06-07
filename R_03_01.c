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
 * R.3.1
 *
 * The character sequences /* and // shall not be used within a comment
 */

#include "mc3_types.h"
#include "mc3_header.h"

void R_3_1 ( void )
{
   /* some comment, end comment marker accidentally omitted
   <<New Page>>
   Perform_Critical_Safety_Function(X);
   /* this comment is non-compliant */

  int16_t x;
  int16_t y = 3;
  int16_t z = 5;

   /* Following is Non-compliant */
   x = y // /*
         + z
         // */
       ;

   use_int16 ( x );
   use_int16 ( z );

}

/* end of R_03_01.c */
