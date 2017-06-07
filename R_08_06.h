/*
 * Release: 2016-01-01
 *
 * Example from MISRA C:2012 ( THIS IS NOT A TEST SUITE )
 *
 * Copyright HORIBA MIRA Limited.
 *
 * See file READ_ME.txt for full copyright, license and release instructions.
 */

#ifndef R_08_06_
#define R_08_06_


#include "mc3_types.h"
#include "mc3_header.h"

extern int16_t i;

extern int32_t two_different_definitions;
extern void two_identical_definitions ( void );

extern int32_t no_definition;                 /* Not Compliant - no definition */
extern void no_definition_f ( void );        /* Not Compliant - no definition */

extern void R_8_6_2 ( void );


#endif /* R_08_06_ */

