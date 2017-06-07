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
 * R.17.1
 *
 * The features of <stdarg.h> shall not be used
 */

#include "mc3_types.h"
#include "mc3_header.h"

#include <stdarg.h>

static void h ( va_list ap )        /* Non-compliant */
{
   float64_t y;

   y = va_arg ( ap, float64_t );    /* Non-compliant */

   use_float64 ( y );
}


static void f ( uint16_t n, ... )
{
   uint32_t x;

   va_list ap;                     /* Non-compliant */

   va_start ( ap, n );             /* Non-compliant */
   x = va_arg ( ap, uint32_t );    /* Non-compliant */
   use_uint32 ( x );

   h ( ap );

   /* undefined - ap is indeterminate because va_arg used in h ( ) */
   x = va_arg ( ap, uint32_t );   /* Non-compliant */

   use_uint32 ( x );
   /* undefined - returns without using va_end ( ) */
}


void R_17_1 ( void )
{
   /* undefined - uint32_t:double type mismatch when f uses va_arg( ) */
   f ( 1, 2.0, 3.0 );
}

/* end of R_17_01.c */

