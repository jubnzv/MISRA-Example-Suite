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
 * R.20.5
 *
 * #undef should not be used
 */

#include "mc3_types.h"
#include "mc3_header.h"

#define QUALIFIER volatile

#undef QUALIFIER           /* Non-compliant */

#ifdef QUALIFIER
static void f ( QUALIFIER int32_t p )
#else
static void f5 ( int32_t p )
#endif
{
   while ( p != 0 )
   {
      p = get_int32 ( ); /* Breaks R.17.8 */
   }
}



void R_20_5 ( void )
{
  int32_t v = 0;
  f5 ( v );
}


/* end of R_20_05.c */

