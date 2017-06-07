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
 * R.20.9
 *
 * All identifiers used in the controlling expression of #if or #elif 
 * preprocessing directives shall be #define'd before evaluation
 */

#include "mc3_types.h"
#include "mc3_header.h"

#if M == 0          /* Non-compliant */
                    /* Does 'M' expand to zero or is it undefined? */
#endif


#if defined ( M )   /* Compliant - M is not evaluated              */
#if M == 0          /* Compliant - M is known to be defined        */
                    /* 'M' must expand to zero.                    */
#endif
#endif

/* Compliant - B is only evaluated in (B == 0) if it is defined */
#if defined ( B ) && ( B == 0 )
#endif

void R_20_9 ( void )
{
   use_int8 ( 3 );
}

/* end of R_20_09.c */
