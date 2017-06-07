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
 * R.21.10
 *
 * The Standard Library time and date routines shall not be used
 */

#include "mc3_types.h"
#include "mc3_header.h"
#include <time.h>               /* Non-compliant */

void R_21_10 ( void )
{
     float64_t  time_dif;
     time_t     time_1;
     time_t     time_2;

     time_1   = clock ( );                    /* Non-compliant */
     time_2   = clock ( );                    /* Non-compliant */
     time_dif = difftime ( time_1, time_2 );  /* Non-compliant */

     use_float64 ( time_dif );
}

/* end of R_21_10.c */

