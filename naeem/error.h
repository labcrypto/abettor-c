#ifndef _NAEEM_CORELIBS__ERROR_H_
#define _NAEEM_CORELIBS__ERROR_H_

#ifdef __cplusplus
extern "C" {
#endif

#define NAEEM_RESULT_SUCCESS                                                            0x00000000
#define NAEEM_RESULT_ERROR_INVALID_MRZ_DATA                                             0x80000001
#define NAEEM_RESULT_ERROR_INVALID_MRZ_CHARACTER                                        0x80000002
#define NAEEM_RESULT_BUFFER_SIZE_TOO_LOW                                                0x80000003
#define NAEEM_RESULT_INVALID_DES_KEY                                                    0x80000004
#define NAEEM_RESULT_SCARD_CONTEXT_NOT_ESTABLISHED                                      0x80000005
#define NAEEM_RESULT_SCARD_LIST_NOT_OBTAINED                                            0x80000006
#define NAEEM_RESULT_NO_SCARD_IS_FOUND                                                  0x80000007
#define NAEEM_RESULT_SCARD_CAN_NOT_BE_CONNECTED                                         0x80000008
#define NAEEM_RESULT_SCARD_TRANSMIT_ERROR                                               0x80000009
#define NAEEM_RESULT_SCARD_CAN_NOT_BE_DISCONNECTED                                      0x8000000A
#define NAEEM_RESULT_UNABLE_TO_GET_CHIP_SERIAL                                          0x8000000B
#define NAEEM_RESULT_UNABLE_TO_GET_CHALLENGE_NUMBER                                     0x8000000C
#define NAEEM_RESULT_PERSO_EXT_AUTH_FAILED                                              0x8000000D
#define NAEEM_RESULT_UPDATE_EXT_AUTH_FAILED                                             0x8000000E
#define NAEEM_RESULT_READ_EXT_AUTH_FAILED                                               0x8000000F
#define NAEEM_RESULT_EF_COM_CREATION_FAILED                                             0x80000010
#define NAEEM_RESULT_EF_COM_NOT_SELECTED                                                0x80000011
#define NAEEM_RESULT_EF_COM_DELETION_FAILED                                             0x80000012
#define NAEEM_RESULT_EF_COM_WRITE_FAILED                                                0x80000013
#define NAEEM_RESULT_EF_COM_READ_FAILED                                                 0x80000014
#define NAEEM_RESULT_DG1_CREATION_FAILED                                                0x80000015
#define NAEEM_RESULT_DG1_NOT_SELECTED                                                   0x80000016
#define NAEEM_RESULT_DG1_DELETION_FAILED                                                0x80000017
#define NAEEM_RESULT_DG1_WRITE_FAILED                                                   0x80000018
#define NAEEM_RESULT_DG1_READ_FAILED                                                    0x80000019
#define NAEEM_RESULT_BAC_RND_ICC_IS_INCORRECT                                           0x8000001A
#define NAEEM_RESULT_BAC_RND_IFD_IS_INCORRECT                                           0x0000001B
#define NAEEM_RESULT_BAC_E_ICC_MAC_IS_INCORRECT                                         0x8000001C
#define NAEEM_RESULT_MALFORMED_APDU_COMMAND                                             0x8000001D
#define NAEEM_RESULT_APDU_RESPONSE_MAC_IS_INCORRECT                                     0x8000001E
#define NAEEM_RESULT_INVALID_APDU_RESPONSE                                              0x8000001F
#define NAEEM_RESULT_WRONG_EF_COM_DATA                                                  0x80000020
#define NAEEM_RESULT_WRONG_EF_SOD_DATA                                                  0x80000021
#define NAEEM_RESULT_WRONG_DG1_DATA                                                     0x80000022
#define NAEEM_RESULT_WRONG_DG2_DATA                                                     0x80000023
#define NAEEM_RESULT_WRONG_DG3_DATA                                                     0x80000024
#define NAEEM_RESULT_WRONG_DG4_DATA                                                     0x80000025
#define NAEEM_RESULT_WRONG_DG5_DATA                                                     0x80000026
#define NAEEM_RESULT_WRONG_DG6_DATA                                                     0x80000027
#define NAEEM_RESULT_WRONG_DG7_DATA                                                     0x80000028
#define NAEEM_RESULT_WRONG_DG8_DATA                                                     0x80000029
#define NAEEM_RESULT_WRONG_DG9_DATA                                                     0x8000002A
#define NAEEM_RESULT_WRONG_DG10_DATA                                                    0x8000002B
#define NAEEM_RESULT_WRONG_DG11_DATA                                                    0x8000002C
#define NAEEM_RESULT_WRONG_DG12_DATA                                                    0x8000002D
#define NAEEM_RESULT_WRONG_DG13_DATA                                                    0x8000002E
#define NAEEM_RESULT_WRONG_DG14_DATA                                                    0x8000002F
#define NAEEM_RESULT_WRONG_DG15_DATA                                                    0x80000030
#define NAEEM_RESULT_WRONG_DG16_DATA                                                    0x80000031
#define NAEEM_RESULT_DG2_CREATION_FAILED                                                0x80000032
#define NAEEM_RESULT_DG2_NOT_SELECTED                                                   0x80000033
#define NAEEM_RESULT_DG2_DELETION_FAILED                                                0x80000034
#define NAEEM_RESULT_DG2_WRITE_FAILED                                                   0x80000035
#define NAEEM_RESULT_DG2_READ_FAILED                                                    0x80000036
#define NAEEM_RESULT_DG7_CREATION_FAILED                                                0x80000037
#define NAEEM_RESULT_DG7_NOT_SELECTED                                                   0x80000038
#define NAEEM_RESULT_DG7_DELETION_FAILED                                                0x80000039
#define NAEEM_RESULT_DG7_WRITE_FAILED                                                   0x8000003A
#define NAEEM_RESULT_DG7_READ_FAILED                                                    0x8000003B
#define NAEEM_RESULT_DG12_CREATION_FAILED                                               0x8000003C
#define NAEEM_RESULT_DG12_NOT_SELECTED                                                  0x8000003D
#define NAEEM_RESULT_DG12_DELETION_FAILED                                               0x8000003E
#define NAEEM_RESULT_DG12_WRITE_FAILED                                                  0x8000003F
#define NAEEM_RESULT_DG12_READ_FAILED                                                   0x80000040
#define NAEEM_RESULT_DG13_CREATION_FAILED                                               0x80000041
#define NAEEM_RESULT_DG13_NOT_SELECTED                                                  0x80000042
#define NAEEM_RESULT_DG13_DELETION_FAILED                                               0x80000043
#define NAEEM_RESULT_DG13_WRITE_FAILED                                                  0x80000044
#define NAEEM_RESULT_DG13_READ_FAILED                                                   0x80000045
#define NAEEM_RESULT_EF_SOD_CREATION_FAILED                                             0x80000046
#define NAEEM_RESULT_EF_SOD_NOT_SELECTED                                                0x80000047
#define NAEEM_RESULT_EF_SOD_DELETION_FAILED                                             0x80000048
#define NAEEM_RESULT_EF_SOD_WRITE_FAILED                                                0x80000049
#define NAEEM_RESULT_EF_SOD_READ_FAILED                                                 0x8000004A
#define NAEEM_RESULT_DG15_CREATION_FAILED                                               0x8000004B
#define NAEEM_RESULT_DG15_NOT_SELECTED                                                  0x8000004C
#define NAEEM_RESULT_DG15_DELETION_FAILED                                               0x8000004D
#define NAEEM_RESULT_DG15_WRITE_FAILED                                                  0x8000004E
#define NAEEM_RESULT_DG15_READ_FAILED                                                   0x8000004F

#define NAEEM_RESULT_PKCS11__SHARED_LIBRARY_NOT_FOUND                                   0x80000050
#define NAEEM_RESULT_PKCS11__C_GET_FUNCTION_LIST_FAILED                                 0x80000051
#define NAEEM_RESULT_PKCS11__C_INITIALIZE_FAILED                                        0x80000052
#define NAEEM_RESULT_PKCS11__C_GET_SLOT_LIST_FAILED                                     0x80000053
#define NAEEM_RESULT_PKCS11__C_GET_SLOT_INFO_FAILED                                     0x80000054
#define NAEEM_RESULT_PKCS11__C_GET_TOKEN_INFO_FAILED                                    0x80000055
#define NAEEM_RESULT_PKCS11__C_OPEN_SESSION_FAILED                                      0x80000056
#define NAEEM_RESULT_PKCS11__C_CLOSE_SESSION_FAILED                                     0x80000057
#define NAEEM_RESULT_PKCS11__C_LOGIN_FAILED                                             0x80000058
#define NAEEM_RESULT_PKCS11__C_FIND_OBJECTS_INIT_FAILED                                 0x80000059
#define NAEEM_RESULT_PKCS11__C_FIND_OBJECTS_FAILED                                      0x8000005a
#define NAEEM_RESULT_PKCS11__C_FIND_OBJECTS_FINAL_FAILED                                0x8000005b
#define NAEEM_RESULT_PKCS11__OBJECT_NOT_FOUND                                           0x8000005c
#define NAEEM_RESULT_PKCS11__C_LOGOUT_FAILED                                            0x80000056
#define NAEEM_RESULT_PKCS11__C_ENCRYPT_INIT_FAILED                                      0x80000057
#define NAEEM_RESULT_PKCS11__C_ENCRYPT_FAILED                                           0x80000058
#define NAEEM_RESULT__REMOTE_SIGN_FAILED                                                0x80000059

#define NAEEM_RESULT_GENERAL_ERROR                                                      0x80001000


#define NAEEM_RESULT_APDU_STATUS_90_00_SUCCESS                                          0x00000000
#define NAEEM_RESULT_APDU_STATUS_63_00_VERIFICATION_FAILED                              0x81000001
#define NAEEM_RESULT_APDU_STATUS_69_82_SECURITY_CONDITION_NOT_SATISFIED                 0x81000002
#define NAEEM_RESULT_APDU_STATUS_6A_82_FILE_NOT_FOUND                                   0x81000003
#define NAEEM_RESULT_APDU_STATUS_67_00_WRONG_LENGTH                                     0x81000004


void
NAEEM_error_get_string (unsigned int         /* Error code */, 
                        unsigned char **     /* Pointer to string buffer */);


void
NAEEM_error_print (unsigned int        /* Error code */);


#ifdef __cplusplus
}
#endif

#endif

