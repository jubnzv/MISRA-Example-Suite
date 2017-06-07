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
 * R.20.3
 *
 * The #include directive shall be followed by either a <filename> or  
 * "filename" sequence
 */

#define HEADER "mc3_types.h"
#include HEADER


/* Following statements are Non-compliant and may not compile */
/* Consequential parsing errors may occur in analysis       */

#include another.h           /* Non-compliant */

#define BASE "R_20_03"
#define EXT  ".h"
#include BASE EXT            /* Non-compliant  */
                             /* strings are concatenated after preprocessing */


#define FILENAME file2.h
#include FILENAME            /* Non-compliant */

#include"mc3_header.h"             /* Compliant - space not required */
#include/* a comment */"R_20_03.h" /* Compliant - comment permitted  */

void R_20_3 ( void )
{
   use_int32 ( 3 );
}


/* end of R_20_03.c */

