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
 * R.17.2
 *
 * Functions shall not call themselves, either directly or indirectly
 */


#include "mc3_types.h"
#include "mc3_header.h"


/* Function calling itself directly */
static uint16_t fn_a ( uint16_t parama )
{
   uint16_t ret_val;
   if ( parama > 0U )
   {
      ret_val = parama * fn_a ( parama - 1U ); /* Non-compliant */
   }
   else
   {
      ret_val = parama;
   }
   return ret_val;
}


void R_17_2 ( void )
{
   uint16_t recursive_ret;
   uint16_t recursive_param = get_uint16 ( );

   recursive_ret = fn_a ( recursive_param );

   use_uint16 ( recursive_ret );
}

/* end of R_17_02.c */

