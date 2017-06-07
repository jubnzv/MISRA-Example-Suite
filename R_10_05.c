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
 * R.10.5
 *
 * The value of an expression should not be cast to an inappropriate essential type
 */

#include "mc3_types.h"
#include "mc3_header.h"

/* Defined in mc3_types.h                                 */
/* typedef enum enum_tag { ENUM_0, ENUM_1, ENUM_2 } enum_t */

void R_10_5 ( void )
{
   char cha;
   enum_t ena = ENUM_1;
   enum_t enc;
   int32_t si;

   bool_t bna = ( bool_t ) false;  /* Compliant - C99 'false' is essentially Boolean */
   use_bool ( bna );
   si = ( int32_t ) 3U;       /* Compliant */
   use_int32( si );
   bna = ( bool_t ) 0;        /* Compliant  - by exception */
   use_bool( bna );
   bna = ( bool_t ) 3U;       /* Non-compliant  */
   use_bool(bna);
   bna = ( bool_t ) ENUM_0;   /* Non-compliant - ENUM_0 has essentially enum type */
   use_bool(bna);

   si = ( int32_t ) ena;     /* Compliant */
   use_int32( si );
   enc = ( enum_t ) 3;       /* Non-compliant */
   use_enum( enc );
   cha = ( char ) enc;       /* Compliant */
   use_char ( cha );

}

/* end of R_10_05.c */
