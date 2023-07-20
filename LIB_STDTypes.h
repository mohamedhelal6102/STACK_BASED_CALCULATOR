#ifndef LIB_STDTYPES_H_
#define LIB_STDTYPES_H_

typedef unsigned char u8;
typedef unsigned char * pu8;

typedef signed char s8;
typedef signed char * ps8;

typedef unsigned int u16;
typedef unsigned int * pu16;

typedef signed int s16;
typedef signed int * ps16;

typedef signed long int s32;
typedef signed long int * ps32;

typedef unsigned long int u32;
typedef unsigned long int * pu32;

typedef unsigned long long int u64;
typedef unsigned long long int * pu64;

typedef signed long long int s64;
typedef signed long long int * ps64;

typedef float  f32;
typedef float * pf32;

typedef double f64;
typedef double* pf64;

#define NULL ((void*)0)

#define u32MAX_VAL  0xFFFFFFFF

typedef enum
{
	LSTY_EXECUTED_SUCCESSFULLY = 0,
	LSTY_OUT_OF_RANGE = 1,
	LSTY_NULL_POINTER = 2,
	LSTY_READ_ERROR = 3,
	LSTY_WRITE_ERROR = 4,
	LSTY_NOK = 5
} tenumFncErrorState ;

#endif



