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
 * R.8.6
 *
 * An identifier with external linkage shall have exactly one external
 * definition
 */

/* Note: Extern only used in 1 file breaks R.8.7 */

#include "R_08_06.h"

int16_t i = 10;                 /* Non-compliant - two definitions  */

int16_t j;                      /* Tentative definition             */
int16_t j = 1;                  /* Compliant - external definition,
                                             but breaks R.8.9       */

int16_t k = 0;                  /*  Non-compliant - 2 definitions,
                                             also breaks R.8.4      */

void R_8_6 ( void )
{
   R_8_6_2 ( );
   use_int16 ( i + j + k );
   use_int32 ( no_definition ); /* breaks R.9.1                     */
   no_definition_f ( );
}

/* end of R_08_06_1.c */

