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
 * R.13.3
 *
 * A full expression containing an increment (++) or decrement (--) operator 
 * should have no other potential side effects other than that caused by the 
 * increment or decrement operator
 */

#include "mc3_types.h"
#include "mc3_header.h"

static uint8_t f3 ( void )
{
  return get_uint8 ( );
}

static void g3 ( uint8_t gu )
{
   use_uint8 ( gu );
}

void R_13_3 ( void )
{
    uint8_t u8a;
    uint8_t u8b = get_uint8 ( );
    uint8_t u8c = get_uint8 ( );
    uint16_t *p = get_uint16_ptr ( );

    u8a = u8b++;          /* Non-compliant */
    use_uint8 ( u8a );
    u8a = ++u8b + u8c--;  /* Non-compliant */
    use_uint8 ( u8a );

    ++u8b;
    u8a = u8b + u8c;
    u8c--;
    use_uint8 ( u8a + u8b + u8c );


    uint16_t x = get_uint16 ( );
    uint16_t i = get_uint16 ( );
    uint16_t a[ 10 ] = { 0 };

    struct st1
    {
       uint16_t x;
    } b = { 1u };

    struct st1 *c = &b;

    x++;
    use_uint16 ( x );

    a[ i ]++;
    use_uint16 (a [ i ] );

    b.x++;
    use_uint16 ( b.x );
    c->x++;
    use_uint16 ( c->x );

    if ( p != NULL )
    {
       ++( *p );
    }
    if ( p != NULL )
    {
       *p++;
    }
    if ( p != NULL )
    {
      ( *p )++;
      use_uint16_ptr( p );
    }

    if ( ( f3( ) + --u8a ) == 0u )               /* Non-compliant */
    {
    }
    use_uint8 ( u8a );

    g3 ( u8b++ );                                /* Non-compliant */

    u8a = ( 1u == 1u ) ? 0u : u8b++;            /* Non-compliant, also breaks R.14.3 */
    use_uint8 ( u8a );

    u8a = get_uint8 ( );
    if ( u8a++ == ( (1u == 1u) ? 0u : f3( ) ) )  /* Non-compliant */
    {
    }

    use_uint8 ( u8a + u8b );
}

/* end of R_13_03.c */
