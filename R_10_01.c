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
 * R.10.1
 *
 * Operands shall not be of an inappropriate essential type
 *
 * Note: Some lines will give consequential R.10.3 warnings
 * on assignment, where the non-compliant expression returns
 * the C standard type. See Appendix D of the guidelines.
 */

#include "mc3_types.h"
#include "mc3_header.h"

/* Defined in mc3_types.h                                 */
/* typedef enum enum_tag { ENUM_0, ENUM_1, ENUM_2 } enum_t */

enum { K1 = 1, K2 = 128 }; /* K1 essentially signed char,
                              K2 essentially signed short */

void R_10_1 ( void )
{
   bool bla = get_bool ( );
   bool blb = get_bool ( );
   bool blc;
   float32_t f32a = get_float32 ( );
   float32_t f32b;
   char cha = get_char ( );
   char chb = get_char ( );
   char chc;
   int8_t s8a = get_int8 ( );
   int8_t s8b;
   int16_t s16a;
   int16_t s16b;
   int32_t s32a;
   uint8_t u8a = get_uint8 ( );
   uint8_t u8b;
   uint16_t u16b = get_uint16 ( );
   enum_t ena = get_enum ( );
   enum_t enb;
   uint8_t *ptr = get_uint8_ptr ( );

   f32b = f32a & 2U;       /* Constraint Error, also breaks R.10.4 */
   use_float32 ( f32b );
   f32b = f32a << 2;       /* Constraint Error */
   use_float32 ( f32b );

   blc = cha && bla;       /* Non-compliant */
   use_bool ( blc );
   enb = ena ? ENUM_1 : ENUM_2;    /* Non-compliant */
   use_enum ( enb );
   s8b = s8a && bla;       /* Non-compliant, returns standard type */
   use_int8 ( s8b );
   enb = u8a ? ENUM_1 : ENUM_2;    /* Non-compliant */
   use_enum ( enb );
   blc = f32a && bla;      /* Non-compliant */
   use_bool ( blc );
   if ( !ptr )             /* Non-compliant - added in TC1 */
   {
     use_bool ( blc );
   }

   blc = bla * blb;        /* Non-compliant, returns standard type */
   use_bool ( blc );
   blc = bla > blb;        /* Non-compliant */
   use_bool ( blc );

   chc = cha & chb;        /* Non-compliant, returns standard type */
   use_char ( chc );
   chc = cha << 1;         /* Non-compliant */
   use_char ( chc );

   ena--;                  /* Non-compliant */
   enb = ena * ENUM_2;     /* Non-compliant, returns standard type */
   use_enum ( enb );

   s8b = s8a & 2;          /* Non-compliant */
   use_int8 ( s8b );
   s16b = 50 << 3U;        /* Non-compliant */
   use_int16 ( s16b );

   u8b = u8a << s8a;       /* Non-compliant */
   use_uint8 ( u8b );
   u8b = u8a << -1;        /* Non-compliant; also breaks R.12.2 */
   use_uint8 ( u8b );

   u8b = -u8a;             /* Non-compliant, returns standard type  */
   use_uint8 ( u8b );

   ena += ENUM_1;          /* Non-compliant, returns standard type */
   use_enum ( ena );

   blc = bla && blb;
   use_bool ( blc );
   u8b = bla ? u8a : u8b;
   use_uint8 ( u8b );

   s32a = cha - chb;
   use_int32 ( s32a );
   blc = cha > chb;
   use_bool ( blc );

   blc = ena > ENUM_1;
   use_bool ( blc );
   s8b =  K1 + s8a;     /* Compliant as K1 from anonymous enum */
   use_int8 ( s8b );

   s16a = s8a + s16b;
   use_int16 ( s16a );
   s8b = -( s8a ) * s8b;
   use_int8 ( s8b );
   blc = s8a > 0;
   use_bool ( blc );
   --s16b;
   use_int16 ( s16b );

   u16b = u8a + u16b;
   use_uint16 ( u16b );
   u8b = u8a & 2U;
   use_uint8 ( u8b );

   blc = u8a > 0U;
   use_bool ( blc );
   u8b = u8a << 2U;
   use_uint8( u8b );
   u8b = u8a << 1;    /* Compliant by exception */
   use_uint8( u8b );

   f32b = f32a + f32b;
   use_float32 ( f32b );
   blc = f32a > 0.0f;
   use_bool ( blc );

   chc =  cha + chb;   /* compliant but breaks R.10.2, returns standard type */
   use_char( chc );
}

/* end of R_10_01.c */
