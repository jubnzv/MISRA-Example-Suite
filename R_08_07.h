/*
 * Release: 2016-01-01
 *
 * Example from MISRA C:2012 ( THIS IS NOT A TEST SUITE )
 *
 * Copyright HORIBA MIRA Limited.
 *
 * See file READ_ME.txt for full copyright, license and release instructions.
 */

#ifndef R_08_07_
#define R_08_07_

#include "mc3_types.h"
#include "mc3_header.h"

extern int32_t extern_required;

extern int32_t explicit_extern;    /* Non-compliant - doesn't need external linkage */

extern void explicit_ext ( void ); /* Non-compliant - doesn't need external linkage */

extern void R_8_7_2 ( void );


#endif /* R_08_07_ */

