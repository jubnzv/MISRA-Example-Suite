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
 * R.15.5
 *
 * A function should have a single point of exit at the end
 */

#include "mc3_types.h"
#include "mc3_header.h"

#define MAX 255u

static bool_t f ( uint16_t n, const char *p )
{
   if ( n > MAX )
   {
      return false;   /* Non-compliant */
   }

   if ( p == NULL )
   {
      return false;  /* Non-compliant */
   }

   return true;
}


void R_15_5 ( void )
{
   uint16_t n = get_uint16 ( );
   char *p = get_char_ptr ( );

   ( void ) f ( n, p );
}
/* end of R_15_05.c */
