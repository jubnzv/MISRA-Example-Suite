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
 * R.20.12
 *
 * A macro parameter used as an operand to the # or ## operators, which is 
 * itself subject to further macro replacement, shall only be used as an 
 * operand to these operators
 */

/* Note: The use of ## violates R.20.10         */

#include "mc3_types.h"
#include "mc3_header.h"


#define AA        0xffff
#define BB( x )   ( x ) + wow ## x   /* Non-compliant   */

static void f12 ( void )
{
   int32_t wowAA = 0;

   /* Expands as wowAA = ( 0xffff ) + wowAA; */
   wowAA = BB ( AA );

   use_int32 ( wowAA );
}


#define SCALE( X ) ( ( X ) * X ## _scale ) /* Compliant */

void R_20_12 ( void )
{
   int32_t speed;
   int32_t speed_scale;
   int32_t scaled_speed;

   speed = get_int32 ( );
   speed_scale  = get_int32 ( );

   /* expands to scaled_speed = ( ( speed ) * speed_scale ); */
   scaled_speed = SCALE ( speed );

   use_int32 ( scaled_speed );

   f12 ( );
}
/* end of R_20_12.c */
