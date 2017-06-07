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
 * R.19.1
 *
 * An object shall not be assigned or copied to an overlapping object
 */

#include "mc3_types.h"
#include "mc3_header.h"

#include <string.h>


static void fn ( void )
{
  union                  /* breaks R.19.2 */
  {
     int16_t i;
     int32_t j;
  } a = { 0 };

  use_int32 ( a.j );

  a.j = a.i;             /* Non Compliant */
  use_int32 ( a.j );
}


static int16_t arr[ 20 ] = { 0 };

static void f ( void )
{
   ( void ) memcpy ( &arr[ 5 ], &arr[ 4 ], 2u * sizeof ( arr[ 0 ] ) ); /* Non-compliant */
}


static void g ( void )
{
   int16_t *p = &arr [ 0 ];
   int16_t *q = &arr [ 0 ];
   *p = *q;                /* Compliant - exception 1 */

   use_int16 ( *p + *q );
}


void R_19_1 ( void )
{
   fn ( );
   f ( );
   g ( );
}

/* end of R_19_01.c */
