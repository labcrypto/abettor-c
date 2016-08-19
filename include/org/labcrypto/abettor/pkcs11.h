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
 
#ifndef _ORG_LABCRYPTO_ABETTOR__C__PKCS11_PKCS11_H_
#define _ORG_LABCRYPTO_ABETTOR__C__PKCS11_PKCS11_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#include <unistd.h>
#endif

#include <org/labcrypto/abettor/pkcs11types.h>
#include <org/labcrypto/abettor/types.h>


#ifdef __cplusplus
extern "C" {
#endif

typedef CK_ULONG                             ORG_LABCRYPTO_ABETTOR__pkcs11__pkcs11_uint64;
typedef CK_ULONG                             ORG_LABCRYPTO_ABETTOR__pkcs11__pkcs11_result;
typedef CK_SLOT_ID                           ORG_LABCRYPTO_ABETTOR__pkcs11__slot_id;
typedef CK_FUNCTION_LIST                     ORG_LABCRYPTO_ABETTOR__pkcs11__function_list;
typedef CK_FUNCTION_LIST_PTR                 ORG_LABCRYPTO_ABETTOR__pkcs11__function_list_ptr;
typedef CK_FUNCTION_LIST_PTR_PTR             ORG_LABCRYPTO_ABETTOR__pkcs11__function_list_ptr_ptr;
typedef CK_SLOT_INFO                         ORG_LABCRYPTO_ABETTOR__pkcs11__slot_info;
typedef CK_TOKEN_INFO                        ORG_LABCRYPTO_ABETTOR__pkcs11__token_info;
typedef CK_SESSION_HANDLE                    ORG_LABCRYPTO_ABETTOR__pkcs11__session;
typedef CK_SESSION_HANDLE_PTR                ORG_LABCRYPTO_ABETTOR__pkcs11__session_ptr;
typedef CK_OBJECT_HANDLE                     ORG_LABCRYPTO_ABETTOR__pkcs11__object;
typedef CK_OBJECT_HANDLE_PTR                 ORG_LABCRYPTO_ABETTOR__pkcs11__object_ptr;
typedef CK_OBJECT_HANDLE_PTR PTR             ORG_LABCRYPTO_ABETTOR__pkcs11__object_ptr_ptr;
typedef CK_OBJECT_HANDLE                     ORG_LABCRYPTO_ABETTOR__pkcs11__key;
typedef CK_OBJECT_HANDLE_PTR                 ORG_LABCRYPTO_ABETTOR__pkcs11__key_ptr;


typedef struct {
  ORG_LABCRYPTO_ABETTOR_char               label[32];
} ORG_LABCRYPTO_ABETTOR__pkcs11__token;
typedef ORG_LABCRYPTO_ABETTOR__pkcs11__token PTR ORG_LABCRYPTO_ABETTOR__pkcs11__token_ptr;


typedef struct {
  ORG_LABCRYPTO_ABETTOR__pkcs11__slot_id    id;
  ORG_LABCRYPTO_ABETTOR_char               description[64];
  ORG_LABCRYPTO_ABETTOR__pkcs11__token      token;
} ORG_LABCRYPTO_ABETTOR__pkcs11__slot;
typedef ORG_LABCRYPTO_ABETTOR__pkcs11__slot PTR ORG_LABCRYPTO_ABETTOR__pkcs11__slot_ptr;
typedef ORG_LABCRYPTO_ABETTOR__pkcs11__slot_ptr PTR ORG_LABCRYPTO_ABETTOR__pkcs11__slot_ptr_ptr;


ORG_LABCRYPTO_ABETTOR_string
get_pkcs11_error_name (
  ORG_LABCRYPTO_ABETTOR__pkcs11__pkcs11_result
);


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__pkcs11__load_shared_object (
  ORG_LABCRYPTO_ABETTOR_path, 
  ORG_LABCRYPTO_ABETTOR__pkcs11__function_list_ptr_ptr
);


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__pkcs11__initialize (
  ORG_LABCRYPTO_ABETTOR__pkcs11__function_list_ptr
);


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__pkcs11__finalize (
  ORG_LABCRYPTO_ABETTOR__pkcs11__function_list_ptr
);


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__pkcs11__get_slots (
  ORG_LABCRYPTO_ABETTOR__pkcs11__function_list_ptr,
  ORG_LABCRYPTO_ABETTOR__pkcs11__slot_ptr_ptr,
  ORG_LABCRYPTO_ABETTOR_length_ptr
);


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__pkcs11__open_session (
  ORG_LABCRYPTO_ABETTOR__pkcs11__function_list_ptr,
  ORG_LABCRYPTO_ABETTOR__pkcs11__slot,
  ORG_LABCRYPTO_ABETTOR__pkcs11__session_ptr
);


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__pkcs11__close_session (
  ORG_LABCRYPTO_ABETTOR__pkcs11__function_list_ptr,
  ORG_LABCRYPTO_ABETTOR__pkcs11__session
);


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__pkcs11__login (
  ORG_LABCRYPTO_ABETTOR__pkcs11__function_list_ptr,
  ORG_LABCRYPTO_ABETTOR__pkcs11__session,
  ORG_LABCRYPTO_ABETTOR_password
);


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__pkcs11__login_as_SO (
  ORG_LABCRYPTO_ABETTOR__pkcs11__function_list_ptr,
  ORG_LABCRYPTO_ABETTOR__pkcs11__session,
  ORG_LABCRYPTO_ABETTOR_password
);


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__pkcs11__logout (
  ORG_LABCRYPTO_ABETTOR__pkcs11__function_list_ptr,
  ORG_LABCRYPTO_ABETTOR__pkcs11__session
);


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__pkcs11__get_all_des3_keys (
  ORG_LABCRYPTO_ABETTOR__pkcs11__function_list_ptr,
  ORG_LABCRYPTO_ABETTOR__pkcs11__session,
  ORG_LABCRYPTO_ABETTOR__pkcs11__object_ptr_ptr,
  ORG_LABCRYPTO_ABETTOR_length_ptr
);


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__pkcs11__find_object_by_label (
  ORG_LABCRYPTO_ABETTOR__pkcs11__function_list_ptr,
  ORG_LABCRYPTO_ABETTOR__pkcs11__session,
  ORG_LABCRYPTO_ABETTOR__pkcs11__object_ptr,
  ORG_LABCRYPTO_ABETTOR_string
);


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__pkcs11__encrypt_des3 (
  ORG_LABCRYPTO_ABETTOR__pkcs11__function_list_ptr,
  ORG_LABCRYPTO_ABETTOR__pkcs11__session,
  ORG_LABCRYPTO_ABETTOR__pkcs11__key,
  ORG_LABCRYPTO_ABETTOR_data,
  ORG_LABCRYPTO_ABETTOR_length,
  ORG_LABCRYPTO_ABETTOR_data_ptr,
  ORG_LABCRYPTO_ABETTOR_length_ptr
);


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__pkcs11__change_SO_pin (
  ORG_LABCRYPTO_ABETTOR__pkcs11__function_list_ptr,
  ORG_LABCRYPTO_ABETTOR__pkcs11__slot,
  ORG_LABCRYPTO_ABETTOR_password,
  ORG_LABCRYPTO_ABETTOR_password
);


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__pkcs11__change_user_pin (
  ORG_LABCRYPTO_ABETTOR__pkcs11__function_list_ptr,
  ORG_LABCRYPTO_ABETTOR__pkcs11__slot,
  ORG_LABCRYPTO_ABETTOR_password,
  ORG_LABCRYPTO_ABETTOR_password
);


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__pkcs11__create_3DES_key (
  ORG_LABCRYPTO_ABETTOR__pkcs11__function_list_ptr,
  ORG_LABCRYPTO_ABETTOR__pkcs11__slot,
  ORG_LABCRYPTO_ABETTOR_password,
  ORG_LABCRYPTO_ABETTOR_string,
  ORG_LABCRYPTO_ABETTOR_data,
  ORG_LABCRYPTO_ABETTOR_length
);


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__pkcs11__list_of_3DES_keys (
  ORG_LABCRYPTO_ABETTOR__pkcs11__function_list_ptr,
  ORG_LABCRYPTO_ABETTOR__pkcs11__slot,
  ORG_LABCRYPTO_ABETTOR_password,
  ORG_LABCRYPTO_ABETTOR_string_ptr_ptr,
  ORG_LABCRYPTO_ABETTOR_length_ptr
);


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__pkcs11__delete_all_3DES_keys (
  ORG_LABCRYPTO_ABETTOR__pkcs11__function_list_ptr,
  ORG_LABCRYPTO_ABETTOR__pkcs11__slot,
  ORG_LABCRYPTO_ABETTOR_password
);


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__pkcs11__3DES_key_exists (
  ORG_LABCRYPTO_ABETTOR__pkcs11__function_list_ptr,
  ORG_LABCRYPTO_ABETTOR__pkcs11__slot,
  ORG_LABCRYPTO_ABETTOR_password,
  ORG_LABCRYPTO_ABETTOR_string,
  ORG_LABCRYPTO_ABETTOR_bool_ptr
);


#ifdef __cplusplus
}
#endif

#endif
