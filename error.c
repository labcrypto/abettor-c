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
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <org/labcrypto/abettor/error.h>


void
ORG_LABCRYPTO_ABETTOR_error_get_string (
  unsigned int error_code, 
  unsigned char ** buffer
) {
  *buffer = (unsigned char*)malloc(128 * sizeof(unsigned char));
  strcpy(*buffer, "Unknown Error.");
  switch (error_code) {
    case ORG_LABCRYPTO_ABETTOR_RESULT__ERROR_INVALID_MRZ_DATA:
      strcpy(*buffer, "Invalid MRZ Data.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__ERROR_INVALID_MRZ_CHARACTER:
      strcpy(*buffer, "Invalid MRZ Character.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__BUFFER_SIZE_TOO_LOW:
      strcpy(*buffer, "Buffer size too low.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__INVALID_DES_KEY:
      strcpy(*buffer, "Invalid DES Key.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__SCARD_CONTEXT_NOT_ESTABLISHED:
      strcpy(*buffer, "Smart Card Context is not establishded.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__SCARD_LIST_NOT_OBTAINED:
      strcpy(*buffer, "Smart Card List not obtained.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__NO_SCARD_IS_FOUND:
      strcpy(*buffer, "No Smart Card is found.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__SCARD_CAN_NOT_BE_CONNECTED:
      strcpy(*buffer, "Smart Card can't be connected.");
    case ORG_LABCRYPTO_ABETTOR_RESULT__SCARD_CAN_NOT_BE_DISCONNECTED:
      strcpy(*buffer, "Smart Card can't be disconnected.");
      break;      
    case ORG_LABCRYPTO_ABETTOR_RESULT__SCARD_TRANSMIT_ERROR:
      strcpy(*buffer, "Smart Card Transmit Error.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__UNABLE_TO_GET_CHIP_SERIAL:
      strcpy(*buffer, "Unable to get Chip Serial Number (CSN).");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__UNABLE_TO_GET_CHALLENGE_NUMBER:
      strcpy(*buffer, "Unable to get challenge number.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__PERSO_EXT_AUTH_FAILED:
      strcpy(*buffer, "External Authentication failed with provided Perso Key.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__UPDATE_EXT_AUTH_FAILED:
      strcpy(*buffer, "External Authentication failed with provided Update Key.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__READ_EXT_AUTH_FAILED:
      strcpy(*buffer, "External Authentication failed with provided Read Key.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__EF_COM_CREATION_FAILED:
      strcpy(*buffer, "EF.COM can't be created.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__EF_COM_NOT_SELECTED:
      strcpy(*buffer, "EF.COM can't be selected.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__EF_COM_DELETION_FAILED:
      strcpy(*buffer, "EF.COM can't be deleted.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__EF_COM_WRITE_FAILED:
      strcpy(*buffer, "EF.COM write failed.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__EF_COM_READ_FAILED:
      strcpy(*buffer, "EF.COM read failed.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__EF_SOD_CREATION_FAILED:
      strcpy(*buffer, "EF.SOD can't be created.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__EF_SOD_NOT_SELECTED:
      strcpy(*buffer, "EF.SOD can't be selected.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__EF_SOD_DELETION_FAILED:
      strcpy(*buffer, "EF.SOD can't be deleted.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__EF_SOD_WRITE_FAILED:
      strcpy(*buffer, "EF.SOD write failed.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__EF_SOD_READ_FAILED:
      strcpy(*buffer, "EF.SOD read failed.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__DG1_CREATION_FAILED:
      strcpy(*buffer, "DG1 can't be created.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__DG1_NOT_SELECTED:
      strcpy(*buffer, "DG1 can't be selected.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__DG1_DELETION_FAILED:
      strcpy(*buffer, "DG1 can't be deleted.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__DG1_WRITE_FAILED:
      strcpy(*buffer, "DG1 write failed.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__DG1_READ_FAILED:
      strcpy(*buffer, "DG1 read failed.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__DG2_CREATION_FAILED:
      strcpy(*buffer, "DG2 can't be created.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__DG2_NOT_SELECTED:
      strcpy(*buffer, "DG2 can't be selected.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__DG2_DELETION_FAILED:
      strcpy(*buffer, "DG2 can't be deleted.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__DG2_WRITE_FAILED:
      strcpy(*buffer, "DG2 write failed.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__DG2_READ_FAILED:
      strcpy(*buffer, "DG2 read failed.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__DG7_CREATION_FAILED:
      strcpy(*buffer, "DG7 can't be created.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__DG7_NOT_SELECTED:
      strcpy(*buffer, "DG7 can't be selected.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__DG7_DELETION_FAILED:
      strcpy(*buffer, "DG7 can't be deleted.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__DG7_WRITE_FAILED:
      strcpy(*buffer, "DG7 write failed.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__DG7_READ_FAILED:
      strcpy(*buffer, "DG7 read failed.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__DG12_CREATION_FAILED:
      strcpy(*buffer, "DG12 can't be created.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__DG12_NOT_SELECTED:
      strcpy(*buffer, "DG12 can't be selected.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__DG12_DELETION_FAILED:
      strcpy(*buffer, "DG12 can't be deleted.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__DG12_WRITE_FAILED:
      strcpy(*buffer, "DG12 write failed.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__DG12_READ_FAILED:
      strcpy(*buffer, "DG12 read failed.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__DG13_CREATION_FAILED:
      strcpy(*buffer, "DG13 can't be created.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__DG13_NOT_SELECTED:
      strcpy(*buffer, "DG13 can't be selected.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__DG13_DELETION_FAILED:
      strcpy(*buffer, "DG13 can't be deleted.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__DG13_WRITE_FAILED:
      strcpy(*buffer, "DG13 write failed.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__DG13_READ_FAILED:
      strcpy(*buffer, "DG13 read failed.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__DG15_CREATION_FAILED:
      strcpy(*buffer, "DG15 can't be created.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__DG15_NOT_SELECTED:
      strcpy(*buffer, "DG15 can't be selected.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__DG15_DELETION_FAILED:
      strcpy(*buffer, "DG15 can't be deleted.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__DG15_WRITE_FAILED:
      strcpy(*buffer, "DG15 write failed.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__DG15_READ_FAILED:
      strcpy(*buffer, "DG15 read failed.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__BAC_RND_ICC_IS_INCORRECT:
      strcpy(*buffer, "BAC: RND_ICC is incorrect.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__BAC_RND_IFD_IS_INCORRECT:
      strcpy(*buffer, "BAC: RND_IFD is incorrect.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__BAC_E_ICC_MAC_IS_INCORRECT:
      strcpy(*buffer, "BAC: E_ICC MAC is incorrect.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__MALFORMED_APDU_COMMAND:
      strcpy(*buffer, "BAC: Malformed APDU command.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__APDU_RESPONSE_MAC_IS_INCORRECT:
      strcpy(*buffer, "APDU response MAC is incorrect.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__INVALID_APDU_RESPONSE:
      strcpy(*buffer, "Invalid APDU response.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_EF_COM_DATA:
      strcpy(*buffer, "Wrong EF.COM data.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_EF_SOD_DATA:
      strcpy(*buffer, "Wrong EF.SOD data.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_DG1_DATA:
      strcpy(*buffer, "Wrong DG1 data.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_DG2_DATA:
      strcpy(*buffer, "Wrong DG2 data.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_DG3_DATA:
      strcpy(*buffer, "Wrong DG3 data.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_DG4_DATA:
      strcpy(*buffer, "Wrong DG4 data.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_DG5_DATA:
      strcpy(*buffer, "Wrong DG5 data.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_DG6_DATA:
      strcpy(*buffer, "Wrong DG6 data.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_DG7_DATA:
      strcpy(*buffer, "Wrong DG7 data.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_DG8_DATA:
      strcpy(*buffer, "Wrong DG8 data.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_DG9_DATA:
      strcpy(*buffer, "Wrong DG9 data.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_DG10_DATA:
      strcpy(*buffer, "Wrong DG10 data.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_DG11_DATA:
      strcpy(*buffer, "Wrong DG11 data.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_DG12_DATA:
      strcpy(*buffer, "Wrong DG12 data.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_DG13_DATA:
      strcpy(*buffer, "Wrong DG13 data.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_DG14_DATA:
      strcpy(*buffer, "Wrong DG14 data.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_DG15_DATA:
      strcpy(*buffer, "Wrong DG15 data.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__WRONG_DG16_DATA:
      strcpy(*buffer, "Wrong DG16 data.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__GENERAL_ERROR:
      strcpy(*buffer, "General Error.");
      break;
  }
  switch(error_code) {
    case ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__SHARED_LIBRARY_NOT_FOUND:
      strcpy(*buffer, "PKCS11: Shared Library not found.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__GET_FUNCTION_LIST_FAILED:
      strcpy(*buffer, "PKCS11: C_GetFunctionList failed.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_INITIALIZE_FAILED:
      strcpy(*buffer, "PKCS11: C_Initialize failed.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_GET_SLOT_LIST_FAILED:
      strcpy(*buffer, "PKCS11: C_GetSlotList failed.");
      break;
     case ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_GET_SLOT_INFO_FAILED:
      strcpy(*buffer, "PKCS11: C_GetSlotInfo failed.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_GET_TOKEN_INFO_FAILED:
      strcpy(*buffer, "PKCS11: C_GetTokenInfo failed.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_OPEN_SESSION_FAILED:
      strcpy(*buffer, "PKCS11: C_OpenSession failed.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_CLOSE_SESSION_FAILED:
      strcpy(*buffer, "PKCS11: C_CloseSession failed.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_LOGIN_FAILED:
      strcpy(*buffer, "PKCS11: C_Login failed.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_FIND_OBJECTS_INIT_FAILED:
      strcpy(*buffer, "PKCS11: C_FindObjectsInit failed.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_FIND_OBJECTS_FAILED:
      strcpy(*buffer, "PKCS11: C_FindObjects failed.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_FIND_OBJECTS_FINAL_FAILED:
      strcpy(*buffer, "PKCS11: C_FindObjectsFinal failed.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__OBJECT_NOT_FOUND:
      strcpy(*buffer, "PKCS11: Object not found.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_LOGOUT_FAILED:
      strcpy(*buffer, "PKCS11: C_Logout failed.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_ENCRYPT_INIT_FAILED:
      strcpy(*buffer, "PKCS11: C_EncryptInit failed.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_ENCRYPT_FAILED:
      strcpy(*buffer, "PKCS11: C_Encrypt failed.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT___REMOTE_SIGN_FAILED:
      strcpy(*buffer, "Remote Sign failed.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__PKCS11__C_SET_PIN_FAILED:
      strcpy(*bufferm "Set Pin failed.");
      break;
  }
  switch(error_code) {
    case ORG_LABCRYPTO_ABETTOR_RESULT__APDU_STATUS__63_00_VERIFICATION_FAILED:
      strcpy(*buffer, "APDU Repsonse: 0x63 0x00 -> Verification failed.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__APDU_STATUS__6A_82_FILE_NOT_FOUND:
      strcpy(*buffer, "APDU Response: 0x6A 0x82 -> File not found.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__APDU_STATUS__69_82_SECURITY_CONDITION_NOT_SATISFIED:
      strcpy(*buffer, "APDU Repsonse: 0x69 0x82 -> Security conditions not satisfied.");
      break;
    case ORG_LABCRYPTO_ABETTOR_RESULT__APDU_STATUS__67_00_WRONG_LENGTH:
      strcpy(*buffer, "APDU Repsonse: 0x67 0x00 -> Wrong length.");
      break;
  }
}


void
ORG_LABCRYPTO_ABETTOR_error_print (
  unsigned int error_code
) {
  unsigned char *message;
  ORG_LABCRYPTO_ABETTOR_error_get_string(error_code, &message);
  printf("ERROR: %s\n", message);
  free(message);
}
