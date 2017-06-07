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
 * R.5.1
 *
 * External identifiers shall be distinct
 */

#include "R_05_01.h"

int32_t ABC;
int32_t ABC = 0;  /* Non-compliant  */

static void R_5_1_2_1 ( void )
{
    ABC = get_int32 ( );
}

void R_5_1_2 ( void )
{
   R_5_1_2_1 ( );
   use_int32 ( ABC );

   use_int32 ( engine_exhaust_gas_temperature_raw );
   use_int32 ( engine_exhaust_gas_temperature_scaled );
   use_int32 ( engine_exhaust_gas_temp_raw );
   use_int32 ( engine_exhaust_gas_temp_scaled );
}

/* end of R_05_01_2.c */

