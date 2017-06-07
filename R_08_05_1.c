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
 * R.8.5
 *
 * An external object or function shall be declared once in one and only one file
 */

#include "R_08_05.h"

int16_t a = 0;                         /* Compliant - declaration in header */

extern int32_t ex_file_head_decl;      /* Non-compliant - declaration also in header */

int32_t ex_file_head_decl = 0;


void R_8_5 ( void )
{
   R_8_5_2 ( );
   use_int32 ( ex_file_head_decl );
   use_int16 ( a );
}




/* end of R_08_05.c */

