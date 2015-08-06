#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <naeem/error.h>


void
NAEEM_error_get_string (unsigned int error_code, 
                        unsigned char ** buffer) {
  *buffer = (unsigned char*)malloc(128 * sizeof(unsigned char));
  strcpy(*buffer, "Unknown Error.");
  switch (error_code) {
    case NAEEM_RESULT_ERROR_INVALID_MRZ_DATA:
      strcpy(*buffer, "Invalid MRZ Data.");
      break;
    case NAEEM_RESULT_ERROR_INVALID_MRZ_CHARACTER:
      strcpy(*buffer, "Invalid MRZ Character.");
      break;
    case NAEEM_RESULT_BUFFER_SIZE_TOO_LOW:
      strcpy(*buffer, "Buffer size too low.");
      break;
    case NAEEM_RESULT_INVALID_DES_KEY:
      strcpy(*buffer, "Invalid DES Key.");
      break;
    case NAEEM_RESULT_SCARD_CONTEXT_NOT_ESTABLISHED:
      strcpy(*buffer, "Smart Card Context is not establishded.");
      break;
    case NAEEM_RESULT_SCARD_LIST_NOT_OBTAINED:
      strcpy(*buffer, "Smart Card List not obtained.");
      break;
    case NAEEM_RESULT_NO_SCARD_IS_FOUND:
      strcpy(*buffer, "No Smart Card is found.");
      break;
    case NAEEM_RESULT_SCARD_CAN_NOT_BE_CONNECTED:
      strcpy(*buffer, "Smart Card can't be connected.");
    case NAEEM_RESULT_SCARD_CAN_NOT_BE_DISCONNECTED:
      strcpy(*buffer, "Smart Card can't be disconnected.");
      break;      
    case NAEEM_RESULT_SCARD_TRANSMIT_ERROR:
      strcpy(*buffer, "Smart Card Transmit Error.");
      break;
    case NAEEM_RESULT_UNABLE_TO_GET_CHIP_SERIAL:
      strcpy(*buffer, "Unable to get Chip Serial Number (CSN).");
      break;
    case NAEEM_RESULT_UNABLE_TO_GET_CHALLENGE_NUMBER:
      strcpy(*buffer, "Unable to get challenge number.");
      break;
    case NAEEM_RESULT_PERSO_EXT_AUTH_FAILED:
      strcpy(*buffer, "External Authentication failed with provided Perso Key.");
      break;
    case NAEEM_RESULT_UPDATE_EXT_AUTH_FAILED:
      strcpy(*buffer, "External Authentication failed with provided Update Key.");
      break;
    case NAEEM_RESULT_READ_EXT_AUTH_FAILED:
      strcpy(*buffer, "External Authentication failed with provided Read Key.");
      break;
    case NAEEM_RESULT_EF_COM_CREATION_FAILED:
      strcpy(*buffer, "EF.COM can't be created.");
      break;
    case NAEEM_RESULT_EF_COM_NOT_SELECTED:
      strcpy(*buffer, "EF.COM can't be selected.");
      break;
    case NAEEM_RESULT_EF_COM_DELETION_FAILED:
      strcpy(*buffer, "EF.COM can't be deleted.");
      break;
    case NAEEM_RESULT_EF_COM_WRITE_FAILED:
      strcpy(*buffer, "EF.COM write failed.");
      break;
    case NAEEM_RESULT_EF_COM_READ_FAILED:
      strcpy(*buffer, "EF.COM read failed.");
      break;
    case NAEEM_RESULT_EF_SOD_CREATION_FAILED:
      strcpy(*buffer, "EF.SOD can't be created.");
      break;
    case NAEEM_RESULT_EF_SOD_NOT_SELECTED:
      strcpy(*buffer, "EF.SOD can't be selected.");
      break;
    case NAEEM_RESULT_EF_SOD_DELETION_FAILED:
      strcpy(*buffer, "EF.SOD can't be deleted.");
      break;
    case NAEEM_RESULT_EF_SOD_WRITE_FAILED:
      strcpy(*buffer, "EF.SOD write failed.");
      break;
    case NAEEM_RESULT_EF_SOD_READ_FAILED:
      strcpy(*buffer, "EF.SOD read failed.");
      break;
    case NAEEM_RESULT_DG1_CREATION_FAILED:
      strcpy(*buffer, "DG1 can't be created.");
      break;
    case NAEEM_RESULT_DG1_NOT_SELECTED:
      strcpy(*buffer, "DG1 can't be selected.");
      break;
    case NAEEM_RESULT_DG1_DELETION_FAILED:
      strcpy(*buffer, "DG1 can't be deleted.");
      break;
    case NAEEM_RESULT_DG1_WRITE_FAILED:
      strcpy(*buffer, "DG1 write failed.");
      break;
    case NAEEM_RESULT_DG1_READ_FAILED:
      strcpy(*buffer, "DG1 read failed.");
      break;
    case NAEEM_RESULT_DG2_CREATION_FAILED:
      strcpy(*buffer, "DG2 can't be created.");
      break;
    case NAEEM_RESULT_DG2_NOT_SELECTED:
      strcpy(*buffer, "DG2 can't be selected.");
      break;
    case NAEEM_RESULT_DG2_DELETION_FAILED:
      strcpy(*buffer, "DG2 can't be deleted.");
      break;
    case NAEEM_RESULT_DG2_WRITE_FAILED:
      strcpy(*buffer, "DG2 write failed.");
      break;
    case NAEEM_RESULT_DG2_READ_FAILED:
      strcpy(*buffer, "DG2 read failed.");
      break;
    case NAEEM_RESULT_DG7_CREATION_FAILED:
      strcpy(*buffer, "DG7 can't be created.");
      break;
    case NAEEM_RESULT_DG7_NOT_SELECTED:
      strcpy(*buffer, "DG7 can't be selected.");
      break;
    case NAEEM_RESULT_DG7_DELETION_FAILED:
      strcpy(*buffer, "DG7 can't be deleted.");
      break;
    case NAEEM_RESULT_DG7_WRITE_FAILED:
      strcpy(*buffer, "DG7 write failed.");
      break;
    case NAEEM_RESULT_DG7_READ_FAILED:
      strcpy(*buffer, "DG7 read failed.");
      break;
    case NAEEM_RESULT_DG12_CREATION_FAILED:
      strcpy(*buffer, "DG12 can't be created.");
      break;
    case NAEEM_RESULT_DG12_NOT_SELECTED:
      strcpy(*buffer, "DG12 can't be selected.");
      break;
    case NAEEM_RESULT_DG12_DELETION_FAILED:
      strcpy(*buffer, "DG12 can't be deleted.");
      break;
    case NAEEM_RESULT_DG12_WRITE_FAILED:
      strcpy(*buffer, "DG12 write failed.");
      break;
    case NAEEM_RESULT_DG12_READ_FAILED:
      strcpy(*buffer, "DG12 read failed.");
      break;
    case NAEEM_RESULT_DG13_CREATION_FAILED:
      strcpy(*buffer, "DG13 can't be created.");
      break;
    case NAEEM_RESULT_DG13_NOT_SELECTED:
      strcpy(*buffer, "DG13 can't be selected.");
      break;
    case NAEEM_RESULT_DG13_DELETION_FAILED:
      strcpy(*buffer, "DG13 can't be deleted.");
      break;
    case NAEEM_RESULT_DG13_WRITE_FAILED:
      strcpy(*buffer, "DG13 write failed.");
      break;
    case NAEEM_RESULT_DG13_READ_FAILED:
      strcpy(*buffer, "DG13 read failed.");
      break;
    case NAEEM_RESULT_DG15_CREATION_FAILED:
      strcpy(*buffer, "DG15 can't be created.");
      break;
    case NAEEM_RESULT_DG15_NOT_SELECTED:
      strcpy(*buffer, "DG15 can't be selected.");
      break;
    case NAEEM_RESULT_DG15_DELETION_FAILED:
      strcpy(*buffer, "DG15 can't be deleted.");
      break;
    case NAEEM_RESULT_DG15_WRITE_FAILED:
      strcpy(*buffer, "DG15 write failed.");
      break;
    case NAEEM_RESULT_DG15_READ_FAILED:
      strcpy(*buffer, "DG15 read failed.");
      break;
    case NAEEM_RESULT_BAC_RND_ICC_IS_INCORRECT:
      strcpy(*buffer, "BAC: RND_ICC is incorrect.");
      break;
    case NAEEM_RESULT_BAC_RND_IFD_IS_INCORRECT:
      strcpy(*buffer, "BAC: RND_IFD is incorrect.");
      break;
    case NAEEM_RESULT_BAC_E_ICC_MAC_IS_INCORRECT:
      strcpy(*buffer, "BAC: E_ICC MAC is incorrect.");
      break;
    case NAEEM_RESULT_MALFORMED_APDU_COMMAND:
      strcpy(*buffer, "BAC: Malformed APDU command.");
      break;
    case NAEEM_RESULT_APDU_RESPONSE_MAC_IS_INCORRECT:
      strcpy(*buffer, "APDU response MAC is incorrect.");
      break;
    case NAEEM_RESULT_INVALID_APDU_RESPONSE:
      strcpy(*buffer, "Invalid APDU response.");
      break;
    case NAEEM_RESULT_WRONG_EF_COM_DATA:
      strcpy(*buffer, "Wrong EF.COM data.");
      break;
    case NAEEM_RESULT_WRONG_EF_SOD_DATA:
      strcpy(*buffer, "Wrong EF.SOD data.");
      break;
    case NAEEM_RESULT_WRONG_DG1_DATA:
      strcpy(*buffer, "Wrong DG1 data.");
      break;
    case NAEEM_RESULT_WRONG_DG2_DATA:
      strcpy(*buffer, "Wrong DG2 data.");
      break;
    case NAEEM_RESULT_WRONG_DG3_DATA:
      strcpy(*buffer, "Wrong DG3 data.");
      break;
    case NAEEM_RESULT_WRONG_DG4_DATA:
      strcpy(*buffer, "Wrong DG4 data.");
      break;
    case NAEEM_RESULT_WRONG_DG5_DATA:
      strcpy(*buffer, "Wrong DG5 data.");
      break;
    case NAEEM_RESULT_WRONG_DG6_DATA:
      strcpy(*buffer, "Wrong DG6 data.");
      break;
    case NAEEM_RESULT_WRONG_DG7_DATA:
      strcpy(*buffer, "Wrong DG7 data.");
      break;
    case NAEEM_RESULT_WRONG_DG8_DATA:
      strcpy(*buffer, "Wrong DG8 data.");
      break;
    case NAEEM_RESULT_WRONG_DG9_DATA:
      strcpy(*buffer, "Wrong DG9 data.");
      break;
    case NAEEM_RESULT_WRONG_DG10_DATA:
      strcpy(*buffer, "Wrong DG10 data.");
      break;
    case NAEEM_RESULT_WRONG_DG11_DATA:
      strcpy(*buffer, "Wrong DG11 data.");
      break;
    case NAEEM_RESULT_WRONG_DG12_DATA:
      strcpy(*buffer, "Wrong DG12 data.");
      break;
    case NAEEM_RESULT_WRONG_DG13_DATA:
      strcpy(*buffer, "Wrong DG13 data.");
      break;
    case NAEEM_RESULT_WRONG_DG14_DATA:
      strcpy(*buffer, "Wrong DG14 data.");
      break;
    case NAEEM_RESULT_WRONG_DG15_DATA:
      strcpy(*buffer, "Wrong DG15 data.");
      break;
    case NAEEM_RESULT_WRONG_DG16_DATA:
      strcpy(*buffer, "Wrong DG16 data.");
      break;
    case NAEEM_RESULT_GENERAL_ERROR:
      strcpy(*buffer, "General Error.");
      break;
  }
  switch(error_code) {
    case NAEEM_RESULT_PKCS11__SHARED_LIBRARY_NOT_FOUND:
      strcpy(*buffer, "PKCS11: Shared Library not found.");
      break;
    case NAEEM_RESULT_PKCS11__GET_FUNCTION_LIST_FAILED:
      strcpy(*buffer, "PKCS11: C_GetFunctionList failed.");
      break;
    case NAEEM_RESULT_PKCS11__C_INITIALIZE_FAILED:
      strcpy(*buffer, "PKCS11: C_Initialize failed.");
      break;
  }
  switch(error_code) {
    case NAEEM_RESULT_APDU_STATUS_63_00_VERIFICATION_FAILED:
      strcpy(*buffer, "APDU Repsonse: 0x63 0x00 -> Verification failed.");
      break;
    case NAEEM_RESULT_APDU_STATUS_6A_82_FILE_NOT_FOUND:
      strcpy(*buffer, "APDU Response: 0x6A 0x82 -> File not found.");
      break;
    case NAEEM_RESULT_APDU_STATUS_69_82_SECURITY_CONDITION_NOT_SATISFIED:
      strcpy(*buffer, "APDU Repsonse: 0x69 0x82 -> Security conditions not satisfied.");
      break;
    case NAEEM_RESULT_APDU_STATUS_67_00_WRONG_LENGTH:
      strcpy(*buffer, "APDU Repsonse: 0x67 0x00 -> Wrong length.");
      break;
  }
}


void
NAEEM_error_print (unsigned int error_code) {
  unsigned char *message;
  NAEEM_error_get_string(error_code, &message);
  printf("ERROR: %s\n", message);
  free(message);
}
