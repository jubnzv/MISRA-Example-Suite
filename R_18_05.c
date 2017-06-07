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
 * R.18.5
 *
 * Declarations should contain no more than two levels of pointer nesting
 */
#include "mc3_types.h"
#include "mc3_header.h"

typedef int8_t * INTPTR;

static void function ( int8_t ** arrPar[ ] ) /* Non-compliant */
{
   int8_t ** obj2;                        /* Compliant     */
   int8_t *** obj3;                       /* Non-compliant */
   INTPTR * obj4;                         /* Compliant     */
   INTPTR * const * const obj5;           /* Non-compliant */
   int8_t ** arr[ 10 ];                   /* Compliant     */
   int8_t **(*parr)[ 10 ];                /* Compliant     */
   int8_t *(**pparr)[ 10 ];               /* Compliant     */

   if ( arrPar[ 0 ] != NULL )
   {
      if ( *( arrPar[ 0 ] ) != NULL )
      {
         **( arrPar[ 0 ] ) = get_int8 ( );
      }
   }
}


static int8_t ** (   *pfunc1 )( void );   /* Compliant     */
static int8_t ** (  **pfunc2 )( void );   /* Compliant     */
static int8_t ** ( ***pfunc3 )( void );   /* Non-compliant */
static int8_t *** ( **pfunc4 )( void );   /* Non-compliant */


struct s
{
   int8_t *   s1;                         /* Compliant     */
   int8_t **  s2;                         /* Compliant     */
   int8_t *** s3;                         /* Non-compliant */
};

void R_18_5 ( void )
{
   struct s     ps0;                     /* Compliant     */
   struct s *   ps1;                     /* Compliant     */
   struct s **  ps2;                     /* Compliant     */
   struct s *** ps3;                     /* Non-compliant  */

   use_int32 ( 3 );

   int8_t ** arr10[ 10 ] = { 0 };
   function ( arr10 );
}

/* end of R_18_05.c */
