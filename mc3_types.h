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
 * MISRA C
 */

#ifndef MC3_TYPES_H
#define MC3_TYPES_H
#include <stddef.h>  /* brings in NULL, size_t, ptrdiff_t, wchar_t */

#if defined ( __STDC_VERSION__ ) && ( __STDC_VERSION__ >= 199901L )/* C99 */

#include <stdint.h>
#include <stdbool.h>
typedef _Bool bool_t;

#else

typedef signed   char           int8_t;
typedef signed   short          int16_t;
typedef signed   int            int32_t;
typedef signed   long           int64_t;
typedef unsigned char           uint8_t;
typedef unsigned short          uint16_t;
typedef unsigned int            uint32_t;
typedef unsigned long           uint64_t;

typedef          int            bool_t;
typedef          int            bool;
enum { false, true };


#endif

typedef          char           char_t;

typedef signed   long long      int128_t;
typedef unsigned long long      uint128_t;

typedef          float          float32_t;
typedef          double         float64_t;
typedef          long double    float128_t;

typedef enum enum_tag { ENUM_0, ENUM_1, ENUM_2 } enum_t;

#endif

/* end of mc3_types.h */
