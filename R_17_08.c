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
 * R.17.8
 *
 * A function parameter should not be modified
 */

#include "mc3_types.h"
#include "mc3_header.h"

static int16_t glob = 0;

static void proc ( int16_t para )
{
   para = glob;   /* Non-compliant */
   use_int16 ( para );
}


static void f8 ( char *p,  char *q )
{
   p = q;         /* Non-compliant */
   *p = *q;       /* Compliant     */

   use_char_ptr ( p );
}


void R_17_8 ( void )
{
   char val1 = 'A';
   char val2 = 'B';
   char *p1 = &val1;
   char *p2 = &val2;

   f8 ( p1, p2 );

   proc ( 3 );

   use_int16 ( glob );
}

/* end of R_17_08.c */
