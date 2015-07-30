#ifndef _NAEEM_SCARD_H_
#define _NAEEM_SCARD_H_

#include <PCSC/wintypes.h>
#include <PCSC/winscard.h>
#include <PCSC/reader.h>

#include <naeem/types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef SCARDHANDLE NAEEM_scard_handle;
typedef NAEEM_scard_handle PTR NAEEM_scard_handle_ptr;
typedef SCARDCONTEXT NAEEM_scard_context;
typedef NAEEM_scard_context PTR NAEEM_scard_context_ptr;


NAEEM_result
NAEEM_scard_open_context (NAEEM_scard_context_ptr /* Pointer to context */);


NAEEM_result
NAEEM_scard_close_context (NAEEM_scard_context /* Context */);


NAEEM_result
NAEEM_scard_enumerate_smart_cards (NAEEM_scard_context   /* Context */,
                                   NAEEM_string_ptr_ptr  /* Pointer to array of scard names */,
                                   NAEEM_uint32_ptr      /* Pointer to number of scards */);


NAEEM_result
NAEEM_scard_connect_card (NAEEM_scard_context       /* Context */,
                          NAEEM_string              /* Name of the card */,
                          NAEEM_scard_handle_ptr    /* Pointer to scard handle */);


NAEEM_result
NAEEM_scard_disconnect_card (NAEEM_scard_handle   /* Handle to scard */);


NAEEM_result
NAEEM_scard_transmit (NAEEM_scard_handle   /* Handle to scard */,
                      NAEEM_data           /* Send buffer */,
                      NAEEM_uint32         /* Send buffer length */,
                      NAEEM_data           /* Receive buffer */,
                      NAEEM_uint32_ptr     /* Pointer to receive buffer length */);


#ifdef __cplusplus
}
#endif

#endif