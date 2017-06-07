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
 * R.13.2
 *
 * The value of an expression and its persistent side-effects shall be the same
 * under all permitted evaluation orders
 */


#include "R_13_02.h"


static struct_fn_ptr g2 ( struct_fn **hn_ptr )
{
   ( *hn_ptr )++;
   return *hn_ptr;
}



#define COPY_ELEMENT( index ) ( b[( index )] = c[( index )] )  /* violates D.4.9 */


void R_13_2 ( void )
{
   uint16_t i = get_uint16 ( );
   uint16_t b[ 10 ];
   uint16_t c[ 10 ] = { 0u };

   COPY_ELEMENT ( i++ );     /* Non-compliant - i is modified twice and also read  */
                             /* Also breaks R.13.3                                 */
   use_uint16 ( b[ i ] );

   uint16_t t;
   t = v1 + v2;              /* Non-compliant - read order of v1 and v2 unspecified */
   use_uint16 ( t );

   volatile uint8_t PORT = get_uint8 ( );
   PORT = PORT & 0x80u;      /* Compliant - PORT is read and modified               */
   use_uint8 ( PORT );

   i = 0;
   f ( i++, i );            /* Non-compliant - order of evaluation unspecified     */
                            /* Also breaks R.13.3                                  */
   use_uint16 ( i );

   struct_fn * p = get_struct_fn_ptr ( );
   p->fn ( g2 ( &p ) );     /* Non-compliant  */
}


/* end of R_13_02.c */
