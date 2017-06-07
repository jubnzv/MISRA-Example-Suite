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
 * R.21.8
 *
 * The Standard Library functions abort, exit, getenv and system of <stdlib.h>
 * shall not be used
 */

#include "mc3_types.h"
#include "mc3_header.h"
#include <stdlib.h>

void R_21_8 ( void )
{
     int32_t status = 0;
     char_t * env;

     env = getenv ( "path" );        /* Non-compliant  */

     if (env != NULL)
     {
        status = system ( env );
                                    /* Non-compliant */
        use_char_ptr ( env );
     }

     if ( status == 0 )
     {
       abort ( );                   /* Non-compliant  */
     }

     if ( status == 1 )
     {
       exit ( status );            /* Non-compliant */
     }

}
   /* This function has 3 points of exit and breaks R.15.5 */

/* end of R_21_08.c */

