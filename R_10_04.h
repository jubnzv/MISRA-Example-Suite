/*
 * Release: 2016-01-01
 *
 * Example from MISRA C:2012 ( THIS IS NOT A TEST SUITE )
 *
 * Copyright HORIBA MIRA Limited.
 *
 * See file READ_ME.txt for full copyright, license and release instructions.
 */

#ifndef R_10_04_
#define R_10_04_


#include "mc3_types.h"
#include "mc3_header.h"

enum enuma { A1, A2, A3 };
enum enumb { B1, B2, B3 };

extern enum enuma get_enuma ( void );
extern enum enumb get_enumb ( void );

#endif /* R_10_04_ */

