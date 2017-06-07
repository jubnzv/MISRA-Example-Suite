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
 * R.2.4
 *
 * A project should not contain unused tag declarations
 */


#include "mc3_types.h"
#include "mc3_header.h"

static void unusedtag ( void )
{
   enum state
   {
      S_init, S_run, S_sleep
   }; /* Non-compliant */

   use_int32 ( 3 );
}


typedef struct record_t  /* Non-compliant */
{
  uint16_t key;
  uint16_t val;
} record1_t;

typedef struct  /* Compliant */
{ uint16_t key;
  uint16_t val;
} record2_t;

static void use_recordtypes ( void )
{
   record1_t r1 = {3U, 2U};
   record2_t r2 = {4U, 5U};

   use_uint16( r1.key + r1.val + r2.key + r2.val );
}

struct A
{ int32_t a1;
  int32_t a2;
};                /* Compliant     */

typedef struct A Atype;
     /* no subsequent use of identifier "A" */

typedef struct B
{ int32_t b1;
  int32_t b2;
} Btype;  /* Non-compliant */
    /* no subsequent use of identifier "B"  */

typedef struct
{ int32_t c1;
  int32_t c2;
} Ctype;   /* Compliant     */

void R_2_4 ( void )
{
   Atype ax = { 0, 0 };
   Btype bx = { 0, 0 };
   Ctype cx = { 0, 0 };

   use_recordtypes ( );
   unusedtag ( );
   use_int32 ( ax.a1 + ax.a2 );
   use_int32 ( bx.b1 + bx.b2 );
   use_int32 ( cx.c1 + cx.c2 );
}

/* end of R_02_04.c */
