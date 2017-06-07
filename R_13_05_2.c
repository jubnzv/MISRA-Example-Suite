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
 * R.13.5
 *
 * The right hand operand of a logical && or || operator shall not contain 
 * persistent side-effects
 */

#include "R_13_05.h"

bool_t persist ( uint16_t y )
{
   uint16_t local = get_uint16 ( );
   bool_t result = ( y == local );
   global = y;
   return result;
}

/* end of R_13_05.c */
