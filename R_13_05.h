/*
 * Release: 2016-01-01
 *
 * Example from MISRA C:2012 ( THIS IS NOT A TEST SUITE )
 *
 * Copyright HORIBA MIRA Limited.
 *
 * See file READ_ME.txt for full copyright, license and release instructions.
 */

#ifndef R_13_05_
#define R_13_05_

#include "mc3_types.h"
#include "mc3_header.h"

extern uint16_t global;


typedef bool_t ( *fnptr ) ( uint16_t y );

extern bool_t persist ( uint16_t y );



#endif /* R_13_05.h */

