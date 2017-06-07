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
 * R.13.6
 *
 * The operand of the sizeof operator shall not contain any expression which 
 * has potential side-effects
 */

#include "mc3_types.h"
#include "mc3_header.h"

static void f6 ( int32_t n )
{
   volatile uint32_t v = get_uint32 ( );
   size_t s;

    s = sizeof ( int32_t [ n ] );                       /* Compliant, but breaks R.18.8 */
    use_sizet ( s );
    s = sizeof ( int32_t [ n++ ] );                     /* Non-compliant, also breaks R.18.8  */
    use_sizet ( s );
    s = sizeof ( void ( *[ n ] ) ( int32_t a[ v ] ) );  /* Non-compliant, also breaks R.18.8  */
    use_sizet ( s );

    use_int32 ( n );
    use_uint32 ( v );
}

void R_13_6 ( void )
{
   volatile int32_t i;
            int32_t j;
            size_t  s;

   s = sizeof ( j );              /* Compliant              */
   use_sizet(s);
   s = sizeof ( j++ );            /* Non-compliant          */
   use_sizet(s);
   s = sizeof ( i );              /* Compliant - exception  */
   use_sizet(s);
   s = sizeof ( int32_t );        /* Compliant              */
   use_sizet(s);

   f6 ( 3 );
}



/* end of R_13_06.c */
