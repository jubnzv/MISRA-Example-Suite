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
 * R.2.1
 *
 * A project shall not contain unreachable code
 */


#include "R_02_01.h"

void R_2_1 ( void )
{
  enum light beacon;
  beacon = next_light ( green );
  use_light(beacon);

}

/* end of R_02_01_2.c */
