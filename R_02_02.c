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
 * R.2.2
 *
 * There shall be no dead code
 */


#include "mc3_types.h"
#include "mc3_header.h"


static void g ( void )
{
/* Compliant - there are no operations in this function */
}

static void h ( void )
{
   static int32_t h_count = 0;
   h_count++;

   g ( ); /* Non-compliant - the call could be removed */
}


void R_2_2 ( void )
{
   volatile uint16_t v = get_uint16 ( );
   char *p1 = get_char_ptr ( );
   char *p2 = get_char_ptr ( );

   uint16_t x;
   uint16_t y = get_uint16 ( );
   uint16_t z;

   ( void ) v;    /* Compliant by Exception - v is accessed for its side-effect */

   ( int64_t ) v; /* Non-compliant - the cast operator is dead        */

   v >> 3;        /* Non-compliant - the >> operator is dead          */

   x = 3U;        /* Non-compliant - the = operator is dead
                                   - x is not subsequently read       */

   *p1++;         /* Non-compliant - result of * operator is not used */

   ( *p2 )++;     /* Compliant     - *p2 is incremented               */

   use_char ( *p2 );

   z = y + 0U;     /* Non-compliant - the + operator is dead          */
   use_uint16 ( z );

   z = y * 1U;    /* Non-compliant - the * operator is dead           */
   use_uint16 ( z );

   h ( );
}


/* end of R_02_02.c */
