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
 * R.21.5
 *
 * The standard header file <signal.h> shall not be used 
 */

#include "mc3_types.h"
#include "mc3_header.h"
#include <signal.h>               /* Non-compliant */

void R_21_5 ( void )
{
     int16_t sig;

     sig = SIGINT;

     use_int16 ( sig );

}

/* end of R_21_05.c */

