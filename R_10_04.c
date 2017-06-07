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
 * R.10.4
 *
 * Both operands of an operator in which the usual arithmetic conversions are
 * performed shall have the same essential type category
 *
 * Note: Some lines will give consequential R.10.3 warnings
 * on assignment, where the non-compliant expression returns
 * the C standard type. See Appendix D of the guidelines.
 */

#include "R_10_04.h"



void R_10_4 ( void )
{
   uint8_t u8a  = get_uint8 ( );
   uint8_t u8b  = get_uint8 ( );
   uint16_t u16b = get_uint16 ( );
   int8_t s8a = get_int8 ( );
   char cha = get_char ( );


   enum enuma ena = get_enuma ( );
   enum enumb enb = get_enumb ( );


   if (ena > A1)                /*  Compliant  - same essential type  */
    {
       ; /*no action */
    }
   u16b = u8a + u16b;           /*  Compliant - same essential type   */
   use_uint16 ( u16b );

   cha += u8a;                  /*  Compliant by exception */
   use_char ( cha );

   s8a += u8a;                  /* Non-compliant - Signed and unsigned,
                                                   also breaks R.10.3*/
   use_int8 ( s8a );

   u8b = u8b + 2;               /* Non-compliant - unsigned and signed,
                                                   returns standard type  */
   use_uint8( u8b );

   if ( enb > A1 )              /* Non-compliant - Enum<enuma> to enum<enumb>    */
   {
      ; /* no action */
   }
   if ( ena == enb )            /* Non-compliant - Enum<enumb> to enum<enuma>      */
    {
       ; /* no action */
    }

   u8a += cha;                  /* Compliant by exception, but breaks R.10.3 */
   use_uint8 ( u8a );


}
/* end of R_10_04.c */
