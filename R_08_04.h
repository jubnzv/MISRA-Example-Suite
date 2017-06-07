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
 * R.8.4
 *
 * A compatible declaration shall be visible when an object or function with 
 * external linkage is defined. 
 */

#ifndef R_08_04_
#define R_08_04_

#include "mc3_types.h"
#include "mc3_header.h"

extern void func41 ( void );
extern void func42 ( int16_t x, int16_t y );
extern void func43 ( int16_t x, int16_t y );


#endif /* R_8_4_H_ */
