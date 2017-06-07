/*
 * Release: 2016-01-01
 *
 * Example from MISRA C:2012 ( THIS IS NOT A TEST SUITE )
 *
 * Copyright HORIBA MIRA Limited.
 *
 * See file READ_ME.txt for full copyright, license and release instructions.
 */

#ifndef R_02_01_
#define R_02_01_


#include "mc3_types.h"
#include "mc3_header.h"

extern void error_handler ( void );

enum light { red, amber, red_amber, green };


extern enum light next_light ( enum light c );
extern void use_light ( enum light light1 );


#endif /* R_02_01_ */

