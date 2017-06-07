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
 * R.7.4
 *
 * A string literal shall not be assigned to an object unless the object's
 * type is "pointer to const-qualified char"
 */

#include "R_07_04.h"

extern void f1 ( char *s1 );

extern void f2 ( const char *s2 );

static void g2 ( void )
{
   f1 ( "string" );         /* Non-compliant */
   f2 ( "string" );         /* Compliant     */
}

static char *name1 ( void )
{
   return ( "MISRA" );     /* Non-compliant */
}

static const char *name2 ( void )
{
   return ( "MISRA" );     /* Compliant*/
}

void R_7_4 ( void )
{
   char *s = "string";                /* Non-compliant */

   const volatile char *p = "string"; /* Compliant     */

   "0123456789"[0] = '*';             /* Non-compliant */

   g2 ( );
   ( void ) name1 ( );
   ( void ) name2 ( );

   use_const_char_ptr ( s );
   use_const_volatile_char_ptr ( p );
}

/* end of R_07_04.c */
