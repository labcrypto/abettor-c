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
 
#ifndef _ORG_LABCRYPTO_ABETTOR__C__FS_H_
#define _ORG_LABCRYPTO_ABETTOR__C__FS_H_

#include <stdlib.h>
#include <stdio.h>

#include <org/labcrypto/abettor/types.h>


#ifdef __cplusplus
extern "C" {
#endif


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__fs__read_file (
  FILE *                             /* FILE pointer */, 
  ORG_LABCRYPTO_ABETTOR_data_ptr     /* Pointer to buffer */, 
  ORG_LABCRYPTO_ABETTOR_uint32_ptr   /* Pointer to buffer size */
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__fs__read_file_with_full_path (
  ORG_LABCRYPTO_ABETTOR_path         /* File path */, 
  ORG_LABCRYPTO_ABETTOR_data_ptr     /* Pointer to buffer */, 
  ORG_LABCRYPTO_ABETTOR_uint32_ptr   /* Pointer to buffer size */
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__fs__read_file_into_buffer (
  ORG_LABCRYPTO_ABETTOR_path         /* File path */, 
  ORG_LABCRYPTO_ABETTOR_data         /* Pre-allocated buffer */, 
  ORG_LABCRYPTO_ABETTOR_uint32       /* Start index in buffer */
);



ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__fs__read_file_with_base_dir (
  ORG_LABCRYPTO_ABETTOR_path         /* Base directory */,
  ORG_LABCRYPTO_ABETTOR_string       /* File name */,
  ORG_LABCRYPTO_ABETTOR_data_ptr     /* Pointer to buffer */, 
  ORG_LABCRYPTO_ABETTOR_uint32_ptr   /* Pointer to buffer size */
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__fs__mkdir (
  ORG_LABCRYPTO_ABETTOR_path         /* Direcotry name */
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__fs__rmdir (
  ORG_LABCRYPTO_ABETTOR_path         /* Direcotry name */
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__fs__write_to_file (
  ORG_LABCRYPTO_ABETTOR_path        /* Base directory */,
  ORG_LABCRYPTO_ABETTOR_string      /* File name */,
  ORG_LABCRYPTO_ABETTOR_data        /* Buffer */,
  ORG_LABCRYPTO_ABETTOR_uint32      /* Bufer length */
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__fs__write_to_file2 (
  ORG_LABCRYPTO_ABETTOR_path       /* File path */,
  ORG_LABCRYPTO_ABETTOR_data       /* Buffer */,
  ORG_LABCRYPTO_ABETTOR_uint32     /* Bufer length */
);


ORG_LABCRYPTO_ABETTOR_bool
ORG_LABCRYPTO_ABETTOR__fs__dir_exists (
  ORG_LABCRYPTO_ABETTOR_path       /* Base directory */
);


ORG_LABCRYPTO_ABETTOR_bool
ORG_LABCRYPTO_ABETTOR__fs__file_exists (
  ORG_LABCRYPTO_ABETTOR_path       /* Base directory */,
  ORG_LABCRYPTO_ABETTOR_string     /* File name */
);


ORG_LABCRYPTO_ABETTOR_bool
ORG_LABCRYPTO_ABETTOR__fs__file_exists2 (
  ORG_LABCRYPTO_ABETTOR_path       /* File path */
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__fs__create_file (
  ORG_LABCRYPTO_ABETTOR_path       /* Base directory */,
  ORG_LABCRYPTO_ABETTOR_string     /* File name */
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__fs__create_file2 (
  ORG_LABCRYPTO_ABETTOR_path      /* File path */
);


ORG_LABCRYPTO_ABETTOR_bool
ORG_LABCRYPTO_ABETTOR__fs__delete_file (
  ORG_LABCRYPTO_ABETTOR_path      /* Base directory */,
  ORG_LABCRYPTO_ABETTOR_string    /* File name */
);


ORG_LABCRYPTO_ABETTOR_bool
ORG_LABCRYPTO_ABETTOR__fs__delete_file2 (
  ORG_LABCRYPTO_ABETTOR_path      /* File path */
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__fs__enum_file_names (
  ORG_LABCRYPTO_ABETTOR_path              /* Base directory */,
  ORG_LABCRYPTO_ABETTOR_string_ptr_ptr    /* Pointer to string array */,
  ORG_LABCRYPTO_ABETTOR_length_ptr        /* Pointer to length */
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__fs__num_files_in_dir (
  ORG_LABCRYPTO_ABETTOR_path              /* Base directory */,
  ORG_LABCRYPTO_ABETTOR_length_ptr        /* Pointer to length */
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__fs__free_file_names (
  ORG_LABCRYPTO_ABETTOR_string_ptr   /* String array */,
  ORG_LABCRYPTO_ABETTOR_length       /* Length of array */
);


ORG_LABCRYPTO_ABETTOR_bool
ORG_LABCRYPTO_ABETTOR__fs__copy_file (
  ORG_LABCRYPTO_ABETTOR_path      /* First base directory */,
  ORG_LABCRYPTO_ABETTOR_string    /* First file name */,
  ORG_LABCRYPTO_ABETTOR_path      /* Second base directory */,
  ORG_LABCRYPTO_ABETTOR_string    /* Second file name */
);


ORG_LABCRYPTO_ABETTOR_bool
ORG_LABCRYPTO_ABETTOR__fs__move_file (
  ORG_LABCRYPTO_ABETTOR_path      /* First base directory */,
  ORG_LABCRYPTO_ABETTOR_string    /* First file name */,
  ORG_LABCRYPTO_ABETTOR_path      /* Second base directory */,
  ORG_LABCRYPTO_ABETTOR_string    /* Second file name */
);


#ifdef __cplusplus
}
#endif

#endif