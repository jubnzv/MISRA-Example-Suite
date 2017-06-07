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
 * R.11.5
 *
 * A conversion should not be performed from pointer to void into pointer to object
 */

#include "mc3_types.h"
#include "mc3_header.h"

void R_11_5 ( void )
{
   uint32_t *p32 = get_uint32_ptr ( );
   void     *p;
   uint16_t *p16;

   p   = p32;               /* Compliant - pointer to uint32_t -> pointer to void */
   p16 = p;                 /* Non-compliant */

   p   = ( void * ) p16;    /* Compliant     */

   p32 = ( uint32_t * ) p;  /* Non-compliant */

   use_uint32_ptr ( p32 );

}
/* end of R_11_05.c */

