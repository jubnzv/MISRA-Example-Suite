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
 * R.18.7
 *
 * Flexible array members shall not be declared
 */

#include "mc3_types.h"
#include "mc3_header.h"
#include <stdlib.h>

struct sdata
{
   uint16_t len;
   uint32_t data[ ];   /* Non-compliant  */
};


static struct sdata * copy ( const struct sdata *s1 )
{
   struct sdata *s2;

   s2 = ( struct sdata * ) malloc ( sizeof(struct sdata) + ( ( s1->len ) * sizeof ( uint32_t ) ) );
         /* breaks R.21.3 */

   if ( s2 != NULL )
   {
     *s2 = *s1; /* only copies s1->len */
   }
   return s2;
}


void R_18_7 ( void )
{
  struct sdata str;
  struct sdata *ss1 = &str;
  struct sdata *ss2 = copy ( ss1 );

  if (ss2 != NULL)
  {
    use_uint16 ( ss2->len );
  }
}

/* end of R_18_07.c */
