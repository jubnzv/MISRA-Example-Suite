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
 * R.5.6
 *
 * A typedef name shall be a unique identifier
 */


#include "mc3_types.h"
#include "mc3_header.h"

static void func (void)
{
   {
      typedef unsigned char u8_t;

      u8_t c1 = get_uint8 ( );
      use_uint8 ( c1 );
   }
   {
      typedef unsigned char u8_t; /* Non-compliant */

      u8_t c2 = get_uint8 ( );
      use_uint8 ( c2 );
   }
}


typedef float mass32;

static void func1 (void)
{
   float32_t mass32 = 0.0f;       /* Non-compliant, also breaks R.5.3 */

   use_float32 ( mass32 );
}


typedef struct list
{
   struct list *next;
   uint16_t     element;
} list;                           /* Compliant - exception */

typedef struct
{
   struct chain
   {
         struct chain *chlist;
         uint16_t      element;
   } s1;
   uint16_t length;
} chain;                          /* Non-compliant - tag "chain" not associated with typedef */


void R_5_6 ( void )
{
   const mass32 zero_mass = 0.0F;
   chain cable = { 0 };
   list list1 = { NULL, 1U };

   func ( );
   func1 ( );
   use_float32 ( zero_mass );
   use_uint16 ( cable.s1.element + cable.length );
   use_uint16 ( list1.element );
}

/* end of R_05_06.c */
