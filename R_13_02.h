/*
 * Release: 2016-01-01
 *
 * Example from MISRA C:2012 ( THIS IS NOT A TEST SUITE )
 *
 * Copyright HORIBA MIRA Limited.
 *
 * See file READ_ME.txt for full copyright, license and release instructions.
 */

#ifndef R_13_02_
#define R_13_02_

#include "mc3_types.h"
#include "mc3_header.h"

typedef struct struct_fn_t
{
  void (* fn)( struct struct_fn_t * s_fn_ptr );
} struct_fn;


typedef struct_fn* struct_fn_ptr;

extern struct_fn*  get_struct_fn_ptr ( void );



extern void f ( uint16_t xx, uint16_t yy );

extern volatile uint16_t v1, v2;



#endif /* R_13_02_ */

