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
 * R.8.3
 *
 * All declarations of an object or function shall use the same names and type
 * qualifiers
 */

#ifndef R_08_03_
#define R_08_03_

#include "mc3_types.h"
#include "mc3_header.h"

typedef uint16_t width_t;
typedef uint16_t height_t;
typedef uint32_t area_t;


extern void f1 ( int16_t x );
extern void f2 ( int16_t y );

#endif /* R_08_03_ */

