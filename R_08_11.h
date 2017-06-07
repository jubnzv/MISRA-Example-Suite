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
 * MISRA-C:2012
 *
 * R.8.11
 *
 * When an array with external linkage is declared, its size should be 
 * explicitly specified. 
 */

#ifndef R_08_11_
#define R_08_11_

#include "mc3_types.h"
#include "mc3_header.h"


extern int32_t array1 [ 10 ]; /* Compliant */
extern int32_t array2 [ ];    /* Non-compliant */

extern void R_8_11_2 ( void );

#endif /* R_8_11_H_ */
