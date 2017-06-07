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
 * R.8.4
 *
 * A compatible declaration shall be visible when an object or function with
 * external linkage is defined
 */

/* Note: Extern only used in 1 file breaks R.8.7.
         Extern only used in 1 function breaks R.8.9
 */

#include "R_08_04.h"

extern int16_t count;
       int16_t count = 0;      /* Compliant */

extern uint16_t speed = 6000u; /* Non-compliant - no declaration prior to this definition */

uint8_t pressure = 101u;       /* Non-compliant - no declaration prior to this definition */


extern int32_t ext_val1;      /* Compliant - declaration            */
int32_t ext_val1 = 3;         /* followed by compatible definition  */

int32_t ext_val2;             /* Compliant - Tentative definition, treated as declaration */
int32_t ext_val2 = 3;         /* because followed by compatible definition                */

int32_t ext_val3;            /* Non-compliant - Tentative definition                      */
                             /* which becomes a definition, initialising ext_val3 to 0.   */


void func41 (void)
{
   /* Compliant */
   use_int16 ( count );
}

void func42 ( int16_t x, int16_t y )
{
   /* Compliant */
   use_int16 ( x );
   use_int16 ( y );
}

void func43 ( int16_t x, uint16_t y )
{
   /* Non-compliant - parameter types different - also constraint error and breaks Rule 1.1 */
   use_int16 ( x );
   use_uint16 ( y );
}

void func44 (void)
{
   /* Non-Compliant - no declaration  of func44 before this definition */
   use_uint8 ( pressure );
}

static void func45 (void)
{
   /* Compliant - rule does not apply to objects/functions with internal linkage */
   use_uint16 ( speed );
}

void R_8_4 ( void )
{
   func41 ( );
   func42 ( 3, 4 );
   func43 ( 4, 3U );
   func44 ( );
   func45 ( );

   use_int16 ( count );
   use_uint16 ( speed );
   use_uint8 ( pressure );
   use_int32 ( ext_val1 + ext_val2 + ext_val3 );
}


/* end of R_08_04.c */
