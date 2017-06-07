/*
 * Release: 2016-11-01
 *
 * Example from MISRA C:2012 ( THIS IS NOT A TEST SUITE )
 *
 * Copyright HORIBA MIRA Limited.
 *
 * See file READ_ME.txt for full copyright, license and release instructions.
 */

#ifndef R_05_03_
#define R_05_03_


#include "mc3_types.h"
#include "mc3_header.h"

struct astruct
{
   int16_t m;
};

extern void g ( struct astruct * p );


#endif /* R_05_09_ */

