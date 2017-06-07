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
 * R.4.2
 *
 * Trigraphs should not be used
 */

#include "mc3_types.h"
#include "mc3_header.h"

void R_4_2 ( void )
{
   const char * datestring = "(Date should be in the form ??-??-??)";     /* Non-compliant */

   use_const_char_ptr ( datestring );
 }

/* end of R_04_02.c */
