/*  The MIT License (MIT)
 *
 *  Copyright (c) 2015 LabCrypto Org.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */
 
#ifndef _ORG_LABCRYPTO_ABETTOR__C__TYPES_H_
#define _ORG_LABCRYPTO_ABETTOR__C__TYPES_H_

#include <org/labcrypto/abettor/error.h>

#ifdef _MSC_VER
typedef __int8 int8_t;
typedef unsigned __int8 uint8_t;
typedef __int16 int16_t;
typedef unsigned __int16 uint16_t;
typedef __int32 int32_t;
typedef unsigned __int32 uint32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#else
#include <stdint.h>
#endif


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

#define IN
#define OUT
#ifndef WIN32
#define INPUT
#endif

typedef void ORG_LABCRYPTO_ABETTOR_void;
typedef int8_t ORG_LABCRYPTO_ABETTOR_int8;
typedef int16_t ORG_LABCRYPTO_ABETTOR_int16;
typedef int32_t ORG_LABCRYPTO_ABETTOR_int32;
typedef int64_t ORG_LABCRYPTO_ABETTOR_int64;
typedef uint8_t ORG_LABCRYPTO_ABETTOR_uint8;
typedef uint16_t ORG_LABCRYPTO_ABETTOR_uint16;
typedef uint32_t ORG_LABCRYPTO_ABETTOR_uint32;
typedef uint64_t ORG_LABCRYPTO_ABETTOR_uint64;
typedef char ORG_LABCRYPTO_ABETTOR_char;
typedef ORG_LABCRYPTO_ABETTOR_uint8 ORG_LABCRYPTO_ABETTOR_bool;
typedef double ORG_LABCRYPTO_ABETTOR_real;
typedef float ORG_LABCRYPTO_ABETTOR_float;
typedef ORG_LABCRYPTO_ABETTOR_uint8 ORG_LABCRYPTO_ABETTOR_utf16_char[2];

typedef ORG_LABCRYPTO_ABETTOR_uint32 ORG_LABCRYPTO_ABETTOR_counter;
typedef ORG_LABCRYPTO_ABETTOR_uint32 ORG_LABCRYPTO_ABETTOR_size;
typedef ORG_LABCRYPTO_ABETTOR_uint32 ORG_LABCRYPTO_ABETTOR_count;
typedef ORG_LABCRYPTO_ABETTOR_int64 ORG_LABCRYPTO_ABETTOR_unix_epoch;
typedef ORG_LABCRYPTO_ABETTOR_size ORG_LABCRYPTO_ABETTOR_length;
typedef ORG_LABCRYPTO_ABETTOR_uint32 ORG_LABCRYPTO_ABETTOR_pixel;

typedef ORG_LABCRYPTO_ABETTOR_counter PTR ORG_LABCRYPTO_ABETTOR_counter_ptr;
typedef ORG_LABCRYPTO_ABETTOR_size PTR ORG_LABCRYPTO_ABETTOR_size_ptr;
typedef ORG_LABCRYPTO_ABETTOR_count PTR ORG_LABCRYPTO_ABETTOR_count_ptr;
typedef ORG_LABCRYPTO_ABETTOR_unix_epoch PTR ORG_LABCRYPTO_ABETTOR_unix_epoch_ptr;
typedef ORG_LABCRYPTO_ABETTOR_length PTR ORG_LABCRYPTO_ABETTOR_length_ptr;

typedef ORG_LABCRYPTO_ABETTOR_void PTR ORG_LABCRYPTO_ABETTOR_void_ptr;
typedef ORG_LABCRYPTO_ABETTOR_bool PTR ORG_LABCRYPTO_ABETTOR_bool_ptr;
typedef ORG_LABCRYPTO_ABETTOR_uint32 PTR ORG_LABCRYPTO_ABETTOR_uint32_ptr;
typedef ORG_LABCRYPTO_ABETTOR_int32 PTR ORG_LABCRYPTO_ABETTOR_int32_ptr; 
typedef ORG_LABCRYPTO_ABETTOR_char PTR ORG_LABCRYPTO_ABETTOR_char_ptr;

typedef unsigned char ORG_LABCRYPTO_ABETTOR_byte;
typedef ORG_LABCRYPTO_ABETTOR_byte PTR ORG_LABCRYPTO_ABETTOR_byte_ptr;
typedef ORG_LABCRYPTO_ABETTOR_byte PTR ORG_LABCRYPTO_ABETTOR_data;
typedef ORG_LABCRYPTO_ABETTOR_data PTR ORG_LABCRYPTO_ABETTOR_data_ptr;

typedef ORG_LABCRYPTO_ABETTOR_char PTR ORG_LABCRYPTO_ABETTOR_string;
typedef ORG_LABCRYPTO_ABETTOR_utf16_char PTR ORG_LABCRYPTO_ABETTOR_utf16_string;
typedef ORG_LABCRYPTO_ABETTOR_string PTR ORG_LABCRYPTO_ABETTOR_string_ptr;
typedef ORG_LABCRYPTO_ABETTOR_string_ptr PTR ORG_LABCRYPTO_ABETTOR_string_ptr_ptr;
typedef ORG_LABCRYPTO_ABETTOR_string ORG_LABCRYPTO_ABETTOR_path;
typedef ORG_LABCRYPTO_ABETTOR_path PTR ORG_LABCRYPTO_ABETTOR_path_ptr;
typedef ORG_LABCRYPTO_ABETTOR_string ORG_LABCRYPTO_ABETTOR_password;

typedef ORG_LABCRYPTO_ABETTOR_int32 ORG_LABCRYPTO_ABETTOR_socket_fd;
typedef ORG_LABCRYPTO_ABETTOR_string ORG_LABCRYPTO_ABETTOR_hostname;
typedef ORG_LABCRYPTO_ABETTOR_string ORG_LABCRYPTO_ABETTOR_ip_v4_address;
typedef ORG_LABCRYPTO_ABETTOR_ip_v4_address ORG_LABCRYPTO_ABETTOR_ip_address;
typedef ORG_LABCRYPTO_ABETTOR_string ORG_LABCRYPTO_ABETTOR_ip_v6_address;
typedef ORG_LABCRYPTO_ABETTOR_uint16 ORG_LABCRYPTO_ABETTOR_port;
typedef ORG_LABCRYPTO_ABETTOR_string ORG_LABCRYPTO_ABETTOR_string_port;

typedef ORG_LABCRYPTO_ABETTOR_uint32 ORG_LABCRYPTO_ABETTOR_result;

typedef struct {
  ORG_LABCRYPTO_ABETTOR_data        image_data;
  ORG_LABCRYPTO_ABETTOR_length      image_data_length;
} ORG_LABCRYPTO_ABETTOR_image;
typedef ORG_LABCRYPTO_ABETTOR_image PTR ORG_LABCRYPTO_ABETTOR_image_ptr;


#ifdef __cplusplus
}
#endif

#endif
