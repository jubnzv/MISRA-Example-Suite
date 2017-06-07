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
 * R.21.9
 *
 * The library functions bsearch and qsort of <stdlib.h> shall not be used
 */

#include "mc3_types.h"
#include "mc3_header.h"

#include <stdlib.h>

#define COUNT 10U

extern int32_t compare ( const void * e1, const void * e2 );

void R_21_9 ( void )
{
  int32_t array[ COUNT ] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  const int32_t key = 5;

  int32_t *result = bsearch ( &key,
                              &array[ 0 ],
                              ( size_t ) COUNT,
                              sizeof ( key ),
                              compare);      /* Non-compliant - also breaks R.11.5 */
  if ( result != NULL )
  {
    use_int32 ( *result );
  }

  qsort( &array[ 0 ], ( size_t ) COUNT, sizeof ( key ), compare ); /* Non-compliant */

  use_int32 ( array[0] );

}

/* end of R_21_09.c */
