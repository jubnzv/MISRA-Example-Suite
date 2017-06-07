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
 * R.10.2
 *
 * Expressions of essentially character type shall not be used inappropriately
 * in addition and subtraction operations
 *
 * Note: Some lines will give consequential R.10.3 warnings
 * on assignment, where the non-compliant expression returns
 * the C standard type. See Appendix D of the guidelines.
 */

#include "mc3_types.h"
#include "mc3_header.h"

void R_10_2 ( void )
{
   uint8_t u8a = get_uint8 ( );
   int8_t s8a = get_int8 ( );
   char cha;
   int16_t s16a = get_int16 ( );
   int32_t s32a;
   float32_t fla = get_float32 ( );
   enum { a1, a2, a3 } ena = a2;

   cha = '0' + u8a;     /* Convert u8a to digit   */
   use_char ( cha );
   cha = s8a + '0';     /* Convert s8a to digit   */
   use_char ( cha );
   s32a = cha  - '0';   /* Convert cha to ordinal */
   use_int32 ( s32a );
   cha = '0' - s8a;     /* Convert -s8a to digit  */
   use_char ( cha );

   cha++;               /* compliant             */
   use_char ( cha );

   /* The following also break R.10.4 */
   s16a = s16a - 'a';  /* Non-compliant, returns standard type */
   use_int16 ( s16a );
   cha = '0' + fla;    /* Non-compliant, returns standard type */
   use_char ( cha );
   cha = cha  + ':';   /* Non-compliant, returns standard type */
   use_char ( cha );
   cha = cha  - ena;   /* Non-compliant, returns standard type, also breaks R.10.1 */
   use_char ( cha );

}
/* end of R_10_02.c */
