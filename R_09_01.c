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
 * R.9.1
 *
 * The value of an object with automatic storage duration shall not be read
 * before it has been set
 */

#include "mc3_types.h"
#include "mc3_header.h"


static void f ( bool_t b, uint16_t *p )
{
  if ( b )
  {
     *p = 3U;
  }
}

static void g (void)
{
   uint16_t u;       /* Non-compliant declaration */

   f ( false, &u );

   if ( u == 3U )    /* Non-compliant use - "u" has not been assigned a value. */
   {
      use_uint16 ( u );
   }
}


static void jmp_over_init ( void )
{
   goto  L1;                  /* violates R.15.1 */
     uint16_t x = 10u;
  L1:
     x = x + 1u;      /* Non-compliant - x has not been been assigned a value */
     use_uint16 ( x );
}


void R_9_1 ( void )
{
   bool_t b = get_bool ( );
   uint16_t val = 3u;

   f( b, &val );
   use_uint16 ( val );

   g ( );
   jmp_over_init ( );
}

/* end of R_09_01.c */
