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
 * R.2.7
 *
 * There should be no unused parameters in functions
 */

#include "mc3_types.h"
#include "mc3_header.h"


static void withunusedpara ( uint16_t *para1,
                             int16_t   unusedpara )   /* Non-compliant */
{
   *para1 = 42U;
}

static int16_t voidedpara ( int16_t notwanted )
{
    ( void ) notwanted;  /* Compliant */
    return 0;
}


void R_2_7 ( void )
{
   uint16_t data1;
   int16_t data2 = 6;

   withunusedpara ( &data1, data2 );
   data2 = voidedpara ( data2 );

   use_uint16 ( data1 );
   use_int16 ( data2 );
}

/* end of R_02_07.c */
