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
 * D.4.3
 *
 * Assembly language shall be encapsulated and isolated
 */

#include "mc3_types.h"
#include "mc3_header.h"

#define NOP asm("  NOP")               /* Compliant, but breaks R.1.2 */

static void D_4_3_1 ( void )
{
   asm { "CLI" };                      /* Non-compliant  */
   use_int16 ( 1 );
   asm { "SEI" };                      /* Non-compliant  */
}

static void D_4_3_2 ( void )
{
   NOP;
}

void D_4_3 ( void )
{
   D_4_3_1 ( );
   D_4_3_2 ( );
}

/* end of D_04_03.c */

