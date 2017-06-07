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
 * R.10.8
 *
 * The value of a composite expression shall not be cast to a different 
 * essential type category or a wider essential type
 */

#include "mc3_types.h"
#include "mc3_header.h"


void R_10_8 ( void )
{
   uint32_t u32a = get_uint32 ( );
   uint32_t u32b = get_uint32 ( );
   uint16_t u16a;
   uint16_t u16b = get_uint16 ( );
   int32_t s32a = get_int32 ( );
   int32_t s32b = get_int32 ( );

   u16a = ( uint16_t ) ( u32a + u32b ); /* Compliant */
   use_uint16 ( u16a );
   u16a = ( uint16_t ) ( s32a + s32b ); /* Non-compliant - different essential
                                         * type category */
   use_uint16 ( u16a );

   u16a = ( uint16_t ) s32a;            /* Compliant - s32a is not composite */
   use_uint16 ( u16a );
   u32a = ( uint32_t ) ( u16a + u16b ); /* Non-compliant - cast to wider
                                         * essential type */
   use_uint32 ( u32a );

   u32a = ( uint32_t ) ( uint16_t ) ( u16a + u16b );
                                /* Compliant - uint32_t cast is
                                 * not on a composite expression*/
   use_uint32 ( u32a );
}

/* end of R_10_08.c */
