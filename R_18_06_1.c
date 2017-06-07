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
 * R.18.6
 *
 * The address of an object with automatic storage shall not be copied to 
 * another object that persists after the first object has ceased to exist
 */

#include "R_18_06.h"

static int8_t *func ( void )
{
   int8_t local_auto;
   return &local_auto; /* Non-compliant - &local_auto is indeterminate
                        * when func returns */
}


uint16_t *sp;

static void g ( uint16_t *p )
{
   sp = p; /* Non-compliant - address of f's parameter u
            * copied to static sp */
}

static void f ( uint16_t u )
{
   g ( &u );
}


static void h ( void )
{
   static uint16_t *q;
   uint16_t x = 0u;
   q = &x; /* Non-compliant - &x stored in object with
            * greater lifetime */
}


void R_18_6 ( void )
{
   int8_t *res = func ( );
   use_int8_ptr( res );

   f ( 3u );
   h ( );

   R_18_6_2 ( );
}


/* end of R_18_06_1.c */
