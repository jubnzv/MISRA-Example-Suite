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
 * mc3_header.h
 *
 */

#ifndef MC3_HEADER_H_
#define MC3_HEADER_H_


extern bool get_bool ( void );
extern char_t get_char ( void );
extern int8_t get_int8 ( void );
extern int16_t get_int16 ( void );
extern int32_t get_int32 ( void );
extern int64_t get_int64 ( void );
extern uint8_t get_uint8 ( void );
extern uint16_t get_uint16 ( void );
extern uint32_t get_uint32 ( void );
extern uint64_t get_uint64 ( void );
extern float32_t get_float32 ( void );
extern float64_t get_float64 ( void );
extern float128_t get_float128 ( void );

extern bool *get_bool_ptr ( void );
extern char_t *get_char_ptr ( void );
extern int8_t *get_int8_ptr ( void );
extern int16_t *get_int16_ptr ( void );
extern int32_t *get_int32_ptr ( void );
extern int64_t *get_int64_ptr ( void );
extern uint8_t *get_uint8_ptr ( void );
extern uint16_t *get_uint16_ptr ( void );
extern uint32_t *get_uint32_ptr ( void );
extern uint64_t *get_uint64_ptr ( void );
extern float32_t *get_float32_ptr ( void );
extern float64_t *get_float64_ptr ( void );
extern float128_t *get_float128_ptr ( void );
extern enum_t get_enum ( void );

/* Functions that use a variable */

extern void use_bool ( bool use_bool_param );
extern void use_char ( char_t use_char_param );
extern void use_int8 ( int8_t use_int8_param );
extern void use_int16 ( int16_t use_int16_param );
extern void use_int32 ( int32_t use_int32_param );
extern void use_int64 ( int64_t use_int64_param );
extern void use_int128( int128_t use_int128_param );
extern void use_uint8 ( uint8_t use_uint8_param );
extern void use_uint16 ( uint16_t use_uint16_param );
extern void use_uint32 ( uint32_t use_uint32_param );
extern void use_uint64 ( uint64_t use_uint64_param );
extern void use_uint128 ( uint128_t use_uint128_param );
extern void use_float32 ( float32_t use_float32_param );
extern void use_float64 ( float64_t use_float64_param );
extern void use_float128 ( float128_t use_float128_param );

extern void use_void_ptr ( void * void_ptr_param );
extern void use_bool_ptr ( bool *use_bool_ptr_param );
extern void use_char_ptr ( char_t *use_char_ptr_param );
extern void use_int8_ptr ( int8_t *use_int8_ptr_param );
extern void use_int16_ptr ( int16_t *use_int16_ptr_param );
extern void use_int32_ptr ( int32_t *use_int32_ptr_param );
extern void use_int64_ptr ( int64_t *use_int64_ptr_param );
extern void use_uint8_ptr ( uint8_t *use_uint8_ptr_param );
extern void use_uint16_ptr ( uint16_t *use_uint16_ptr_param );
extern void use_uint32_ptr ( uint32_t *use_uint32_ptr_param );
extern void use_uint64_ptr ( uint64_t *use_uint64_ptr_param );
extern void use_float32_ptr ( float32_t *use_float32_ptr_param );
extern void use_float64_ptr ( float64_t *use_float64_ptr_param );
extern void use_float128_ptr ( float128_t *use_float128_ptr_param );


extern void use_const_char_ptr ( const char_t *use_c_char_ptr_param );


extern void use_enum ( enum_t use_enum_param );
extern void use_sizet ( size_t st );
extern void use_ptrdiff ( ptrdiff_t pt );


