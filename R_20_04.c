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
 * R.20.4
 *
 * A macro shall not be defined with the same name as a keyword
 */

#include "mc3_types.h"
#include "mc3_header.h"

#define some_other_type long     /* Breaks D.4.6 */

#define int some_other_type      /* Non-compliant */
#include <stdlib.h>              /* undefined behaviour if keyword changed and header included */


#define while( E ) for ( ; ( E ) ; )  /* Non-compliant - redefined while */

#define unless( E ) if ( ! ( E ) )    /* Compliant  */

/* Note: following line changed from document example to permit seq example to compile */
#define seq( S1, S2 ) if ( get_bool ( ) ) { \
   S1; S2; }                          /* Compliant  */

#define compound( S ) { S; }          /* Compliant  */

#define inline                        /* Non-compliant C99, Compliant C90 */


void R_20_4 ( void )
{
  int32_t ind = 0;

  while ( ind < 10 )
  {  ind++;
     use_int32 ( ind );
  }

  ind = get_int32 ( );
  unless ( ind > 3 ) { ; }

  seq ( ind = 3, use_int64 ( ind ) );

  compound ( use_int64 ( ind ) )

  inline;
}

/* end of R_20_04.c */
