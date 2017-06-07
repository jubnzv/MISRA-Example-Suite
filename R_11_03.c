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
 * R.11.3
 *
 * A cast shall not be performed between a pointer to object type and a pointer 
 * to a different object type
 */

#include "mc3_types.h"
#include "mc3_header.h"


extern uint32_t read_value ( void );
extern void print ( uint32_t n );
extern int32_t * const * get_int32_ptr_ptr ( void );
extern void use_int16_cvptr ( const volatile int16_t *use_int16_ptr_param );
extern void use_int32_ccptr ( const int32_t * const *use_int32_ptr_param );

static void f3 ( void )
{
  uint32_t u     = read_value ( );
  uint16_t *hi_p = ( uint16_t * ) &u; /* Non-compliant even though
                                       * probably correctly aligned */
  *hi_p = 0;     /* Attempt to clear high 16-bits on big-endian machine */
  print ( u );   /* Line above may appear not to have been performed */
}

void R_11_3 ( void )
{
   uint8_t  *p1 = get_uint8_ptr ( );
   uint32_t *p2;

   p2 = ( uint32_t * ) p1;         /* Non-compliant  - possible incompatible alignment */
   use_uint32_ptr ( p2 );

   const int16_t s = 1;
   const int16_t *p = &s;
   const volatile int16_t *q;

   q = ( const volatile int16_t * ) p;        /* Compliant     */
   use_int16_cvptr ( q );

   int32_t * const * pcpi = get_int32_ptr_ptr ( );
   const int32_t * const * pcpci;

   pcpci = ( const int32_t * const * ) pcpi;  /* Non-compliant */
   use_int32_ccptr ( pcpci );

   f3 ( );
}
/* end of R_11_03.c */

