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
 * R.5.1
 *
 * External identifiers shall be distinct
 */

#include "R_05_01.h"


/*      1234567890123456789012345678901********* Characters */
int32_t engine_exhaust_gas_temperature_raw;
int32_t engine_exhaust_gas_temperature_scaled; /* Non-compliant */

/*      1234567890123456789012345678901********* Characters */
int32_t engine_exhaust_gas_temp_raw;
int32_t engine_exhaust_gas_temp_scaled; /* Compliant */

extern int32_t abc;
int32_t abc = 0;


static void R_5_1_1 ( void )
{
   engine_exhaust_gas_temperature_raw = get_int32 ( );
   engine_exhaust_gas_temperature_scaled = get_int32 ( );
   engine_exhaust_gas_temp_raw = get_int32 ( );
   engine_exhaust_gas_temp_scaled = get_int32 ( );
   abc = get_int32 ( );
}


void R_5_1 ( void )
{
    R_5_1_1 ( );

    use_int32 ( engine_exhaust_gas_temperature_raw );
    use_int32 ( engine_exhaust_gas_temperature_scaled );
    use_int32 ( engine_exhaust_gas_temp_raw );
    use_int32 ( engine_exhaust_gas_temp_scaled );
    use_int32 ( abc );

    R_5_1_2 ( );
}
/* end of R_05_01_1.c */

