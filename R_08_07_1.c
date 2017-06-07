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
 * R.8.7
 *
 * Functions and objects should not be defined with external linkage if they
 * are referenced in only one translation unit
 */

/* Note: Extern only used in 1 file breaks R.8.7 */

#include "R_08_07.h"

int32_t implicit_extern = 8;       /* Non-compliant, also breaks R.8.4  */
int32_t explicit_extern = 10;      /* Non-compliant  */

int32_t extern_required;

void explicit_ext ( void )        /* Non-compliant  */
{
   use_int32 ( implicit_extern );
   use_int32 ( explicit_extern );
}


void R_8_7 ( void )
{
   R_8_7_2 ( );
   explicit_ext ( );
   use_int32 ( implicit_extern );
   use_int32 ( explicit_extern );
   use_int32 ( extern_required );
}


/* end of R_08_07_1.c */

