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
 * R.13.5
 *
 * The right hand operand of a logical && or || operator shall not contain
 * persistent side-effects
 */


#include "R_13_05.h"


static uint16_t f5 ( uint16_t y )
{
   uint16_t temp;
   /* This side effect is not persistent as seen by the caller */
   temp = y & 0x8080U;

   return temp;
}

static uint16_t h5 ( uint16_t y )
{   /* function has persistent side_effect as seen by the caller */
   static uint16_t temph = 0;

   temph = y + temph;

   return temph;
}

static uint16_t k5 ( uint16_t y )
{   /* function has persistent side_effect as seen by the caller
       regardless of the value of y
     */
   static uint16_t tempk = 0;

   if ( y > 10U )
   {
     tempk = y + tempk;
   }

   return tempk;
}


static void g5 ( bool_t ishigh, uint16_t x, uint16_t a )
{
   /* Compliant - f5( ) has no persistent side effects */
   if ( ishigh && ( a == f5 ( x ) ) )
   {
   }

   /* Non-compliant - h5( ) has a persistent side effect */
   if ( ishigh && ( a == h5 ( x ) ) )
   {
   }

   /* Non-compliant - k5( ) has a persistent side effect */
   if ( ishigh && ( a == k5 ( 5U ) ) )
   {
   }
}


uint16_t global = 0u;

void R_13_5 ( void )
{
    uint16_t          x = get_uint16 ( );
    volatile uint16_t v = get_uint16 ( );
    fnptr fp = persist;   /* updates global */

    if ( ( x == 0u ) || ( v == 1u ) )      /* Non-compliant */
    {
    }

    if ( ( fp != NULL ) && ( *fp ) ( 0 ) ) /* Non-compliant, also breaks R.14.3 */
    {
    }

    use_uint16 ( v );

    bool_t flag = persist ( x );
    g5 ( flag, x, x );

    use_uint16 ( global );
}

/* end of R_13_05.c */
