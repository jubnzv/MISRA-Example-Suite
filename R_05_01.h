/*
 * Release: 2016-01-01
 *
 * Example from MISRA C:2012 ( THIS IS NOT A TEST SUITE )
 *
 * Copyright HORIBA MIRA Limited.
 *
 * See file READ_ME.txt for full copyright, license and release instructions.
 */

#ifndef R_05_01_
#define R_05_01_

#include "mc3_types.h"
#include "mc3_header.h"

/*             1234567890123456789012345678901********* Characters */
extern int32_t engine_exhaust_gas_temperature_raw;
extern int32_t engine_exhaust_gas_temperature_scaled; /* Non-compliant */

/*             1234567890123456789012345678901********* Characters */
extern int32_t engine_exhaust_gas_temp_raw;
extern int32_t engine_exhaust_gas_temp_scaled; /* Compliant */

extern void R_5_1_2 ( void );


#endif /* R_05_01_ */

