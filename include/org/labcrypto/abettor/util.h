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
 
#ifndef _ORG_LABCRYPTO_ABETTOR__C__UTIL_UTIL_H_
#define _ORG_LABCRYPTO_ABETTOR__C__UTIL_UTIL_H_

#include <stdlib.h>
#include <stdio.h>

#include <org/labcrypto/abettor/types.h>


#ifdef __cplusplus
extern "C" {
#endif


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__util__print_array (
  ORG_LABCRYPTO_ABETTOR_string     /* Title */,
  ORG_LABCRYPTO_ABETTOR_data       /* Array to print */, 
  ORG_LABCRYPTO_ABETTOR_uint32     /* Array length */
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__util__copy_array (
  ORG_LABCRYPTO_ABETTOR_data       /* Destination */,
  ORG_LABCRYPTO_ABETTOR_data       /* Source */, 
  ORG_LABCRYPTO_ABETTOR_uint32     /* Start index */, 
  ORG_LABCRYPTO_ABETTOR_uint32     /* Number of bytes to be copied */
);


ORG_LABCRYPTO_ABETTOR_bool
ORG_LABCRYPTO_ABETTOR__util__compare_data (
  ORG_LABCRYPTO_ABETTOR_data      /* First buffer */, 
  ORG_LABCRYPTO_ABETTOR_uint32    /* First buffer length */, 
  ORG_LABCRYPTO_ABETTOR_data      /* Second buffer */,
  ORG_LABCRYPTO_ABETTOR_uint32    /* Second buffer length */
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__util__concat_data (
  ORG_LABCRYPTO_ABETTOR_data      /* Destination buffer */,    
  ORG_LABCRYPTO_ABETTOR_uint32    /* Start index in destination buffer */,                      
  ORG_LABCRYPTO_ABETTOR_data      /* Source buffer */,
  ORG_LABCRYPTO_ABETTOR_uint32    /* Source buffer length */
);


ORG_LABCRYPTO_ABETTOR_string
ORG_LABCRYPTO_ABETTOR__util__trim_string (
  ORG_LABCRYPTO_ABETTOR_string     /* String to trim */
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__util__xor (
  ORG_LABCRYPTO_ABETTOR_data      /* Destination buffer */,    
  ORG_LABCRYPTO_ABETTOR_uint32    /* Destination buffer length */,                      
  ORG_LABCRYPTO_ABETTOR_data      /* Source buffer */
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__util__increment (
  ORG_LABCRYPTO_ABETTOR_data    /* Number */,
  ORG_LABCRYPTO_ABETTOR_uint32  /* Number of bytes */
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__util__make_zero (
  ORG_LABCRYPTO_ABETTOR_data       /* Buffer */,
  ORG_LABCRYPTO_ABETTOR_uint32     /* Buffer length */
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__util__pad (
  ORG_LABCRYPTO_ABETTOR_data       /* Buffer */,
  ORG_LABCRYPTO_ABETTOR_uint32     /* Buffer length */,
  ORG_LABCRYPTO_ABETTOR_data_ptr   /* Pointer to padded buffer */,
  ORG_LABCRYPTO_ABETTOR_uint32_ptr /* Pointer to padded buffer length */
);


ORG_LABCRYPTO_ABETTOR_string
ORG_LABCRYPTO_ABETTOR__util__array_to_string (
  ORG_LABCRYPTO_ABETTOR_data       /* Array */, 
  ORG_LABCRYPTO_ABETTOR_uint32     /* Array length */
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__util__to_upper (
  ORG_LABCRYPTO_ABETTOR_string
);


#ifdef __cplusplus
}
#endif

#endif
