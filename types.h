#ifndef _NAEEM_TYPES_H_
#define _NAEEM_TYPES_H_

#include <naeem/error.h>


#ifdef __cplusplus
extern "C" {
#endif

#ifndef PTR
#define PTR *
#endif

#ifndef NULL
#define NULL 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

typedef void NAEEM_void;
typedef int NAEEM_int32;
typedef long int NAEEM_int64;
typedef unsigned int NAEEM_uint32;
typedef unsigned long int NAEEM_uint64;
typedef unsigned char NAEEM_char;
typedef unsigned int NAEEM_bool;
typedef double NAEEM_real;

typedef NAEEM_counter NAEEM_uint32;
typedef NAEEM_size NAEEM_uint32;
typedef NAEEM_count NAEEM_uint32;
typedef NAEEM_datetime NAEEM_int64;

typedef NAEEM_bool PTR NAEEM_bool_ptr;
typedef NAEEM_uint32 PTR NAEEM_uint32_ptr;
typedef NAEEM_int32 PTR NAEEM_int32_ptr; 
typedef NAEEM_char PTR NAEEM_char_ptr;

typedef NAEEM_char NAEEM_byte;
typedef NAEEM_byte PTR NAEEM_byte_ptr;
typedef NAEEM_byte PTR NAEEM_data;
typedef NAEEM_data PTR NAEEM_data_ptr;

typedef NAEEM_char PTR NAEEM_string;
typedef NAEEM_string PTR NAEEM_string_ptr;
typedef NAEEM_string_ptr PTR NAEEM_string_ptr_ptr;

typedef NAEEM_uint32 NAEEM_result;

#ifdef __cplusplus
}
#endif

#endif
