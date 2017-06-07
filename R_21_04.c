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
 * R.21.4
 *
 * The standard header file <setjmp.h> shall not be used 
 */

#include "mc3_types.h"
#include "mc3_header.h"
#include  <setjmp.h>                /* Non-compliant */

static jmp_buf myenv;


static void jmpfunc ( int8_t p )
{
  if( p == 10 )
  {
    longjmp ( myenv, 9 );           /* Non-compliant, also breaks R.15.5 */
  }

  use_int8 ( p );
}

void R_21_4 ( void )
{
    int16_t istat = 0;

    if ( setjmp ( myenv ) != 0 )    /* Non-compliant */
    {
      jmpfunc( 10 );
    }

    use_int16 ( istat );
}

/* end of R_21_04.c */

