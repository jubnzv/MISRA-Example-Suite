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
 * R.12.2
 *
 * The right hand operand of a shift operator shall lie in the range zero to 
 * one less than the width in bits of the essential type of the left hand 
 * operand
 */


#include "mc3_types.h"
#include "mc3_header.h"

void R_12_2 ( void )
{
    uint8_t  u8a = get_uint8 ( );
    uint16_t u16a;
    uint64_t u64a;

    u8a = u8a << 7   ;             /* Compliant */
    use_uint8 ( u8a );

    u8a = u8a << 8;                /* Non-compliant */
    use_uint8 ( u8a );

    u16a = ( uint16_t ) u8a << 9;    /* Compliant */
    use_uint16 ( u16a );

    u8a = 1u << 10u;               /* Non-compliant */
    use_uint8 ( u8a );

    u16a = ( uint16_t )1u << 10u;  /* Compliant     */
    use_uint16 ( u16a );

    u64a = 1UL << 10u;             /* Compliant     */
    use_uint64 ( u64a );

}
/* end of R_12_02.c */
