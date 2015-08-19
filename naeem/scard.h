#ifndef _NAEEM_CORELIBS__SCARD_H_
#define _NAEEM_CORELIBS__SCARD_H_

#if defined _WIN32 || defined __CYGWIN__

#include <winscard.h>
#include <scarderr.h>

#else

#include <PCSC/wintypes.h>
#include <PCSC/winscard.h>
#include <PCSC/reader.h>

#endif

#include <naeem/types.h>

// #define SCARD_SIMULATION 1

#ifdef __cplusplus
extern "C" {
#endif

typedef SCARDHANDLE NAEEM_scard__handle;
typedef NAEEM_scard__handle PTR NAEEM_scard__handle_ptr;
typedef SCARDCONTEXT NAEEM_scard__context;
typedef NAEEM_scard__context PTR NAEEM_scard__context_ptr;


NAEEM_result
NAEEM_scard__open_context (NAEEM_scard__context_ptr /* Pointer to context */);


NAEEM_result
NAEEM_scard__close_context (NAEEM_scard__context /* Context */);


NAEEM_result
NAEEM_scard__enumerate_smart_cards (NAEEM_scard__context   /* Context */,
                                    NAEEM_string_ptr_ptr   /* Pointer to array of scard names */,
                                    NAEEM_uint32_ptr       /* Pointer to number of scards */);


NAEEM_result
NAEEM_scard__connect_card (NAEEM_scard__context       /* Context */,
                           NAEEM_string               /* Name of the card */,
                           NAEEM_scard__handle_ptr    /* Pointer to scard handle */);


NAEEM_result
NAEEM_scard__disconnect_card (NAEEM_scard__handle   /* Handle to scard */);


NAEEM_result
NAEEM_scard__transmit (NAEEM_scard__handle   /* Handle to scard */,
                       NAEEM_data            /* Send buffer */,
                       NAEEM_uint32          /* Send buffer length */,
                       NAEEM_data            /* Receive buffer */,
                       NAEEM_uint32_ptr      /* Pointer to receive buffer length */);


#ifdef __cplusplus
}
#endif

#endif