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
 * R.11.8
 *
 * A cast shall not remove any const or volatile qualification from the type 
 * pointed to by a pointer
 */

#include "mc3_types.h"
#include "mc3_header.h"



void R_11_8 ( void )
{
   const uint16_t          cx = 3U;
   volatile uint16_t       vx = 3U;

   uint16_t                 x = 3U;
   uint16_t * const       cpi = &x;     /* const pointer               */
   uint16_t * const    * pcpi = &cpi;  /* pointer to const pointer    */
   uint16_t *          * ppi;
   const uint16_t      * pci = &cx;    /* pointer to const            */
   volatile uint16_t   * pvi = &vx;    /* pointer to volatile         */
   uint16_t            * pi;

   pi = cpi;                           /* Compliant - no conversion
                                                      no cast required */
   use_uint16_ptr(pi);

   pi  = ( uint16_t * ) pci;           /* Non-compliant               */
   use_uint16_ptr(pi);

   pi  = ( uint16_t * ) pvi;           /* Non-compliant               */
   use_uint16_ptr(pi);

   ppi = ( uint16_t * * ) pcpi;        /* Non-compliant               */
   use_uint16_ptr(*ppi);

}

/* end of R_11_08.c */

