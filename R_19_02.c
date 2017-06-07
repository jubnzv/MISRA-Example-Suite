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
 * R.19.2
 *
 * The union keyword should not be used
 */

#include "mc3_types.h"
#include "mc3_header.h"

static uint32_t zext ( uint16_t s )
{
   union                /* Non-compliant */
   {
      uint32_t ul;
      uint16_t us;
   } tmp;

   tmp.us = s;
   return tmp.ul;       /* unspecified value */
}


void R_19_2 ( void )
{
  uint32_t x = zext ( 3u );

  use_uint32 ( x );
}

/* end of R_19_02.c */

