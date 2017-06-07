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
 * R.11.4
 *
 * A conversion should not be performed between a pointer to object and an 
 * integer type
 */

#include "mc3_types.h"
#include "mc3_header.h"

void R_11_4 ( void )
{
   uint8_t  *PORTA = ( uint8_t * ) 0x0002;  /* Non-compliant */
   uint16_t *p = get_uint16_ptr ( );

   int32_t  addr = ( int32_t ) &p;          /* Non-compliant */
   uint8_t  *q   = ( uint8_t * ) addr;      /* Non-compliant */
   bool_t    b   = ( bool_t ) p;            /* Non-compliant */

   enum etag { A, B } e = ( enum etag ) p;  /* Non-compliant */

   use_uint8_ptr( q );
   use_uint8_ptr( PORTA );
   use_bool ( b );
   if ( e == A )
   {
   }
}
/* end of R_11_04.c */

