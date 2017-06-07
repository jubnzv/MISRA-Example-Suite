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
 * R.6.1
 *
 * Bit-fields shall only be declared with an appropriate type
 *
 * Note: This assumes that the "int" type is 32 bit
 */

#include "mc3_types.h"
#include "mc3_header.h"

typedef unsigned int UINT_32;

struct s
{
  unsigned int b1:2; /* Compliant */
  int          b2:2; /* Non-compliant - plain int not permitted */
  UINT_32      b3:2; /* Compliant     - typedef designating unsigned int */
  signed long  b4:2; /* Non-compliant - even if long and int are the same size */
                     /* C90: always non-compliant                              */
                     /* C99: non-compliant if "signed long" is not a permitted
                             by implementation                                 */
};


void R_6_1 ( void )
{
  struct s bitfields = { 0 };
  use_uint32 ( bitfields.b1);
  use_int32 ( bitfields.b2 );
  use_uint32 ( bitfields.b3 );
  use_int64 ( bitfields.b4 );
}

/* end of R_06_01.c */