/* Examples */
extern void R_8_1 ( void );
extern void R_8_2 ( void );
extern void R_8_3 ( void );
extern void R_8_4 ( void );
extern void R_8_5 ( void );
extern void R_8_6 ( void );
extern void R_8_7 ( void );
extern void R_8_8 ( void );
extern void R_8_9 ( void );
extern void R_8_10 ( void );
extern void R_8_11 ( void );
extern void R_8_12 ( void );
extern void R_8_13 ( void );
extern void R_8_14 ( void );
extern void R_8_main_support ( void );
extern void R_9_1 ( void );
extern void R_9_2 ( void );
extern void R_9_3 ( void );
extern void R_9_4 ( void );
extern void R_9_5 ( void );
extern void R_9_main_support ( void );
extern void R_1_main_support ( void );
extern void R_2_1 ( void );
extern void R_2_2 ( void );
extern void R_2_3 ( void );
extern void R_2_4 ( void );
extern void R_2_5 ( void );
extern void R_2_6 ( void );
extern void R_2_7 ( void );
extern void R_2_main_support ( void );
extern void R_3_1 ( void );
extern void R_3_2 ( void );
extern void R_3_main_support ( void );
extern void R_4_1 ( void );
extern void R_4_2 ( void );
extern void R_4_main_support ( void );
extern void R_5_1 ( void );
extern void R_5_2 ( void );
extern void R_5_3 ( void );
extern void R_5_4 ( void );
extern void R_5_5 ( void );
extern void R_5_6 ( void );
extern void R_5_7 ( void );
extern void R_5_8 ( void );
extern void R_5_9 ( void );
extern void R_5_main_support ( void );
extern void R_6_1 ( void );
extern void R_6_2 ( void );
extern void R_6_main_support ( void );
extern void R_7_1 ( void );
extern void R_7_2 ( void );
extern void R_7_3 ( void );
extern void R_7_4 ( void );
extern void R_7_main_support ( void );
extern void R_18_1 ( void );
extern void R_18_2 ( void );
extern void R_18_3 ( void );
extern void R_18_4 ( void );
extern void R_18_5 ( void );
extern void R_18_6 ( void );
extern void R_18_7 ( void );
extern void R_18_8 ( void );
extern void R_18_main_support ( void );
extern void R_19_1 ( void );
extern void R_19_2 ( void );
extern void R_19_main_support ( void );
extern void R_12_1 ( void );
extern void R_12_2 ( void );
extern void R_12_3 ( void );
extern void R_12_4 ( void );
extern void R_12_5 ( void );
extern void R_12_main_support ( void );
extern void R_13_1 ( void );
extern void R_13_2 ( void );
extern void R_13_3 ( void );
extern void R_13_4 ( void );
extern void R_13_5 ( void );
extern void R_13_6 ( void );
extern void R_13_main_support ( void );
extern void R_10_1 ( void );
extern void R_10_2 ( void );
extern void R_10_3 ( void );
extern void R_10_4 ( void );
extern void R_10_5 ( void );
extern void R_10_6 ( void );
extern void R_10_7 ( void );
extern void R_10_8 ( void );
extern void R_10_main_support ( void );
extern void R_11_1 ( void );
extern void R_11_2 ( void );
extern void R_11_3 ( void );
extern void R_11_4 ( void );
extern void R_11_5 ( void );
extern void R_11_6 ( void );
extern void R_11_7 ( void );
extern void R_11_8 ( void );
extern void R_11_9 ( void );
extern void R_11_main_support ( void );
extern void R_16_1 ( void );
extern void R_16_2 ( void );
extern void R_16_3 ( void );
extern void R_16_4 ( void );
extern void R_16_5 ( void );
extern void R_16_6 ( void );
extern void R_16_7 ( void );
extern void R_16_main_support ( void );
extern void R_17_1 ( void );
extern void R_17_2 ( void );
extern void R_17_3 ( void );
extern void R_17_4 ( void );
extern void R_17_5 ( void );
extern void R_17_6 ( void );
extern void R_17_7 ( void );
extern void R_17_8 ( void );
extern void R_17_main_support ( void );
extern void R_14_1 ( void );
extern void R_14_2 ( void );
extern void R_14_3 ( void );
extern void R_14_4 ( void );
extern void R_14_main_support ( void );
extern void R_15_1 ( void );
extern void R_15_2 ( void );
extern void R_15_3 ( void );
extern void R_15_4 ( void );
extern void R_15_5 ( void );
extern void R_15_6 ( void );
extern void R_15_7 ( void );
extern void R_15_main_support ( void );
extern void D_2_main_support ( void );
extern void D_3_main_support ( void );
extern void D_1_main_support ( void );
extern void D_4_1 ( void );
extern void D_4_3 ( void );
extern void D_4_4 ( void );
extern void D_4_5 ( void );
extern void D_4_6 ( void );
extern void D_4_7 ( void );
extern void D_4_8 ( void );
extern void D_4_9 ( void );
extern void D_4_10 ( void );
extern void D_4_11 ( void );
extern void D_4_12 ( void );
extern void D_4_13 ( void );
extern void D_4_14 ( void );
extern void D_4_main_support ( void );
extern void R_22_1 ( void );
extern void R_22_2 ( void );
extern void R_22_3 ( void );
extern void R_22_4 ( void );
extern void R_22_5 ( void );
extern void R_22_6 ( void );
extern void R_22_7 ( void );
extern void R_22_8 ( void );
extern void R_22_9 ( void );
extern void R_22_10 ( void );
extern void R_22_main_support ( void );
extern void R_21_1 ( void );
extern void R_21_2 ( void );
extern void R_21_3 ( void );
extern void R_21_4 ( void );
extern void R_21_5 ( void );
extern void R_21_6 ( void );
extern void R_21_7 ( void );
extern void R_21_8 ( void );
extern void R_21_9 ( void );
extern void R_21_10 ( void );
extern void R_21_11 ( void );
extern void R_21_12 ( void );
extern void R_21_13 ( void );
extern void R_21_14 ( void );
extern void R_21_15 ( void );
extern void R_21_16 ( void );
extern void R_21_17 ( void );
extern void R_21_18 ( void );
extern void R_21_19 ( void );
extern void R_21_20 ( void );
extern void R_21_main_support ( void );
extern void R_20_1 ( void );
extern void R_20_2 ( void );
extern void R_20_3 ( void );
extern void R_20_4 ( void );
extern void R_20_5 ( void );
extern void R_20_6 ( void );
extern void R_20_7 ( void );
extern void R_20_8 ( void );
extern void R_20_9 ( void );
extern void R_20_10 ( void );
extern void R_20_11 ( void );
extern void R_20_12 ( void );
extern void R_20_13 ( void );
extern void R_20_14 ( void );
extern void R_20_main_support ( void );


#endif /* MC3_HEADER_H_ */
