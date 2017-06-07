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

#include "D_04_08.h"

static void D_4_8_1 ( const ptrX a,  /* compliant, since member i1 of ptrX used elsewhere */
                      ptrX b )
{
   use_ptrX ( a );
   b->i1 = 3;
   use_int32 ( b->i1 ) ;
}

void D_4_8 ( void )
{
   pOpaqueType pObject;
   pObject = GetObject ( );   /* Get a handle to an OpaqueType object */
   UseObject ( pObject );     /* Use it...                            */

   pNot_OpaqueType pObject2;        /* Non-compliant - implementation of object not hidden */
   pObject2 = GetObject_notop ( );
   UseObject_notop ( pObject2 );

   ptrX A1 = get_ptrX( );
   ptrX A2 = get_ptrX( );
   D_4_8_1( A1, A2 );
}

/* end of D_04_08_1.c */
