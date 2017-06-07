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
 * R.8.9
 *
 * An object should be defined at block scope if its identifier only appears in
 * a single function
 */

#include "mc3_types.h"
#include "mc3_header.h"

#define N 10

static void func9 ( void )
{
   int32_t i9;                        /* Compliant */
   for ( i9 = 0; i9 < N; ++i9 )
   {
      use_int32 ( i9 );
   }
}


static uint32_t count9 ( void )
{
   static uint32_t call_count = 0;   /* Compliant */
   ++call_count;
   return call_count;
}


static int32_t should_be_local;      /* Non-compliant */


#define MACHINE1 0
static int32_t x_9;   /* Non-compliant */

static void fn_91 ( void )
{
   x_9 = 3;    /* After pre-processing, x_9 is only used in this function */
}

static int32_t fn_92 ( void )
{
#if ( MACHINE1 )
   return x_9;
#else
   return 0;
#endif
}



void R_8_9 ( void )
{
   should_be_local = get_int32 ( );
   use_int32 ( should_be_local );

   func9 ( );
   ( void ) count9( );

   fn_91 ( );
   ( void ) fn_92 ( );

}

/* end of R_08_09.c */
