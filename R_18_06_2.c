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
 * R.18.6
 *
 * The address of an object with automatic storage shall not be copied to 
 * another object that persists after the first object has ceased to exist
 */

#include "R_18_06.h"


void R_18_6_2 ( void )
{
   *sp = get_uint16 ( );
}


/* end of R_18_06_2.c */
