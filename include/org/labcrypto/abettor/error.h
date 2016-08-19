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
 
#ifndef _ORG_LABCRYPTO_ABETTOR__C__ERROR_H_
#define _ORG_LABCRYPTO_ABETTOR__C__ERROR_H_

#ifdef __cplusplus
extern "C" {
#endif

#define ORG_LABCRYPTO_ABETTOR_RESULT__SUCCESS                                                            0x00000000
#define ORG_LABCRYPTO_ABETTOR_RESULT__ERROR_INVALID_MRZ_DATA                                             0x80000001
#define ORG_LABCRYPTO_ABETTOR_RESULT__ERROR_INVALID_MRZ_CHARACTER                                        0x80000002
#define ORG_LABCRYPTO_ABETTOR_RESULT__BUFFER_SIZE_TOO_LOW                                                0x80000003
#define ORG_LABCRYPTO_ABETTOR_RESULT__INVALID_DES_KEY                                                    0x80000004
#define ORG_LABCRYPTO_ABETTOR_RESULT__SCARD_CONTEXT_NOT_ESTABLISHED                                      0x80000005
#define ORG_LABCRYPTO_ABETTOR_RESULT__SCARD_LIST_NOT_OBTAINED                                            0x80000006
#define ORG_LABCRYPTO_ABETTOR_RESULT__NO_SCARD_IS_FOUND                                                  0x80000007
#define ORG_LABCRYPTO_ABETTOR_RESULT__SCARD_CAN_NOT_BE_CONNECTED                                         0x80000008
#define ORG_LABCRYPTO_ABETTOR_RESULT__SCARD_TRANSMIT_ERROR                                               0x80000009
#define ORG_LABCRYPTO_ABETTOR_RESULT__SCARD_CAN_NOT_BE_DISCONNECTED                                      0x8000000A
#define ORG_LABCRYPTO_ABETTOR_RESULT__UNABLE_TO_GET_CHIP_SERIAL                                          0x8000000B
#define ORG_LABCRYPTO_ABETTOR_RESULT__UNABLE_TO_GET_CHALLENGE_NUMBER                                     0x8000000C
#define ORG_LABCRYPTO_ABETTOR_RESULT__PERSO_EXT_AUTH_FAILED                                              0x8000000D
#define ORG_LABCRYPTO_ABETTOR_RESULT__UPDATE_EXT_AUTH_FAILED                                             0x8000000E
#define ORG_LABCRYPTO_ABETTOR_RESULT__READ_EXT_AUTH_FAILED                                               0x8000000F
#define ORG_LABCRYPTO_ABETTOR_RESULT__EF_COM_CREATION_FAILED                                             0x80000010
#define ORG_LABCRYPTO_ABETTOR_RESULT__EF_COM_NOT_SELECTED                                                0x80000011
#define ORG_LABCRYPTO_ABETTOR_RESULT__EF_COM_DELETION_FAILED                                             0x80000012
#define ORG_LABCRYPTO_ABETTOR_RESULT__EF_COM_WRITE_FAILED                                                0x80000013
#define ORG_LABCRYPTO_ABETTOR_RESULT__EF_COM_READ_FAILED                                                 0x80000014
#define ORG_LABCRYPTO_ABETTOR_RESULT__DG1_CREATION_FAILED                                                0x80000015
#define ORG_LABCRYPTO_ABETTOR_RESULT__DG1_NOT_SELECTED                                                   0x80000016
#define ORG_LABCRYPTO_ABETTOR_RESULT__DG1_DELETION_FAILED                                                0x80000017
#define ORG_LABCRYPTO_ABETTOR_RESULT__DG1_WRITE_FAILED                                                   0x80000018
#define ORG_LABCRYPTO_ABETTOR_RESULT__DG1_READ_FAILED                                                    0x80000019
#define ORG_LABCRYPTO_ABETTOR_RESULT__BAC_RND_ICC_IS_INCORRECT                                           0x8000001A
#define ORG_LABCRYPTO_ABETTOR_RESULT__BAC_RND_IFD_IS_INCORRECT                                           0x0000001B
#define ORG_LABCRYPTO_ABETTOR_RESULT__BAC_E_ICC_MAC_IS_INCORRECT                                         0x8000001C
#define ORG_LABCRYPTO_ABETTOR_RESULT__MALFORMED_APDU_COMMAND                                             0x8000001D
#define ORG_LABCRYPTO_ABETTOR_RESULT__APDU_RESPONSE_MAC_IS_INCORRECT                                     0x8000001E
#define ORG_LABCRYPTO_ABETTOR_RESULT__INVALID_APDU_RESPONSE                                              0x8000001F
#define ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_EF_COM_DATA                                                  0x80000020
#define ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_EF_SOD_DATA                                                  0x80000021
#define ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_DG1_DATA                                                     0x80000022
#define ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_DG2_DATA                                                     0x80000023
#define ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_DG3_DATA                                                     0x80000024
#define ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_DG4_DATA                                                     0x80000025
#define ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_DG5_DATA                                                     0x80000026
#define ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_DG6_DATA                                                     0x80000027
#define ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_DG7_DATA                                                     0x80000028
#define ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_DG8_DATA                                                     0x80000029
#define ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_DG9_DATA                                                     0x8000002A
#define ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_DG10_DATA                                                    0x8000002B
#define ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_DG11_DATA                                                    0x8000002C
#define ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_DG12_DATA                                                    0x8000002D
#define ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_DG13_DATA                                                    0x8000002E
#define ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_DG14_DATA                                                    0x8000002F
#define ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_DG15_DATA                                                    0x80000030
#define ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_DG16_DATA                                                    0x80000031
#define ORG_LABCRYPTO_ABETTOR_RESULT__DG2_CREATION_FAILED                                                0x80000032
#define ORG_LABCRYPTO_ABETTOR_RESULT__DG2_NOT_SELECTED                                                   0x80000033
#define ORG_LABCRYPTO_ABETTOR_RESULT__DG2_DELETION_FAILED                                                0x80000034
#define ORG_LABCRYPTO_ABETTOR_RESULT__DG2_WRITE_FAILED                                                   0x80000035
#define ORG_LABCRYPTO_ABETTOR_RESULT__DG2_READ_FAILED                                                    0x80000036
#define ORG_LABCRYPTO_ABETTOR_RESULT__DG7_CREATION_FAILED                                                0x80000037
#define ORG_LABCRYPTO_ABETTOR_RESULT__DG7_NOT_SELECTED                                                   0x80000038
#define ORG_LABCRYPTO_ABETTOR_RESULT__DG7_DELETION_FAILED                                                0x80000039
#define ORG_LABCRYPTO_ABETTOR_RESULT__DG7_WRITE_FAILED                                                   0x8000003A
#define ORG_LABCRYPTO_ABETTOR_RESULT__DG7_READ_FAILED                                                    0x8000003B
#define ORG_LABCRYPTO_ABETTOR_RESULT__DG12_CREATION_FAILED                                               0x8000003C
#define ORG_LABCRYPTO_ABETTOR_RESULT__DG12_NOT_SELECTED                                                  0x8000003D
#define ORG_LABCRYPTO_ABETTOR_RESULT__DG12_DELETION_FAILED                                               0x8000003E
#define ORG_LABCRYPTO_ABETTOR_RESULT__DG12_WRITE_FAILED                                                  0x8000003F
#define ORG_LABCRYPTO_ABETTOR_RESULT__DG12_READ_FAILED                                                   0x80000040
#define ORG_LABCRYPTO_ABETTOR_RESULT__DG13_CREATION_FAILED                                               0x80000041
#define ORG_LABCRYPTO_ABETTOR_RESULT__DG13_NOT_SELECTED                                                  0x80000042
#define ORG_LABCRYPTO_ABETTOR_RESULT__DG13_DELETION_FAILED                                               0x80000043
#define ORG_LABCRYPTO_ABETTOR_RESULT__DG13_WRITE_FAILED                                                  0x80000044
#define ORG_LABCRYPTO_ABETTOR_RESULT__DG13_READ_FAILED                                                   0x80000045
#define ORG_LABCRYPTO_ABETTOR_RESULT__EF_SOD_CREATION_FAILED                                             0x80000046
#define ORG_LABCRYPTO_ABETTOR_RESULT__EF_SOD_NOT_SELECTED                                                0x80000047
#define ORG_LABCRYPTO_ABETTOR_RESULT__EF_SOD_DELETION_FAILED                                             0x80000048
#define ORG_LABCRYPTO_ABETTOR_RESULT__EF_SOD_WRITE_FAILED                                                0x80000049
#define ORG_LABCRYPTO_ABETTOR_RESULT__EF_SOD_READ_FAILED                                                 0x8000004A
#define ORG_LABCRYPTO_ABETTOR_RESULT__DG15_CREATION_FAILED                                               0x8000004B
#define ORG_LABCRYPTO_ABETTOR_RESULT__DG15_NOT_SELECTED                                                  0x8000004C
#define ORG_LABCRYPTO_ABETTOR_RESULT__DG15_DELETION_FAILED                                               0x8000004D
#define ORG_LABCRYPTO_ABETTOR_RESULT__DG15_WRITE_FAILED                                                  0x8000004E
#define ORG_LABCRYPTO_ABETTOR_RESULT__DG15_READ_FAILED                                                   0x8000004F

#define ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__SHARED_LIBRARY_NOT_FOUND                                   0x80000050
#define ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_GET_FUNCTION_LIST_FAILED                                 0x80000051
#define ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_INITIALIZE_FAILED                                        0x80000052
#define ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_GET_SLOT_LIST_FAILED                                     0x80000053
#define ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_GET_SLOT_INFO_FAILED                                     0x80000054
#define ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_GET_TOKEN_INFO_FAILED                                    0x80000055
#define ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_OPEN_SESSION_FAILED                                      0x80000056
#define ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_CLOSE_SESSION_FAILED                                     0x80000057
#define ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_LOGIN_FAILED                                             0x80000058
#define ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_FIND_OBJECTS_INIT_FAILED                                 0x80000059
#define ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_FIND_OBJECTS_FAILED                                      0x8000005a
#define ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_FIND_OBJECTS_FINAL_FAILED                                0x8000005b
#define ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__OBJECT_NOT_FOUND                                           0x8000005c
#define ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_LOGOUT_FAILED                                            0x8000005d
#define ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_ENCRYPT_INIT_FAILED                                      0x8000005e
#define ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_ENCRYPT_FAILED                                           0x8000005f
#define ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_SET_PIN_FAILED                                           0x80000060
#define ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_CREATE_OBJECT_FAILED                                     0x80000061

#define ORG_LABCRYPTO_ABETTOR_RESULT__REMOTE_SIGN_FAILED                                                 0x80000200

#define ORG_LABCRYPTO_ABETTOR_RESULT__GENERAL_ERROR                                                      0x80001000


#define ORG_LABCRYPTO_ABETTOR_RESULT__APDU_STATUS__90_00_SUCCESS                                          0x00000000
#define ORG_LABCRYPTO_ABETTOR_RESULT__APDU_STATUS__63_00_VERIFICATION_FAILED                              0x81000001
#define ORG_LABCRYPTO_ABETTOR_RESULT__APDU_STATUS__69_82_SECURITY_CONDITION_NOT_SATISFIED                 0x81000002
#define ORG_LABCRYPTO_ABETTOR_RESULT__APDU_STATUS__6A_82_FILE_NOT_FOUND                                   0x81000003
#define ORG_LABCRYPTO_ABETTOR_RESULT__APDU_STATUS__67_00_WRONG_LENGTH                                     0x81000004


void
ORG_LABCRYPTO_ABETTOR__error_get_string (
  unsigned int         /* Error code */, 
  unsigned char **     /* Pointer to string buffer */
);


void
ORG_LABCRYPTO_ABETTOR__error_print (
  unsigned int        /* Error code */
);


#ifdef __cplusplus
}
#endif

#endif

