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
 * R.7.2
 *
 * A "u" or "U" suffix shall be applied to all integer constants that are 
 * represented in an unsigned type
 *
 * Note: Examples in document apply to 16-bit int and 32-bit long.
 * These examples are designed to run with the default values of 32-bit int and 64-bit long.
 */

#include "mc3_types.h"
#include "mc3_header.h"

void R_7_2 ( void )
{
       use_int32  ( 2147483647 );          /* int constant */
       use_int32  ( 0x7FFFFFFF );          /* int constant */
       use_int64  ( 2147483648 );          /* long constant */
       use_uint32 ( 2147483648U );         /* unsigned int constant */
       use_uint32 ( 0x80000000 );          /* unsigned int constant -  Non-compliant */
       use_uint32 ( 0x80000000U );         /* unsigned int constant */


}

/* end of R_07_02.c */
