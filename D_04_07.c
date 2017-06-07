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
 * D.4.7
 *
 * If a function returns error information, then that error information
 * shall be tested
 */

#include "mc3_types.h"
#include "mc3_header.h"



static uint8_t add ( uint16_t *out_param, const uint16_t *in_param )
{
   uint8_t err_status = 0U;

   *out_param += ( *in_param );
   if ( *out_param  <  *in_param  )
   {
      /* Overflow has occurred */
      err_status = 1U;
   }
   return err_status;
}


void D_4_7 ( void )
{
    uint8_t error_status;
    uint16_t fun_ret = get_uint16 ( );
    uint16_t param   = get_uint16 ( );

    /* Non-compliant 'error' information is disregarded */
    ( void ) add ( &fun_ret, &param );

    /* Non-compliant 'error' information is assigned to error_status, but never tested. */
    error_status = add ( &fun_ret, &param ); /* Also breaks R.2.2 */

    /* Compliant 'error' information is assigned to error_status, and subsequently tested. */
    error_status = add ( &fun_ret, &param );
    if ( error_status != 0U )
    {
       fun_ret = 0U;
    }

    use_uint16 ( fun_ret );
}

/* end of D_04_07.c */
