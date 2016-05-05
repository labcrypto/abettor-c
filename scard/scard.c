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

#include <org/labcrypto/abettor/scard.h>
#include <org/labcrypto/abettor/log.h>


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__scard__open_context (
  ORG_LABCRYPTO_ABETTOR__scard__context_ptr scard_context_ptr
) {
#ifndef SCARD_SIMULATION
  ORG_LABCRYPTO_ABETTOR_uint32 result = SCardEstablishContext(SCARD_SCOPE_USER, NULL, NULL, scard_context_ptr);
  if (result != SCARD_S_SUCCESS) {
    printf ("INTERNAL SCARD ERROR: 0x%x\n", result);
    return ORG_LABCRYPTO_ABETTOR_RESULT__SCARD_CONTEXT_NOT_ESTABLISHED;
  }
#endif
  return ORG_LABCRYPTO_ABETTOR_RESULT__SUCCESS;
}


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__scard__close_context (
  ORG_LABCRYPTO_ABETTOR__scard__context scard_context
) {
#ifndef SCARD_SIMULATION
  SCardReleaseContext(scard_context);
#endif
  return ORG_LABCRYPTO_ABETTOR_RESULT__SUCCESS;
}


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__scard__enumerate_smart_cards (
  ORG_LABCRYPTO_ABETTOR__scard__context scard_context,
  ORG_LABCRYPTO_ABETTOR_string_ptr_ptr scard_names,
  ORG_LABCRYPTO_ABETTOR_uint32_ptr number_of_scards
) {
#ifndef SCARD_SIMULATION
#ifdef _WIN32
	LPTSTR          pmszReaders = NULL;
	LPTSTR          pReader;
	LONG            lReturn, lReturn2;
	DWORD           cch = SCARD_AUTOALLOCATE;
	ORG_LABCRYPTO_ABETTOR_uint32    i = 0;
	lReturn = SCardListReaders(scard_context, NULL, (LPTSTR)&pmszReaders, &cch);
	if (lReturn != SCARD_S_SUCCESS) {
		printf("INTERNAL SCARD ERROR: 0x%x\n", lReturn);
		return ORG_LABCRYPTO_ABETTOR_RESULT__SCARD_LIST_NOT_OBTAINED;
	}
	*scard_names = (ORG_LABCRYPTO_ABETTOR_string_ptr)malloc(10 * sizeof(ORG_LABCRYPTO_ABETTOR_string));
	pReader = pmszReaders;
	while ('\0' != *pReader) {
		(*scard_names)[i] = (unsigned char*)malloc(128 * sizeof(unsigned char));
		WideCharToMultiByte(CP_UTF8, 0, pReader, -1, (*scard_names)[i], 128, NULL, NULL);
		printf("Reader: %S\n", pReader);
		pReader = pReader + wcslen((wchar_t*)pReader) + 1;
		i++;
	}
	*number_of_scards = i;
	lReturn2 = SCardFreeMemory(scard_context, pmszReaders);
	if (SCARD_S_SUCCESS != lReturn2) {
		printf("Failed SCardFreeMemory\n");
	}
#else
  unsigned char sc_names[256];
  DWORD num_sc_names = 256;
  ORG_LABCRYPTO_ABETTOR_uint32 result = SCardListReaders(scard_context, NULL, sc_names, &num_sc_names);
  if (result != SCARD_S_SUCCESS) {
    printf ("INTERNAL SCARD ERROR: 0x%x\n", result);
    return ORG_LABCRYPTO_ABETTOR_RESULT__SCARD_LIST_NOT_OBTAINED;
  }
  if (num_sc_names == 0) {
    return ORG_LABCRYPTO_ABETTOR_RESULT__NO_SCARD_IS_FOUND;
  }  
  *scard_names = (ORG_LABCRYPTO_ABETTOR_string_ptr)malloc(10 * sizeof(ORG_LABCRYPTO_ABETTOR_string));
  char *p = sc_names;
  ORG_LABCRYPTO_ABETTOR_uint32 i = 0;
  while (*p != 0 && i < num_sc_names) {
    (*scard_names)[i] = (unsigned char*)malloc(128 * sizeof(unsigned char));
    strcpy((*scard_names)[i], p);
    p += strlen(p) + 1;
    i++;
  }
  *number_of_scards = i;
#endif
#else
  *number_of_scards = 1;
  *scard_names = (ORG_LABCRYPTO_ABETTOR_string_ptr)malloc(sizeof(ORG_LABCRYPTO_ABETTOR_string));
  (*scard_names)[0] = "Simulated Smart Card";
#endif
  return ORG_LABCRYPTO_ABETTOR_RESULT__SUCCESS;
}


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__scard__connect_card (
  ORG_LABCRYPTO_ABETTOR__scard__context scard_context,
  ORG_LABCRYPTO_ABETTOR_string scard_name,
  ORG_LABCRYPTO_ABETTOR__scard__handle_ptr scard_handle_ptr
) {
#ifndef SCARD_SIMULATION
#ifndef _WIN32
  DWORD dwProtocol = 0;
  ORG_LABCRYPTO_ABETTOR_uint32 result = SCardConnect(scard_context, scard_name, SCARD_SHARE_EXCLUSIVE, 
    SCARD_PROTOCOL_T0 | SCARD_PROTOCOL_T1, scard_handle_ptr, &dwProtocol);
#else
  DWORD dwProtocol = 0;
  ORG_LABCRYPTO_ABETTOR_uint32 result = 0;
  int wchars_num = MultiByteToWideChar(CP_UTF8, 0, scard_name, -1, NULL, 0);
  wchar_t* wstr = malloc(wchars_num * sizeof(wchar_t));
  MultiByteToWideChar(CP_UTF8, 0, scard_name, -1, wstr, wchars_num);
  result = SCardConnect(scard_context, wstr, SCARD_SHARE_EXCLUSIVE,
	SCARD_PROTOCOL_T0 | SCARD_PROTOCOL_T1, scard_handle_ptr, &dwProtocol);
  free(wstr);
#endif
  if (result != SCARD_S_SUCCESS) {
    printf ("INTERNAL SCARD ERROR: 0x%x\n", result);
    // return ORG_LABCRYPTO_ABETTOR_RESULT__SCARD_CAN_NOT_BE_CONNECTED;
	return result;
  }
#endif
  return ORG_LABCRYPTO_ABETTOR_RESULT__SUCCESS;
}

ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__scard__disconnect_card (
  ORG_LABCRYPTO_ABETTOR__scard__handle scard_handle
) {
#ifndef SCARD_SIMULATION
  ORG_LABCRYPTO_ABETTOR_uint32 result = SCardDisconnect(scard_handle, SCARD_UNPOWER_CARD);  
  if (result != SCARD_S_SUCCESS) {
    printf ("INTERNAL SCARD ERROR: 0x%x\n", result);
    return ORG_LABCRYPTO_ABETTOR_RESULT__SCARD_CAN_NOT_BE_DISCONNECTED;
  }
#endif
  return ORG_LABCRYPTO_ABETTOR_RESULT__SUCCESS;
}


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__scard__transmit (
  ORG_LABCRYPTO_ABETTOR__scard__handle scard_handle,
  ORG_LABCRYPTO_ABETTOR_data send_buffer,
  ORG_LABCRYPTO_ABETTOR_uint32 send_buffer_length,
  ORG_LABCRYPTO_ABETTOR_data recv_buffer,
  ORG_LABCRYPTO_ABETTOR_uint32_ptr recv_buffer_length
) {
#ifndef SCARD_SIMULATION
  ORG_LABCRYPTO_ABETTOR_char error[128];
  SCARD_IO_REQUEST send_io = {SCARD_PROTOCOL_T1, sizeof(SCARD_IO_REQUEST)};
  SCARD_IO_REQUEST recv_io = {SCARD_PROTOCOL_T1, sizeof(SCARD_IO_REQUEST)};
  DWORD buffer_length = *recv_buffer_length;
  ORG_LABCRYPTO_ABETTOR_uint32 result = 
    SCardTransmit (
      scard_handle, 
      &send_io, 
      send_buffer, 
      send_buffer_length, 
      &recv_io, 
      recv_buffer, 
      &buffer_length
    );
  if (result != SCARD_S_SUCCESS) {
    printf ("INTERNAL SCARD ERROR: 0x%x\n", result);
    return ORG_LABCRYPTO_ABETTOR_RESULT__SCARD_TRANSMIT_ERROR;
  }
  *recv_buffer_length = buffer_length;
  if (recv_buffer[buffer_length - 2] == 0x90 && recv_buffer[buffer_length - 1] == 0x00) {
    return ORG_LABCRYPTO_ABETTOR_RESULT__APDU_STATUS__90_00_SUCCESS;
  }
  sprintf(error, "Transmit error: 0x%02x 0x%02x.", (ORG_LABCRYPTO_ABETTOR_uint32)recv_buffer[buffer_length - 2], 
                                            (ORG_LABCRYPTO_ABETTOR_uint32)recv_buffer[buffer_length - 1]);
  ORG_LABCRYPTO_ABETTOR__log__error("epass-reader", error);
  if (recv_buffer[buffer_length - 2] == 0x63 && recv_buffer[buffer_length - 1] == 0x00) {
    return ORG_LABCRYPTO_ABETTOR_RESULT__APDU_STATUS__63_00_VERIFICATION_FAILED;
  }
  if (recv_buffer[buffer_length - 2] == 0x69 && recv_buffer[buffer_length - 1] == 0x82) {
    return ORG_LABCRYPTO_ABETTOR_RESULT__APDU_STATUS__69_82_SECURITY_CONDITION_NOT_SATISFIED;
  }
  if (recv_buffer[buffer_length - 2] == 0x6a && recv_buffer[buffer_length - 1] == 0x82) {
    return ORG_LABCRYPTO_ABETTOR_RESULT__APDU_STATUS__6A_82_FILE_NOT_FOUND;
  }
  if (recv_buffer[buffer_length - 2] == 0x67 && recv_buffer[buffer_length - 1] == 0x00) {
    return ORG_LABCRYPTO_ABETTOR_RESULT__APDU_STATUS__67_00_WRONG_LENGTH;
  }
  return ORG_LABCRYPTO_ABETTOR_RESULT__SCARD_TRANSMIT_ERROR;
#else
  return ORG_LABCRYPTO_ABETTOR_RESULT__APDU_STATUS__90_00_SUCCESS;
#endif
}
