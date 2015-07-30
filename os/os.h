#ifndef _NAEEM_OS_H_
#define _NAEEM_OS_H_

#include <stdlib.h>
#include <stdio.h>

#include <naeem/types.h>


#ifdef __cplusplus
extern "C" {
#endif


NAEEM_void
NAEEM_os_read_file (FILE *             /* FILE pointer */, 
                    NAEEM_data_ptr     /* Pointer to buffer */, 
                    NAEEM_uint32_ptr   /* Pointer to buffer size */);


NAEEM_void
NAEEM_os_read_file_with_path (NAEEM_string    /* Base directory */,
                              NAEEM_string    /* File name */,
                              NAEEM_data_ptr     /* Pointer to buffer */, 
                              NAEEM_uint32_ptr   /* Pointer to buffer size */);


NAEEM_void
NAEEM_os_mkdir (NAEEM_string    /* Direcotry name */);


NAEEM_void
NAEEM_os_write_to_file (NAEEM_string    /* Base directory */,
                        NAEEM_string    /* File name */,
                        NAEEM_data      /* Buffer */,
                        NAEEM_uint32    /* Bufer length */);


#ifdef __cplusplus
}
#endif

#endif