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
 * D.4.1
 *
 * Run-time failures shall be minimized
 */

#include "D_04_01.h"

#define MSG_HEADER_SIZE 128
#define MAX_MSG_SIZE 128

 /* Given a pointer to a message, check the message header and return
 * a pointer to the body of the message or NULL if the message is
 * invalid
 */

static const char * msg_body ( const char *msg )
{
   const char *body = NULL;
   if ( msg != NULL )
   {
      if ( msg_header_valid ( msg ) )
      {
         body = &msg[ MSG_HEADER_SIZE ];
      }
   }
   return body;
}


void D_4_1 ( void )
 {
    float32_t f1 = 1E38f;
    float32_t f2 = 10.0f;
    float32_t f3 = 0.1f;
    float32_t f4 = ( f1 * f2 ) * f3;  /* (f1 * f2) will overflow           */
    float32_t f5 = f1 * ( f2 * f3 );  /* no overflow because (f2 * f3)
                                       * is (approximately) 1
                                       */

    if ( ( f3 >= 0.0f ) && ( f3 <= 1.0f ) )
    {
      f4 = f3 * 100.0f;             /* no overflow because f3 is known
                                     * to be in range 0..1 so the result
                                     * of the multiplication will fit
                                     * in type float32_t
                                     */
    }

    use_float32 ( f4 );
    use_float32 ( f5 );


          char msg_buffer [ MAX_MSG_SIZE ] = "message";
    const char *payload;

    payload = msg_body ( msg_buffer );

    if ( payload != NULL ) /* Check if there is a payload */
    {
         /* Process the payload                                           */
    }

 }

/* end of D_04_01.c */

