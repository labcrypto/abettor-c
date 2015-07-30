#ifndef _NAEEM_UTIL_H_
#define _NAEEM_UTIL_H_

#include <stdlib.h>
#include <stdio.h>

#include <naeem/types.h>


#ifdef __cplusplus
extern "C" {
#endif


NAEEM_void
NAEEM_util_print_array (NAEEM_string     /* Title */,
                        NAEEM_data       /* Array to print */, 
                        NAEEM_uint32     /* Array length */);


NAEEM_void
NAEEM_util_copy_array (NAEEM_data       /* Destination */,
                       NAEEM_data       /* Source */, 
                       NAEEM_uint32     /* Start index */, 
                       NAEEM_uint32     /* Number of bytes to be copied */);


NAEEM_bool
NAEEM_util_compare_data (NAEEM_data      /* First buffer */, 
                         NAEEM_uint32    /* First buffer length */, 
                         NAEEM_data      /* Second buffer */,
                         NAEEM_uint32    /* Second buffer length */);


NAEEM_void
NAEEM_util_concat_data (NAEEM_data      /* Destination buffer */,    
                        NAEEM_uint32    /* Start index in destination buffer */,                      
                        NAEEM_data      /* Source buffer */,
                        NAEEM_uint32    /* Source buffer length */);


NAEEM_string
NAEEM_util_trim_string (NAEEM_string     /* String to trim */);


NAEEM_void
NAEEM_util_xor (NAEEM_data      /* Destination buffer */,    
                NAEEM_uint32    /* Destination buffer length */,                      
                NAEEM_data      /* Source buffer */);


NAEEM_void
NAEEM_util_increment (NAEEM_data    /* Number */,
                      NAEEM_uint32  /* Number of bytes */);


NAEEM_void
NAEEM_util_make_zero (NAEEM_data       /* Buffer */,
                      NAEEM_uint32     /* Buffer length */);


NAEEM_void
NAEEM_util_pad (NAEEM_data       /* Buffer */,
                NAEEM_uint32     /* Buffer length */,
                NAEEM_data_ptr   /* Pointer to padded buffer */,
                NAEEM_uint32_ptr /* Pointer to padded buffer length */);


#ifdef __cplusplus
}
#endif

#endif
