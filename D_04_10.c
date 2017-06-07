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
 * D.4.10
 *
 * Precautions shall be taken in order to prevent the contents of a header file 
 * being included more than once
 */

#include "mc3_types.h"
#include "mc3_header.h"

#include "D_04_10_1.h"
#include "D_04_10_2.h"
#include "D_04_10_3.h"

void D_4_10 ( void )
{
   use_int32 ( 3 );
}
/* end of D_04_10.c */
