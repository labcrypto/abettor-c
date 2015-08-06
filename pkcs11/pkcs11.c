#include <naeem/pkcs11.h>


NAEEM_result
NAEEM_pkcs11__load_shared_object(NAEEM_path shared_object_path, 
                                 NAEEM_pkcs11__function_list_ptr function_list_ptr) {
  NAEEM_void_ptr lib;
  NAEEM_void (*lib_func)(CK_FUNCTION_LIST_PTR_PTR);
  lib = dlopen(shared_object_path, RTLD_LAZY);
  if (!lib) {
    printf("Error in loading PKCS#11 library - %s\n", dlerror());
    fflush(stdout);
    return NAEEM_RESULT_PKCS11__SHARED_LIBRARY_NOT_FOUND;
  }
  lib_func = (NAEEM_void (*) (CK_FUNCTION_LIST **)) dlsym(lib, "C_GetFunctionList");
  NAEEM_string error = dlerror();
  if (error) {
    printf("Error in get C_GetFunction address: %s\n", error);
    return NAEEM_RESULT_PKCS11__C_GET_FUNCTION_LIST_FAILED;
  }
  (*lib_func)(&function_list_ptr);
  return NAEEM_RESULT_SUCCESS;
}


NAEEM_result
NAEEM_pkcs11__initialize(NAEEM_pkcs11__function_list_ptr function_list_ptr) {
  NAEEM_pkcs11__pkcs11_result result = function_list_ptr->C_Initialize(NULL);
  if (result) {
    printf("Error in init: C_Initialize failed %s\n", get_pkcs11_error_name(result));
    return NAEEM_RESULT_PKCS11__C_INITIALIZE_FAILED;
  }
  return NAEEM_RESULT_SUCCESS;
}


NAEEM_result
NAEEM_pkcs11__get_slots(NAEEM_pkcs11__function_list_ptr function_list_ptr,
                        NAEEM_pkcs11__slot_ptr_ptr slots,
                        NAEEM_length_ptr slots_length) {
  return NAEEM_RESULT_SUCCESS;
}