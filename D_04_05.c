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
 * D.4.5
 *
 * Identifiers in the same namespace with overlapping visibility should be 
 * typographically unambiguous
 */

#include "mc3_types.h"
#include "mc3_header.h"


void D_4_5 ( void )
{
   int32_t id1_a_b_c = 1;
   int32_t id1_abc = 1;  /* Non-compliant  */

   int32_t id2_abc = 1;
   int32_t id2_ABC = 1;  /* Non-compliant  */

   int32_t id3_a_bc = 1;
   int32_t id3_ab_c = 1; /* Non-compliant  */

   int32_t id4_I = 1;
   int32_t id4_1 = 1;    /* Non-compliant  */

   int32_t id5_Z = 1;
   int32_t id5_2 = 1;    /* Non-compliant  */

   int32_t id6_O = 1;
   int32_t id6_0 = 1;    /* Non-compliant  */

   int32_t id7_B = 1;
   int32_t id7_8 = 1;    /* Non-compliant  */

   int32_t id8_rn = 1;
   int32_t id8_m = 1;    /* Non-compliant  */

   int32_t id9_rn = 1;
   struct
   {
      int32_t id9_m; /* Compliant */
   } struct_x = { 1 };


   use_int32 ( id1_a_b_c + id1_abc + id2_abc + id2_ABC );
   use_int32 ( id3_a_bc + id3_ab_c + id4_I + id4_1 + id5_Z + id5_2 );
   use_int32 ( id6_0 + id6_O + id7_B + id7_8 + id8_rn + id8_m );
   use_int32 ( id9_rn + struct_x.id9_m );

}

/* end of D_04_05.c */
