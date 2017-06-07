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
 * R.20.1
 *
 * #include directives should only be preceded by preprocessor directives or comments
 */

#define F1_MACRO

#include "mc3_types.h"

static int32_t i = 0;

#include "mc3_header.h"   /* Non-compliant */

static int16_t

#include "R_20_01.h"     /* Non-compliant */



static void use_fn ( void )
{
   use_int32 ( i + xyz );
}

void R_20_1 ( void )
{
   use_fn ( F1_MACRO );

   use_int32 ( i + xyz );
}

/* end of R_20_01.c */

