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
 * R.5.4
 *
 * Macro identifiers shall be distinct
 */


#include "mc3_types.h"
#include "mc3_header.h"


/*       1234567890123456789012345678901*********             Characters */
#define  engin4_exhaust_gas_temperature_raw     egt_r
#define  engin4_exhaust_gas_temperature_scaled  egt_s   /* Non-compliant */

/*         1234567890123456789012345678901*********           Characters */
#define  engin4_exhaust_gas_temp_raw            egt_r
#define  engin4_exhaust_gas_temp_scaled         egt_s   /* Compliant     */


void R_5_4 ( void )
{
   int32_t egt_r = 0;
   int32_t egt_s = 1;
   use_int32 ( engin4_exhaust_gas_temperature_raw );
   use_int32 ( engin4_exhaust_gas_temperature_scaled );
   use_int32 ( engin4_exhaust_gas_temp_raw );
   use_int32 ( engin4_exhaust_gas_temp_scaled );
}

/* end of R_05_04.c */

