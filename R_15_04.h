/*
 * Release: 2016-01-01
 *
 * Example from MISRA C:2012 ( THIS IS NOT A TEST SUITE )
 *
 * Copyright HORIBA MIRA Limited.
 *
 * See file READ_ME.txt for full copyright, license and release instructions.
 */

#ifndef R_15_04_
#define R_15_04_

#include "mc3_types.h"
#include "mc3_header.h"


extern bool ExitNow ( uint32_t e );
extern bool BreakNow ( uint32_t b );
extern bool GotoNow ( uint32_t g );
extern void KeepGoing ( uint32_t k );


#endif /* R_15_04_ */
