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
 * R.11.2
 *
 * Conversions shall not be performed between a pointer to incomplete and any
 * other type
 */

#include "mc3_types.h"
#include "mc3_header.h"

#include <stddef.h>  /* To obtain macro NULL */
/* Could also be stdio.h, stdlib.h and others in hosted environments */

struct s;                  /* Incomplete type                        */
struct t;                  /* A different incomplete type            */
extern void use_structs_ptr ( struct s * ps );
extern void use_structt_ptr ( struct t * pt );

extern  struct s *f2 (void);

void R_11_2 ( void )
{
   struct s *sp;
   struct t *tp;
   int16_t  *ip;

   sp = ( struct s * ) 1234;     /* Non-compliant                          */
   ip = ( int16_t  * ) sp;       /* Non-compliant                          */
   tp = ( struct t * ) sp;       /* Non-compliant - casting pointer to a
                                    different incomplete type              */

   sp = NULL;                    /* Compliant - exception                  */

   (void) f2 ( );                 /* Compliant - exception                  */

   use_structs_ptr ( sp );
   use_structt_ptr ( tp );
   use_int16_ptr (ip);
}

/* end of R_11_02.c */
