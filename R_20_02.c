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
 * R.20.2
 *
 * The ', " or \ characters and the /* or // character sequences shall not 
 * occur in a header file name
 */

#include "mc3_types.h"
#include "mc3_header.h"


/* Following  statement is Non-compliant */
#include "fi'le.h"


void R_20_2 ( void )
{
   use_int32 ( 3 );
}

/* end of R_20_02.c */

