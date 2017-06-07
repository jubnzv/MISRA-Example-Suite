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
 * R.6.2
 *
 * Single-bit named bit fields shall not be of a signed type
 */

#include "mc3_types.h"
#include "mc3_header.h"


struct single_bit
{
   signed int b1:1;        /* Non-compliant */
};


void R_6_2 ( void )
{
   struct single_bit sbit = { 0 };
   use_int32 ( sbit.b1 );
}

/* end of R_06_02.c */
