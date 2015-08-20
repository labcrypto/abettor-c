#ifndef _NAEEM_CORELIBS__TYPES_H_
#define _NAEEM_CORELIBS__TYPES_H_

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
typedef char NAEEM_char;
typedef unsigned int NAEEM_bool;
typedef double NAEEM_real;

typedef NAEEM_uint32 NAEEM_counter;
typedef NAEEM_uint32 NAEEM_size;
typedef NAEEM_uint32 NAEEM_count;
typedef NAEEM_int64 NAEEM_unix_epoch;
typedef NAEEM_size NAEEM_length;
typedef NAEEM_uint32 NAEEM_pixel;

typedef NAEEM_counter PTR NAEEM_counter_ptr;
typedef NAEEM_size PTR NAEEM_size_ptr;
typedef NAEEM_count PTR NAEEM_count_ptr;
typedef NAEEM_unix_epoch PTR NAEEM_unix_epoch_ptr;
typedef NAEEM_length PTR NAEEM_length_ptr;

typedef NAEEM_void PTR NAEEM_void_ptr;
typedef NAEEM_bool PTR NAEEM_bool_ptr;
typedef NAEEM_uint32 PTR NAEEM_uint32_ptr;
typedef NAEEM_int32 PTR NAEEM_int32_ptr; 
typedef NAEEM_char PTR NAEEM_char_ptr;

typedef unsigned char NAEEM_byte;
typedef NAEEM_byte PTR NAEEM_byte_ptr;
typedef NAEEM_byte PTR NAEEM_data;
typedef NAEEM_data PTR NAEEM_data_ptr;

typedef NAEEM_char PTR NAEEM_string;
typedef NAEEM_string PTR NAEEM_string_ptr;
typedef NAEEM_string_ptr PTR NAEEM_string_ptr_ptr;
typedef NAEEM_string NAEEM_path;
typedef NAEEM_path PTR NAEEM_path_ptr;
typedef NAEEM_string NAEEM_password;

typedef NAEEM_string NAEEM_ip_address;
typedef NAEEM_uint32 NAEEM_port;

typedef NAEEM_uint32 NAEEM_result;

typedef struct {
  NAEEM_data        image_data;
  NAEEM_length      image_data_length;
} NAEEM_image;
typedef NAEEM_image PTR NAEEM_image_ptr;


#ifdef __cplusplus
}
#endif

#endif
