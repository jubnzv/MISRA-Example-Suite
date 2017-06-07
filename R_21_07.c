/*
 * Release: 2016-11-01
 *
 * Example from MISRA C:2012 ( THIS IS NOT A TEST SUITE )
 *
 * Copyright HORIBA MIRA Limited.
 *
 * See file READ_ME.txt for full copyright, license and release instructions.
 */

/*
 * R.21.7
 *
 * The Standard Library functions atof, atoi, atol and atoll of <stdlib.h>
 * shall not be used
 */

#include "mc3_types.h"
#include "mc3_header.h"
#include <stdlib.h>

void R_21_7 ( void )
{
  float64_t a_to_float_result;

  a_to_float_result = atof ( "123.5" );      /* Non_compliant, also breaks R.22.8, R.22.9 */

  use_float64 ( a_to_float_result );

}

/* end of R_21_07.c */

