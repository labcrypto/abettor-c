#ifndef _NAEEM_CORELIBS__PKCS11_PKCS11_H_
#define _NAEEM_CORELIBS__PKCS11_PKCS11_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <unistd.h>

// #include <naeem/pkcs11/pkcs11t.h>
// #include <naeem/pkcs11/pkcs11.h>
// #include <naeem/pkcs11/pkcs11f.h>
#include <naeem/pkcs11types.h>
#include <naeem/types.h>


#ifdef __cplusplus
extern "C" {
#endif

typedef CK_ULONG                             NAEEM_pkcs11__pkcs11_uint64;
typedef CK_ULONG                             NAEEM_pkcs11__pkcs11_result;
typedef CK_SLOT_ID                           NAEEM_pkcs11__slot_id;
typedef CK_FUNCTION_LIST                     NAEEM_pkcs11__function_list;
typedef CK_FUNCTION_LIST_PTR                 NAEEM_pkcs11__function_list_ptr;
typedef CK_FUNCTION_LIST_PTR_PTR             NAEEM_pkcs11__function_list_ptr_ptr;
typedef CK_SLOT_INFO                         NAEEM_pkcs11__slot_info;
typedef CK_TOKEN_INFO                        NAEEM_pkcs11__token_info;
typedef CK_SESSION_HANDLE                    NAEEM_pkcs11__session;
typedef CK_SESSION_HANDLE_PTR                NAEEM_pkcs11__session_ptr;
typedef CK_OBJECT_HANDLE                     NAEEM_pkcs11__object;
typedef CK_OBJECT_HANDLE_PTR                 NAEEM_pkcs11__object_ptr;
typedef CK_OBJECT_HANDLE_PTR PTR             NAEEM_pkcs11__object_ptr_ptr;

typedef struct {
  NAEEM_char               label[32];
} NAEEM_pkcs11__token;
typedef NAEEM_pkcs11__token PTR NAEEM_pkcs11__token_ptr;


typedef struct {
  NAEEM_pkcs11__slot_id    id;
  NAEEM_char               description[64];
  NAEEM_pkcs11__token      token;
} NAEEM_pkcs11__slot;
typedef NAEEM_pkcs11__slot PTR NAEEM_pkcs11__slot_ptr;
typedef NAEEM_pkcs11__slot_ptr PTR NAEEM_pkcs11__slot_ptr_ptr;


NAEEM_string
get_pkcs11_error_name(NAEEM_pkcs11__pkcs11_result);


NAEEM_result
NAEEM_pkcs11__load_shared_object(NAEEM_path, 
                                 NAEEM_pkcs11__function_list_ptr_ptr);


NAEEM_result
NAEEM_pkcs11__initialize(NAEEM_pkcs11__function_list_ptr);


NAEEM_result
NAEEM_pkcs11__get_slots(NAEEM_pkcs11__function_list_ptr,
                        NAEEM_pkcs11__slot_ptr_ptr,
                        NAEEM_length_ptr);

NAEEM_result
NAEEM_pkcs11__open_session(NAEEM_pkcs11__function_list_ptr,
                           NAEEM_pkcs11__slot,
                           NAEEM_pkcs11__session_ptr);


NAEEM_result
NAEEM_pkcs11__close_session(NAEEM_pkcs11__function_list_ptr,
                            NAEEM_pkcs11__session);


NAEEM_result
NAEEM_pkcs11__login(NAEEM_pkcs11__function_list_ptr,
                    NAEEM_pkcs11__session,
                    NAEEM_password);


NAEEM_result
NAEEM_pkcs11__logout(NAEEM_pkcs11__function_list_ptr,
                     NAEEM_pkcs11__session);


NAEEM_result
NAEEM_pkcs11__get_all_des3_keys(NAEEM_pkcs11__function_list_ptr,
                                NAEEM_pkcs11__session,
                                NAEEM_pkcs11__object_ptr_ptr,
                                NAEEM_length_ptr);


NAEEM_result
NAEEM_pkcs11__find_object_by_label(NAEEM_pkcs11__function_list_ptr,
                                   NAEEM_pkcs11__session,
                                   NAEEM_pkcs11__object_ptr,
                                   NAEEM_string);


#ifdef __cplusplus
}
#endif

#endif