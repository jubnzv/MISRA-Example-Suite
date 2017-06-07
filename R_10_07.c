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
 * R.10.7
 *
 * If a composite expression is used as one operand of an operator in which the 
 * usual arithmetic conversions are performed then the other operand shall not 
 * have wider essential type
 */

#include "mc3_types.h"
#include "mc3_header.h"

void R_10_7 ( void )
{
   uint16_t u16a = get_uint16 ( );
   uint16_t u16b = get_uint16 ( );

   uint32_t u32a = get_uint32 ( );
   uint32_t u32b = get_uint32 ( );

   u32a =   u32a * u16a   + u16b;               /* No composite conversion, but breaks R.12.1 */
   u32a = ( u32a * u16a ) + u16b;               /* No composite conversion */
   u32a = u32a * ( ( uint32_t ) u16a + u16b );  /* Cast means no conversion */
   u32a += ( u32b + u16b );                     /* No composite conversion */

   u32a = u32a * ( u16a + u16b ); /* Non-compliant - Implicit conversion of ( u16a + u16b ) */
   u32a += ( u16a + u16b );       /* Non-compliant - Implicit conversion of ( u16a + u16b ) */

   use_uint32 ( u32a );
}

/* end of R_10_07.c */
