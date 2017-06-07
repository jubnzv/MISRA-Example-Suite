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
 * R.21.1
 *
 * #define and #undef shall not be used on a reserved identifier or reserved 
 * macro name
 */

#include "mc3_types.h"
#include "mc3_header.h"


#undef __LINE__        /* Non-compliant, also breaks R.20.5 */
#define _GUARD_H 1     /* Non-compliant                     */
#undef _BUILTIN_sqrt   /* Non-compliant, also breaks R.20.5 */


#define defined        /* Non-compliant - reserved identifier  */
#define errno my_errno /* Non-compliant - library identifier   */

/* Compliant - rule doesn't include future library directions */
#define isneg( x ) ( ( x ) < 0 )  /* breaks D.4.9 */


void R_21_1 ( void )
{
   if ( isneg ( get_int32 ( ) ) )
   {
      use_int32 ( _GUARD_H );
   }
   else
   {
      int32_t my_errno = get_int32 ( );
      use_int32 ( my_errno );
      use_int32 ( errno );
   }
}

/* end of R_21_01.c */

