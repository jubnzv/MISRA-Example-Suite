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
 * R.5.2
 *
 * Identifiers declared in the same scope and name space shall be distinct
 */

#include "mc3_types.h"
#include "mc3_header.h"

 /*             1234567890123456789012345678901*********       Characters */
 extern int32_t engin2_exhaust_gas_temperature_raw;
 static int32_t engin2_exhaust_gas_temperature_scaled;      /* Non-compliant */

  /*            1234567890123456789012345678901*********       Characters */
 static int32_t engin2_exhaust_gas_temp_raw;
 static int32_t engin2_exhaust_gas_temp_scaled;             /* Compliant */


 static void f ( void )
 {
   /*      1234567890123456789012345678901*********       Characters */
   int32_t engin2_exhaust_gas_temperature_local;         /* Compliant, but breaks R.5.3 */

   engin2_exhaust_gas_temperature_local = 0;
   use_int32 ( engin2_exhaust_gas_temperature_local );
 }



static void R_5_2_1 ( void )
{
   use_int32 ( engin2_exhaust_gas_temperature_raw );
   use_int32 ( engin2_exhaust_gas_temperature_scaled );
   use_int32 ( engin2_exhaust_gas_temp_raw );
   use_int32 ( engin2_exhaust_gas_temp_scaled );
}

void R_5_2 ( void )
{
   f ( );

   engin2_exhaust_gas_temperature_raw = 0;
   engin2_exhaust_gas_temperature_scaled = 0;
   engin2_exhaust_gas_temp_raw = 0;
   engin2_exhaust_gas_temp_scaled = 0;

   use_int32 ( engin2_exhaust_gas_temperature_raw );
   use_int32 ( engin2_exhaust_gas_temperature_scaled );
   use_int32 ( engin2_exhaust_gas_temp_raw );
   use_int32 ( engin2_exhaust_gas_temp_scaled );
   R_5_2_1 ( );
}

/* End of R_5_2.c */


