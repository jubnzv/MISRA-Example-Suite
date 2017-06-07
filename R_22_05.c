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
 * R.22.5
 *
 * A pointer to a FILE object shall not be dereferenced
 */

/* Note: This file also contains violations of rule R.21.6 */

#include "R_22_05.h"

void R_22_5 ( void )
{
   FILE *pf1 = tmpfile( );
   FILE *pf2;
   FILE  f3;

   pf2 = pf1;         /* Compliant */
    f3 = *pf2;        /* Non-compliant */

   ( void ) fclose( pf2 );
   use_FILE ( f3 );
}

/* end of R_22_05.c */
