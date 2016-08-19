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
 
#ifndef _ORG_LABCRYPTO_ABETTOR__C__SCARD_H_
#define _ORG_LABCRYPTO_ABETTOR__C__SCARD_H_

#if defined _WIN32
#include <winscard.h>
#include <scarderr.h>
#else
#include <PCSC/wintypes.h>
#include <PCSC/winscard.h>
#include <PCSC/reader.h>
#endif

#include <org/labcrypto/abettor/types.h>

// #define SCARD_SIMULATION 1

#ifdef __cplusplus
extern "C" {
#endif

typedef SCARDHANDLE ORG_LABCRYPTO_ABETTOR__scard__handle;
typedef ORG_LABCRYPTO_ABETTOR__scard__handle PTR ORG_LABCRYPTO_ABETTOR__scard__handle_ptr;
typedef SCARDCONTEXT ORG_LABCRYPTO_ABETTOR__scard__context;
typedef ORG_LABCRYPTO_ABETTOR__scard__context PTR ORG_LABCRYPTO_ABETTOR__scard__context_ptr;


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__scard__open_context (
  ORG_LABCRYPTO_ABETTOR__scard__context_ptr /* Pointer to context */
);


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__scard__close_context (
  ORG_LABCRYPTO_ABETTOR__scard__context /* Context */
);


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__scard__enumerate_smart_cards (
  ORG_LABCRYPTO_ABETTOR__scard__context   /* Context */,
  ORG_LABCRYPTO_ABETTOR_string_ptr_ptr   /* Pointer to array of scard names */,
  ORG_LABCRYPTO_ABETTOR_uint32_ptr       /* Pointer to number of scards */
);


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__scard__connect_card (
  ORG_LABCRYPTO_ABETTOR__scard__context       /* Context */,
  ORG_LABCRYPTO_ABETTOR_string               /* Name of the card */,
  ORG_LABCRYPTO_ABETTOR__scard__handle_ptr    /* Pointer to scard handle */
);


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__scard__disconnect_card (
  ORG_LABCRYPTO_ABETTOR__scard__handle   /* Handle to scard */
);


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__scard__transmit (
  ORG_LABCRYPTO_ABETTOR__scard__handle   /* Handle to scard */,
  ORG_LABCRYPTO_ABETTOR_data            /* Send buffer */,
  ORG_LABCRYPTO_ABETTOR_uint32          /* Send buffer length */,
  ORG_LABCRYPTO_ABETTOR_data            /* Receive buffer */,
  ORG_LABCRYPTO_ABETTOR_uint32_ptr      /* Pointer to receive buffer length */
);


#ifdef __cplusplus
}
#endif

#endif