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

#include "D_04_13.h"


static int16_t x16;

/* mutex_lock and mutex_unlock designed to work as a pair */
static void fpair ( void )
{
  mutex_t m = mutex_lock ( );
  if ( x16 > 0 )
  {
    mutex_unlock ( m );
  }
  else
  {
    /* Mutex not unlocked on this path */
  }
}

void D_4_13 ( void )
{
   x16 = get_int16 ( );
   fpair ( );
}
/* end of D_04_13.c */
