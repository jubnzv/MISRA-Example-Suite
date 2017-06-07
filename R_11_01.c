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
 * R.11.1
 *
 * Conversions shall not be performed between a pointer to a function and any
 * other type
 */

#include "mc3_types.h"
#include "mc3_header.h"

#include <stddef.h> /* To obtain macro NULL */
/* Could also be stdio.h, stdlib.h and others in hosted environments */


typedef void ( *fp16 )( int16_t n );
typedef void ( *fp32 )( int32_t n );

static fp16 get_fp16 ( void )
{
   return &use_int16;
}


extern void f1 ( int16_t n );

void R_11_1 ( void )
{
   fp16 fp1 = NULL;        /* Compliant - exception */

   fp32 fp2 = ( fp32) fp1; /* Non-compliant - function pointer to
                                            different function pointer */

   if (fp2 != NULL)        /* Compliant - exception, also breaks R.14.3  */
   {
   }

   fp16 fp3 = ( fp16 ) 0x8000; /* Non-compliant  - integer to function pointer */

   fp16 fp4 = ( fp16 ) 1.0e6F; /* Non-compliant  -   float to function pointer */

   typedef fp16 ( *pfp16 ) ( void );
   pfp16 pfp1 = &get_fp16;

   (void) ( *pfp1 ( ) );   /* Compliant - exception */

   f1 ( 1 );                /* Compliant - exception - implicit conversion
                            * of f1 into pointer to function */
   fp16 fp5 = f1;           /* Compliant - exception */

}

/* end of R_11_01.c */
