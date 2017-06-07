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
 * R.11.6
 *
 * A cast shall not be performed between pointer to void and an arithmetic type
 */

#include "mc3_types.h"
#include "mc3_header.h"

void R_11_6 ( void )
{
   void    *p;
   uint32_t u;

   p = ( void * ) 0x1234u;  /* Non-compliant - implementation-defined */
   use_void_ptr ( p );

   p = ( void * ) 1024.0f;  /* Non-compliant - undefined              */

   u = ( uint32_t ) p;      /* Non-compliant - implementation-defined */

   use_uint32 ( u );
}
/* end of R_11_06.c */

