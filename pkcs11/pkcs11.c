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

#include <org/labcrypto/abettor/pkcs11.h>
#include <org/labcrypto/abettor/util.h>


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__pkcs11__load_shared_object (
  ORG_LABCRYPTO_ABETTOR_path shared_object_path, 
  ORG_LABCRYPTO_ABETTOR__pkcs11__function_list_ptr_ptr function_list_ptr_ptr
) {
#ifdef _WIN32
  int result = 0;
  wchar_t wpath[1024] = { 0 };
  HINSTANCE lib;
  CK_C_GetFunctionList getFunctionListFunc = NULL;
  mbstowcs(wpath, shared_object_path, strlen(shared_object_path) + 1);
  lib = LoadLibrary(wpath);
  if (lib == NULL) {
	  return ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__SHARED_LIBRARY_NOT_FOUND;
  }
  getFunctionListFunc = (CK_C_GetFunctionList)GetProcAddress(lib, "C_GetFunctionList");
  if (getFunctionListFunc == NULL) {
	FreeLibrary(lib);
	return ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_GET_FUNCTION_LIST_FAILED;
  }
  result = getFunctionListFunc(function_list_ptr_ptr);
  if (result) {
	FreeLibrary(lib);
	return ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_GET_FUNCTION_LIST_FAILED;
  }
#else
  ORG_LABCRYPTO_ABETTOR_void_ptr lib;
  ORG_LABCRYPTO_ABETTOR_void (*lib_func)(CK_FUNCTION_LIST_PTR_PTR);
  lib = dlopen(shared_object_path, RTLD_LAZY);
  if (!lib) {
    printf("Error in loading PKCS#11 library - %s\n", dlerror());
    fflush(stdout);
    return ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__SHARED_LIBRARY_NOT_FOUND;
  }
  lib_func = (ORG_LABCRYPTO_ABETTOR_void (*) (CK_FUNCTION_LIST **)) dlsym(lib, "C_GetFunctionList");
  ORG_LABCRYPTO_ABETTOR_string error = dlerror();
  if (error) {
    printf("Error in get C_GetFunction address: %s\n", error);
    return ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_GET_FUNCTION_LIST_FAILED;
  }
  (*lib_func)(function_list_ptr_ptr);
#endif
  return ORG_LABCRYPTO_ABETTOR_RESULT__SUCCESS;
}


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__pkcs11__initialize (
  ORG_LABCRYPTO_ABETTOR__pkcs11__function_list_ptr function_list_ptr
) {
  ORG_LABCRYPTO_ABETTOR__pkcs11__pkcs11_result result = function_list_ptr->C_Initialize(NULL);
  if (result) {
    printf("Error in init: C_Initialize failed %s\n", get_pkcs11_error_name(result));
    return ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_INITIALIZE_FAILED;
  }
  return ORG_LABCRYPTO_ABETTOR_RESULT__SUCCESS;
}

ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__pkcs11__finalize (
  ORG_LABCRYPTO_ABETTOR__pkcs11__function_list_ptr function_list_ptr
) {
  ORG_LABCRYPTO_ABETTOR__pkcs11__pkcs11_result result = function_list_ptr->C_Finalize(NULL);
  if (result) {
    printf("Error in init: C_Initialize failed %s\n", get_pkcs11_error_name(result));
    return ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_INITIALIZE_FAILED;
  }
  return ORG_LABCRYPTO_ABETTOR_RESULT__SUCCESS;
}

ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__pkcs11__get_slots (
  ORG_LABCRYPTO_ABETTOR__pkcs11__function_list_ptr function_list_ptr,
  ORG_LABCRYPTO_ABETTOR__pkcs11__slot_ptr_ptr slots,
  ORG_LABCRYPTO_ABETTOR_length_ptr slots_length_ptr
) {
  ORG_LABCRYPTO_ABETTOR__pkcs11__slot_id slot_ids[10];
  ORG_LABCRYPTO_ABETTOR__pkcs11__pkcs11_uint64 num_slots = 10;
  ORG_LABCRYPTO_ABETTOR_counter i = 0, j = 0;
  ORG_LABCRYPTO_ABETTOR__pkcs11__token_info token_info;
  ORG_LABCRYPTO_ABETTOR__pkcs11__pkcs11_result result = function_list_ptr->C_GetSlotList(1, slot_ids, &num_slots);
  if (result) {
    printf("Error in init: C_GetSlotList failed %s\n", get_pkcs11_error_name(result));
    return ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_GET_SLOT_LIST_FAILED;
  }
  *slots_length_ptr = num_slots;
  if (num_slots == 0) {
    return ORG_LABCRYPTO_ABETTOR_RESULT__SUCCESS;
  }
  *slots = (ORG_LABCRYPTO_ABETTOR__pkcs11__slot_ptr)malloc(num_slots * sizeof(ORG_LABCRYPTO_ABETTOR__pkcs11__slot));
  for (; i < num_slots; i++) {
    ORG_LABCRYPTO_ABETTOR__pkcs11__slot_info slot_info;
    result = function_list_ptr->C_GetSlotInfo(slot_ids[i], &slot_info);
    if (result) {
      printf("Error in init: C_GetSlotInfo failed %s\n", get_pkcs11_error_name(result));
      return ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_GET_SLOT_INFO_FAILED;
    }
    (*slots)[i].id = slot_ids[i];
    for (j = 0; j < 31; j++) {
      (*slots)[i].description[j] = slot_info.slotDescription[j];
    }
    (*slots)[i].description[31] = '\0';
    result = function_list_ptr->C_GetTokenInfo(slot_ids[i], &token_info);
    if (result) {
      printf("Error in init: C_GetTokenInfo failed %s\n", get_pkcs11_error_name(result));
      return ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_GET_TOKEN_INFO_FAILED;
    }
    for (j = 0; j < 31; j++) {
      (*slots)[i].token.label[j] = token_info.label[j];
    }
    (*slots)[i].token.label[31] = '\0';
  }
  return ORG_LABCRYPTO_ABETTOR_RESULT__SUCCESS;
}


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__pkcs11__open_session (
  ORG_LABCRYPTO_ABETTOR__pkcs11__function_list_ptr function_list_ptr,
  ORG_LABCRYPTO_ABETTOR__pkcs11__slot slot,
  ORG_LABCRYPTO_ABETTOR__pkcs11__session_ptr session_ptr
) {
  ORG_LABCRYPTO_ABETTOR__pkcs11__pkcs11_result result = 
    function_list_ptr->C_OpenSession (
      slot.id, 
      CKF_RW_SESSION | CKF_SERIAL_SESSION,
      NULL,
      NULL,
      session_ptr
    );
  if (result) {
    printf("Error in init: C_OpenSession failed %s\n", get_pkcs11_error_name(result));
    return ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_OPEN_SESSION_FAILED;
  }
  return ORG_LABCRYPTO_ABETTOR_RESULT__SUCCESS;
}


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__pkcs11__close_session (
  ORG_LABCRYPTO_ABETTOR__pkcs11__function_list_ptr function_list_ptr,
  ORG_LABCRYPTO_ABETTOR__pkcs11__session session
) {
  ORG_LABCRYPTO_ABETTOR__pkcs11__pkcs11_result result = function_list_ptr->C_CloseSession(session);
  if (result) {
    printf("Error in init: C_CloseSession failed %s\n", get_pkcs11_error_name(result));
    return ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_CLOSE_SESSION_FAILED;
  }
  return ORG_LABCRYPTO_ABETTOR_RESULT__SUCCESS;
}


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__pkcs11__login (
  ORG_LABCRYPTO_ABETTOR__pkcs11__function_list_ptr function_list_ptr,
  ORG_LABCRYPTO_ABETTOR__pkcs11__session session,
  ORG_LABCRYPTO_ABETTOR_password password
) {
  ORG_LABCRYPTO_ABETTOR__pkcs11__pkcs11_result result = 
    function_list_ptr->C_Login (
      session, 
      CKU_USER, 
      password,
      strlen(password)
    );
  if (result) {
    printf("Error in init: C_Login failed %s\n", get_pkcs11_error_name(result));
    return ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_LOGIN_FAILED;
  }
  return ORG_LABCRYPTO_ABETTOR_RESULT__SUCCESS;
}


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__pkcs11__login_as_SO (
  ORG_LABCRYPTO_ABETTOR__pkcs11__function_list_ptr function_list_ptr,
  ORG_LABCRYPTO_ABETTOR__pkcs11__session session,
  ORG_LABCRYPTO_ABETTOR_password password
) {
  ORG_LABCRYPTO_ABETTOR__pkcs11__pkcs11_result result = 
    function_list_ptr->C_Login (
      session, 
      CKU_SO, 
      password,
      strlen(password)
    );
  if (result) {
    printf("Error in init: C_Login as SO failed %s\n", get_pkcs11_error_name(result));
    return ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_LOGIN_FAILED;
  }
  return ORG_LABCRYPTO_ABETTOR_RESULT__SUCCESS;
}


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__pkcs11__logout (
  ORG_LABCRYPTO_ABETTOR__pkcs11__function_list_ptr function_list_ptr,
  ORG_LABCRYPTO_ABETTOR__pkcs11__session session
) {
  ORG_LABCRYPTO_ABETTOR__pkcs11__pkcs11_result result = function_list_ptr->C_Logout(session);
  if (result) {
    printf("Error in init: C_Logout failed %s\n", get_pkcs11_error_name(result));
    return ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_LOGOUT_FAILED;
  }
  return ORG_LABCRYPTO_ABETTOR_RESULT__SUCCESS;
}


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__pkcs11__get_all_des3_keys (
  ORG_LABCRYPTO_ABETTOR__pkcs11__function_list_ptr function_list_ptr,
  ORG_LABCRYPTO_ABETTOR__pkcs11__session session,
  ORG_LABCRYPTO_ABETTOR__pkcs11__object_ptr_ptr objects,
  ORG_LABCRYPTO_ABETTOR_length_ptr length_ptr
) {
  ORG_LABCRYPTO_ABETTOR__pkcs11__pkcs11_result result;
  CK_ULONG num_objects;
  CK_OBJECT_HANDLE object_handles[2048];
  ORG_LABCRYPTO_ABETTOR_counter i = 0;

  CK_ATTRIBUTE object_template[2];

  object_template[0].type = CKA_CLASS;
  object_template[0].ulValueLen = sizeof(CKA_CLASS);
  object_template[0].pValue = (CK_ULONG *) malloc(sizeof(CK_ULONG *));
  *((CK_ULONG *) (object_template[0].pValue)) = CKO_SECRET_KEY;

  object_template[1].type = CKA_KEY_TYPE;
  object_template[1].pValue = (CK_ULONG *) malloc(sizeof(CK_ULONG *));
  object_template[1].ulValueLen = sizeof(CK_ULONG);
  *((CK_ULONG *) (object_template[1].pValue)) = CKK_DES3;

  result = function_list_ptr->C_FindObjectsInit(session, 
                                                object_template, 
                                                2);
  if (result) {
    printf("Error in init: C_FindObjectsInit failed %s\n", get_pkcs11_error_name(result));
    return ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_FIND_OBJECTS_INIT_FAILED;
  }
  num_objects = 2048;
  
  result = function_list_ptr->C_FindObjects(session, 
                                            object_handles, 
                                            2048, 
                                            &num_objects);
  if (result) {
    printf("Error in init: C_FindObjects failed %s\n", get_pkcs11_error_name(result));
    return ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_FIND_OBJECTS_FAILED;
  }
  result = function_list_ptr->C_FindObjectsFinal(session);
  if (result) {
    printf("Error in init: C_FindObjectsFinal failed %s\n", get_pkcs11_error_name(result));
    return ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_FIND_OBJECTS_FINAL_FAILED;
  }
  *length_ptr = num_objects;
  *objects = (ORG_LABCRYPTO_ABETTOR__pkcs11__object_ptr)malloc(num_objects * sizeof(ORG_LABCRYPTO_ABETTOR__pkcs11__object));
  
  for (i = 0; i < num_objects; i++) {
    (*objects)[i] = object_handles[i];
  }
  return ORG_LABCRYPTO_ABETTOR_RESULT__SUCCESS;
}


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__pkcs11__find_object_by_label (
  ORG_LABCRYPTO_ABETTOR__pkcs11__function_list_ptr function_list_ptr,
  ORG_LABCRYPTO_ABETTOR__pkcs11__session session,
  ORG_LABCRYPTO_ABETTOR__pkcs11__object_ptr object_ptr,
  ORG_LABCRYPTO_ABETTOR_string label
) {
  CK_ULONG num_objects;
  CK_OBJECT_HANDLE object_handles[1];
  ORG_LABCRYPTO_ABETTOR__pkcs11__pkcs11_result result;
  CK_ATTRIBUTE object_template[3];

  object_template[0].type = CKA_CLASS;
  object_template[0].ulValueLen = sizeof(CKA_CLASS);
  object_template[0].pValue = (CK_ULONG *) malloc(sizeof(CK_ULONG *));
  *((CK_ULONG *) (object_template[0].pValue)) = CKO_SECRET_KEY;

  object_template[1].type = CKA_KEY_TYPE;
  object_template[1].pValue = (CK_ULONG *) malloc(sizeof(CK_ULONG *));
  object_template[1].ulValueLen = sizeof(CK_ULONG);
  *((CK_ULONG *) (object_template[1].pValue)) = CKK_DES3;

  object_template[2].type = CKA_LABEL;
  object_template[2].pValue = (CK_CHAR_PTR) malloc((strlen(label) + 1) * sizeof(CK_CHAR));
  object_template[2].ulValueLen = strlen(label);
  strcpy(object_template[2].pValue, label);

  result = function_list_ptr->C_FindObjectsInit(session, 
                                                object_template, 
                                                3);
  if (result) {
    printf("Error in init: C_FindObjectsInit failed %s\n", get_pkcs11_error_name(result));
    return ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_FIND_OBJECTS_INIT_FAILED;
  }
  num_objects = 1;
  result = function_list_ptr->C_FindObjects(session, 
                                            object_handles, 
                                            1, 
                                            &num_objects);
  if (result) {
    printf("Error in init: C_FindObjects failed %s\n", get_pkcs11_error_name(result));
    return ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_FIND_OBJECTS_FAILED;
  }
  result = function_list_ptr->C_FindObjectsFinal(session);
  if (result) {
    printf("Error in init: C_FindObjectsFinal failed %s\n", get_pkcs11_error_name(result));
    return ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_FIND_OBJECTS_FINAL_FAILED;
  }
  if (num_objects == 0) {
    return ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__OBJECT_NOT_FOUND;
  }
  *object_ptr = object_handles[0];
  return ORG_LABCRYPTO_ABETTOR_RESULT__SUCCESS;
}


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__pkcs11__encrypt_des3 (
  ORG_LABCRYPTO_ABETTOR__pkcs11__function_list_ptr function_list_ptr,
  ORG_LABCRYPTO_ABETTOR__pkcs11__session session,
  ORG_LABCRYPTO_ABETTOR__pkcs11__key key,
  ORG_LABCRYPTO_ABETTOR_data data,
  ORG_LABCRYPTO_ABETTOR_length data_length,
  ORG_LABCRYPTO_ABETTOR_data_ptr cipher,
  ORG_LABCRYPTO_ABETTOR_length_ptr cipher_length_ptr
) {
  ORG_LABCRYPTO_ABETTOR_byte temp[8];
  ORG_LABCRYPTO_ABETTOR_length temp_length;
  CK_BYTE iv[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  CK_MECHANISM mechanism = {CKM_DES3_CBC, iv, 8};
  ORG_LABCRYPTO_ABETTOR__pkcs11__pkcs11_result result = 
    function_list_ptr->C_EncryptInit (
      session, 
      &mechanism, 
      key
    );
  if (result) {
    printf("Error in init: C_EncryptInit failed %s\n", get_pkcs11_error_name(result));
    return ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_ENCRYPT_INIT_FAILED;
  }
  
  temp_length = 8;
  result = function_list_ptr->C_Encrypt(session, 
                                        data, 
                                        data_length, 
                                        temp,
                                        (CK_ULONG_PTR)&temp_length);
  if (result) {
    printf("Error in init: C_Encrypt failed %s\n", get_pkcs11_error_name(result));
    return ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_ENCRYPT_FAILED;
  }
  *cipher = (ORG_LABCRYPTO_ABETTOR_data)malloc(8 * sizeof(ORG_LABCRYPTO_ABETTOR_byte));
  *cipher_length_ptr = 8;
  ORG_LABCRYPTO_ABETTOR__util__copy_array(*cipher, temp, 0, 8);
  return ORG_LABCRYPTO_ABETTOR_RESULT__SUCCESS;
}


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__pkcs11__change_SO_pin (
  ORG_LABCRYPTO_ABETTOR__pkcs11__function_list_ptr function_list_ptr,
  ORG_LABCRYPTO_ABETTOR__pkcs11__slot slot,
  ORG_LABCRYPTO_ABETTOR_password old_password,
  ORG_LABCRYPTO_ABETTOR_password new_password
) {
  ORG_LABCRYPTO_ABETTOR__pkcs11__session session;
  ORG_LABCRYPTO_ABETTOR__pkcs11__pkcs11_result result = 
    function_list_ptr->C_OpenSession (
      slot.id, 
      CKF_RW_SESSION | CKF_SERIAL_SESSION,
      NULL,
      NULL,
      &session
    );
  if (result) {
    printf("Error in init: C_OpenSession failed %s\n", get_pkcs11_error_name(result));
    return ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_OPEN_SESSION_FAILED;
  }
  result = 
    function_list_ptr->C_Login (
      session, 
      CKU_SO, 
      old_password,
      strlen(old_password)
    );
  if (result) {
    printf("Error in init: C_Login as SO failed %s\n", get_pkcs11_error_name(result));
    function_list_ptr->C_CloseSession(session);
    return ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_LOGIN_FAILED;
  }
  result =
    function_list_ptr->C_SetPIN (
      session,
      old_password,
      strlen(old_password),
      new_password,
      strlen(new_password)
    );
  if (result) {
    printf("Error in init: C_SetPin failed %s\n", get_pkcs11_error_name(result));
    function_list_ptr->C_Logout(session);
    function_list_ptr->C_CloseSession(session);
    return ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_SET_PIN_FAILED;
  }
  result = function_list_ptr->C_Logout(session);
  if (result) {
    printf("Error in init: C_Logout failed %s\n", get_pkcs11_error_name(result));
    function_list_ptr->C_CloseSession(session);
    return ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_LOGOUT_FAILED;
  }
  result = function_list_ptr->C_CloseSession(session);
  if (result) {
    printf("Error in init: C_CloseSession failed %s\n", get_pkcs11_error_name(result));
    return ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_CLOSE_SESSION_FAILED;
  }
  return ORG_LABCRYPTO_ABETTOR_RESULT__SUCCESS;
}