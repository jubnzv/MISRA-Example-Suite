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
 * D.4.9
 *
 * A function should be used in preference to a function-like macro where they 
 * are interchangeable
 */

#include "mc3_types.h"
#include "mc3_header.h"


#define DIV2( X ) ( ( X ) / 2U )

static void fn ( void )
{
   static uint16_t x = DIV2 ( 10U );   /* Compliant -  fn call not permitted */

   uint16_t y = DIV2 ( 10U );          /* Non-compliant - fn call permitted */

   use_uint16 ( x + y );
}


#define EVAL_BINOP( OP, L, R ) ( ( L ) OP ( R ) )

void D_4_9 ( void )
{
   uint32_t z = EVAL_BINOP ( +, 1U, 2U );   /* Compliant -
                                              "+" can not be passed as fn arg */
   use_uint32 ( z );

   fn ( );
}

/* end of D_04_09.c */
