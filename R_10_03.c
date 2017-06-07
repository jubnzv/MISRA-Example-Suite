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
 * R.10.3
 *
 * The value of an expression shall not be assigned to an object with a
 * narrower essential type or of a different essential type category
 */

#include "mc3_types.h"
#include "mc3_header.h"

/* Defined in mc3_types.h                                 */
/* typedef enum enum_tag { ENUM_0, ENUM_1, ENUM_2 } enum_t */

/* anonymous enum type
   When signed char is implemented in 8 bits:
     K1 has essentially signed char type,
     K2 has essentially signed short type */
enum       { K1 = 1, K2 = 128 };

static uint8_t foo1 ( uint16_t x )
{
   return x;                  /* Non-Compliant - uint16_t to uint8_t */
}

void R_10_3 ( void )
{
   uint8_t u8b = get_uint8 ( );
   uint8_t u8c = get_uint8 ( );
   uint8_t u8d = get_uint8 ( );
   int8_t s8a;
   const uint8_t *pu8a;
   const uint8_t *pu8b = & u8b;

   uint16_t u16a = get_uint16 ( );
   uint32_t u32a;
   int32_t s32a = get_int32 ( );

   char cha = 'a';

   enum_t ena;

   uint8_t u8a  = 0;              /* Compliant By exception              */
   bool_t  flag = ( bool_t ) 0;
   bool_t  set  = true;
   bool_t  get  = ( u8b > u8c );
   use_bool ( flag );
   use_bool ( get );
   use_bool ( set );
   use_uint8 ( u8a );

   ena  = ENUM_1;
   use_enum ( ena );
   s8a  = K1;            /* Constant value fits    */
   use_int8 ( s8a );
   u8a  = 2;             /* Compliant By exception               */
   use_uint8( u8a );
   u8a  = 2 * 24;        /* Compliant By exception               */
   use_uint8( u8a );
   cha += 1;             /* cha = cha + 1 assigns character to character */
   use_char( cha );

   pu8a = pu8b;                  /* Compliant - Same essential type            */
   use_uint8( *pu8a );
   u8a = u8b + u8c + u8d;        /* Compliant - Same essential type */
   use_uint8( u8a );
   u8a = ( uint8_t ) s8a;        /* Compliant - Cast gives same essential type */
   use_uint8( u8a );

   u32a = u16a;                  /* Compliant - Assignment to a wider essential type */
   use_uint32 ( u32a );
   u32a = 2U + 125U;             /* Compliant - Assignment to a wider essential type */
   use_uint32 ( u32a );
   use_uint16 ( u8a );           /*  Compliant - Assignment to a wider essential type */
   use_uint16 ( u8a + u16a );    /*  Compliant - Assignment to same essential type    */

   uint8_t u8f = 1.0f;           /* Non-compliant - unsigned and floating */
   use_uint8 ( u8f );
   bool_t bla = 0;               /* Non-compliant - boolean and signed */
   use_bool ( bla );
   cha = 7;                      /* Non-compliant - character and signed */
   use_char( cha );
   u8a = 'a';                    /* Non-compliant - unsigned and character */
   use_uint8( u8a );
   u8b = 1 - 2;                  /* Non-compliant - unsigned and signed */
   use_uint8( u8b );
   u8c += 'a';                   /* Non-compliant - u8c = u8c + 'a' assigns character to unsigned */
   use_uint8( u8c );
   use_uint32 ( s32a );          /* Non-compliant - signed and unsigned */

   s8a = K2;                    /*  Non-compliant - Constant value does not fit */
   use_int8( s8a );
   u16a = u32a;                 /*  Non-compliant - uint32_t to uint16_t */
   use_uint16 ( u16a );
   use_uint16 ( u32a );         /*  Non-compliant - uint32_t to uint16_t */

   s8a  = -123L;                /*  Non-compliant - signed long to int8_t */
   use_int8 ( s8a );

   u8a = 6L;                    /* Non-compliant - signed long to uint8_t */
                                /* Standard Type has rank greater than int,
                                 * so exception does not apply */
   use_uint8( u8a );

   /* integer constant expression from + with value 5U and UTLR of unsigned char */
   u8a = (uint16_t)2U + (uint16_t)3U;  /* Compliant */
   use_uint8( u8a );

   /* integer constant expression from + with value 100000U and UTLR of unsigned int */
   u16a = (uint16_t)50000U + (uint16_t)50000U; /*  Non-compliant */
   use_uint16( u16a );

   /* Top-level cast returns C standard type of unsigned short */
   u8a = (uint16_t)(2U + 3U);  /*  Non-compliant */
   use_uint8( u8a );

   ( void ) foo1 (u16a);

}

/* end of R_10_03.c */
