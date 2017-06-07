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
 * R.5.5
 *
 * Identifiers shall be distinct from macro names
 */

#include "mc3_types.h"
#include "mc3_header.h"

/*             1234567890123456789012345678901*********          Characters */
#define        low_pressure_turbine_temperature_1  lp_tb_temp_1
static int32_t low_pressure_turbine_temperature_2;               /* Non-compliant */

static void used_id ( void )
{
   use_int32 ( low_pressure_turbine_temperature_2 );
}


#define Sum( x, y ) ( ( x ) + ( y ) )      /* breaks D.4.9 and R.2.5 */

#define NextSum( x, y ) ( ( x ) + ( y ) )  /* breaks D.4.9 */

void R_5_5 ( void )
{
   int16_t Sum = 3;                    /* Non-compliant */
   int16_t x = NextSum ( 1, 2 );       /* Compliant     */

   use_int16 ( x + Sum );

   int32_t lp_tb_temp_1 = 3;
   use_int32 ( low_pressure_turbine_temperature_2 + low_pressure_turbine_temperature_1 );
   used_id ( );
}

/* end of R_05_05.c */
