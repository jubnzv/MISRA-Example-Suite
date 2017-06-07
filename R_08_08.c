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
 * R.8.8
 *
 * The static storage class specifier shall be used in all declarations of
 * objects and functions that have internal linkage
 */

#include "mc3_types.h"
#include "mc3_header.h"


static int32_t x8 = 0;       /* definition: internal linkage  */
extern int32_t x8;           /* Non-compliant                 */

extern int32_t y8 = 10;     /* definition: external linkage: Breaks rule 8.4 */
static int32_t y8;          /* internal linkage: Breaks rule 8.8 */


static int32_t f8 ( void );  /* declaration: internal linkage */
int32_t f8 ( void )          /* Non-compliant                 */
{
   return x8;
}

static int32_t g8 ( void );  /* declaration: internal linkage */
extern int32_t g8 ( void )   /* Non-compliant                 */
{
   return x8;
}


/* R.8.8 does not apply since the one declaration is with external linkage */
int32_t h8 ( void );         /* declaration: external linkage */
static int32_t h8 ( void )   /* definition : internal linkage. Breaks rule 1.3 */
{
   return y8;
}

void R_8_8 ( void )
{
   (void) f8 ( );
   (void) g8 ( );
   (void) h8 ( );
   use_int32 ( x8 );
   use_int32 ( y8 );
}

/* end of R_08_08.c */

