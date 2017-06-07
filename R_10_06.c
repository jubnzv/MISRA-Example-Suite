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
 * R.10.6
 *
 * The value of a composite expression shall not be assigned to an object with 
 * wider essential type
 */

#include "mc3_types.h"
#include "mc3_header.h"

void R_10_6 ( void )
{
   uint8_t  u8a  = get_uint8 ( );

   uint16_t u16a = get_uint16 ( );
   uint16_t u16b = get_uint16 ( );
   uint16_t u16c;

   uint32_t u32a;
   uint64_t u64a;

   u16c = u16a + u16b;              /* Same essential type */
   use_uint16 ( u16c );
   u32a = ( uint32_t ) u16a + u16b; /* Cast causes addition in uint32_t */
   use_uint32 ( u32a );

   u32a = u16a + u16b;               /* Non-compliant - Implicit conversion on assignment  */
   use_uint32 ( u32a );
   use_uint32 ( u16a + u16b );       /* Non-compliant - Implicit conversion of fn argument */

   u32a = ++u8a;                     /* Compliant - but breaks R.13.3 */
   use_uint32 ( u8a );
   use_uint32 ( u32a );

   u8a = ~u8a;                       /* Compliant  */
   u16a = ~u8a;                      /* Non-compliant - ~ is a composite operator */
   use_uint16 ( u16a );

   u16a = ~ ( uint16_t ) u8a;       /* Compliant  */
   use_uint16 ( u16a );

   u16a = ( uint8_t ) ( ~ u8a );    /* Compliant  */
   use_uint16 ( u16a );

   u64a = + ( u32a * u32a );        /* Non-compliant - unary + operator */
                                    /* on composite expression          */
   use_uint64 ( u64a );

   u64a = + u32a;                   /* Compliant - unary + operator    */
                                    /* on non-composite expression     */
   use_uint64 ( u64a );
}

/* end of R_10_06.c */
