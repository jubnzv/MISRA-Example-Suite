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
 * D.4.6
 *
 * typedefs that indicate size and signedness should be used in place of the 
 * basic numerical types
 */

#include "mc3_types.h"
#include "mc3_header.h"

typedef int SINT_16;          /* Compliant - int used to define specific-length type */

typedef int speed_t;          /* Non-compliant - no sign or size specified                         */

typedef int16_t torque_t;     /* Compliant     - further abstraction does not need specific length */


void D_4_6 ( void )
{
   int ival = 1;              /* Non-compliant - int used to define an object      */
   char c = 'a';              /* Compliant     - plain char is not a basic numerical type */
   SINT_16 s16 = 1;
   speed_t speed = 4;
   torque_t torq = 5;

   use_char ( c );
   use_int32 ( s16 + ival + ( speed * torq ) );
}

/* end of D_04_06.c */
