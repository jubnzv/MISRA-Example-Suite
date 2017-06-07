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
 * R.9.5
 *
 * Where designated initialisers are used to initialize an array object the 
 * size of the array shall be specified explicitly
 */

#include "mc3_types.h"
#include "mc3_header.h"


void R_9_5 ( void )
{
   int32_t a1[ ]    = { [0] = 1 };    /* Non-compliant - probably unintentional to have single element */
   int32_t a2[ 10 ] = { [0] = 1 };    /* Compliant                                                     */

   use_int32 ( a1[ 0 ] );
   use_int32 ( a2[ 0 ] );
}

/* end of R_09_05.c */
