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
 * R.21.2
 *
 * A reserved identifier or reserved macro name shall not be declared
 */

#include "mc3_types.h"
#include "mc3_header.h"

#include <stddef.h>


static float64_t _BUILTIN_sqrt ( float64_t x )  /* Non-compliant, also breaks R.20.1  */
{
   return x * x;
}

#include <math.h>
/* break R.20.1 */

extern void *memcpy (void * restrict s1,
                     const void * restrict s2, /* also breaks R.8.14   */
                     size_t n);                /* Non-compliant        */


void R_21_2 ( void )
{
   float64_t x = sqrt ( ( float64_t ) 2.0 ); /* sqrt may not behave as defined in the standard */

   x = _BUILTIN_sqrt( x );
   use_float64 ( x );

}

/* end of R_21_02.c */

