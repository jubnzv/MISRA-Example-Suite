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
 * R.8.1
 *
 * Types shall be explicitly specified
 */

/* Note: Extern only used in 1 file breaks R.8.7 */

#include "mc3_types.h"
#include "mc3_header.h"

extern x;                                      /* Non-compliant - implicit int type */
extern int16_t x_ok;                           /* Compliant - explicit type */

extern f ( void );                             /* Non-compliant - implicit int return type */
extern int16_t f_ok( void );                   /* Compliant */

extern void g ( char c, const k );              /* Non-compliant - implicit int for parameter k */
extern void g_ok ( char c2, const int16_t k2 ); /* Compliant */


typedef ( *pfi )( void );                       /* Non-compliant - implicit int return type */
typedef int16_t ( *pfi_ok )( void );            /* Compliant */

typedef void ( *pfv ) ( const x );              /* Non-compliant  - implicit int for parameter x */
typedef void ( *pfv_ok ) ( int16_t xx );        /* Compliant */


void R_8_1 ( void )
{
   const y;                 /* Non-compliant - implicit int type */
   const int16_t y_ok;      /* Compliant     - explicit type */

   struct
   {
        int16_t x1;   /* Compliant */
        const   y1;   /* Non-compliant - implicit int for member y */
   } s =
         {1, 2};

   pfi    F1 = &get_int32;
   pfi_ok F2 = &get_int16;

   pfv    F11 = &use_int32;
   pfv_ok F22 = &use_int16;

   F11( F1( ) + s.y1 );
   F22( F2( ) + s.x1 );
}

/* end of R_08_01.c */
