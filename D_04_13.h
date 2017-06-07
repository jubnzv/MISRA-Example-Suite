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
 * D.4.13
 *
 * Functions which are designed to provide operations on a resource
 * should be called in an appropriate sequence
 */

#ifndef D_4_13_H_
#define D_4_13_H_

#include "mc3_types.h"
#include "mc3_header.h"

typedef struct mutex_t
{
   int32_t count;
   /*... other fields */
} mutex_t;

/* These functions are intended to be paired */
extern mutex_t mutex_lock ( void );
extern void mutex_unlock ( mutex_t m );

#endif /* D_4_13_H_ */
