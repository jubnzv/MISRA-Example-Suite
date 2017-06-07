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
 * D.4.8
 *
 * If a pointer to a structure or union is never dereferenced within a 
 * translation unit, then the implementation of the object should be hidden
 */

#include "D_04_08.h"

struct OpaqueType
{
   /* Object implementation */
  int32_t a;
  int32_t b;
};

static struct OpaqueType global_obj = { 0 };

pOpaqueType GetObject( void )
{
   return &global_obj;
}

void UseObject( const pOpaqueType p )
{
   if ( p != NULL )
   {
     p->b += p->a;
     use_int32 ( p->b );
   }
   use_int32 ( global_obj.a + global_obj.b );
}


static struct Not_OpaqueType global_obj2 = { 0 };

pNot_OpaqueType GetObject_notop( void )
{
   return &global_obj2;
}

void UseObject_notop( const pNot_OpaqueType p )
{
   if ( p != NULL )
   {
      p->d += p->c;
      use_int32 ( p->d );
   }
   use_int32 ( global_obj2.c + global_obj2.d );
}

/* end of D_04_08_2.c */
