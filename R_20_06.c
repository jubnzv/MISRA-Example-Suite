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
 * R.20.6
 *
 * Tokens that look like a preprocessing directive shall not occur within a 
 * macro argument
 */

#include "mc3_types.h"
#include "mc3_header.h"
#include <stdio.h>

#define M( A ) ( void ) printf( #A ) /* breaks D.4.9, R.21.6 and R.20.10 */

void R_20_6 ( void )
{
   M (
#ifdef SW             /* Non-compliant */
         "Message 1"
#else                 /* Non-compliant */
         "Message 2"
#endif                /* Non-compliant */
     );

}

/* end of R_20_06.c */

