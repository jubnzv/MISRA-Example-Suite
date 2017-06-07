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
 * R.14.4
 *
 * The controlling expression of an if-statement and the controlling expression 
 * of an iteration-statement shall have essentially Boolean type
 */

#include "mc3_types.h"
#include "mc3_header.h"


void R_14_4 ( void )
{
   const int32_t *p = get_int32_ptr ( );
   const int32_t *q = get_int32_ptr ( );
   bool_t flag = get_bool ( );
   int32_t   i = get_int32 ( );

   while ( p )           /* Non-compliant - p is a pointer */
   {
      p = get_int32_ptr ( );
   }

   while ( q != NULL )   /* Compliant */
   {
      q = get_int32_ptr ( );
   }

   while ( flag )       /* Compliant */
   {
      flag = get_bool ( );
   }

   if ( i )             /* Non Compliant */
   {
   }

   if ( i != 0 )        /* Compliant */
   {
   }

   while ( true )      /* Compliant, but breaks R.2.1  */
   {
   }

}

/* end of R_14_04.c */
