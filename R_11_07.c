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
 * R.11.7
 *
 * A cast shall not be performed between pointer to object and a non-integer 
 * arithmetic type
 */

#include "mc3_types.h"
#include "mc3_header.h"

void R_11_7 ( void )
{
   int16_t *p = get_int16_ptr ( );
   float32_t f;

   if ( p != NULL )
   {
     f = ( float32_t ) p;          /* Non-compliant */
     p = ( int16_t * ) f;          /* Non-compliant */
   }

   use_int16_ptr ( p );
}

/* end of R_11_07.c */

