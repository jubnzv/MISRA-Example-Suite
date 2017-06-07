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
 * D.4.8
 *
 * If a pointer to a structure or union is never dereferenced within a
 * translation unit, then the implementation of the object should be hidden
 */

#ifndef D_4_8_H_
#define D_4_8_H_


#include "mc3_types.h"
#include "mc3_header.h"

typedef struct OpaqueType * pOpaqueType;

extern pOpaqueType GetObject( void );
extern void UseObject( const pOpaqueType p );

struct Not_OpaqueType
{
  int32_t c;
  int32_t d;
};
typedef struct Not_OpaqueType * pNot_OpaqueType;

extern pNot_OpaqueType GetObject_notop( void );
extern void UseObject_notop( const pNot_OpaqueType p );

struct X { int32_t i1; };
typedef struct X * ptrX;
extern  void use_ptrX ( ptrX p );
extern  ptrX get_ptrX ( void );


#endif /* D_4_8_H_ */
