#ifndef _NAEEM_CORELIBS__UNICODE_UNICODE_H_
#define _NAEEM_CORELIBS__UNICODE_UNICODE_H_

#include <naeem/types.h>


#ifdef __cplusplus
extern "C" {
#endif


NAEEM_result
NAEEM_unicode__utf8_to_utf16(NAEEM_string        /* Source UTF-8 string */,
                             NAEEM_string_ptr    /* Destination UTF-16 string */,
                             NAEEM_length_ptr    /* Pointer to destination length */);


#ifdef __cplusplus
}
#endif


#endif