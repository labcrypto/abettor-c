/*  The MIT License (MIT)
 *
 *  Copyright (c) 2015 Noavaran Tejarat Gostar ORG_LABCRYPTO_ABETTOR Co.
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
 
#include <stdint.h>
#include <stdlib.h>

#include <org/labcrypto/abettor/base64.h>


static ORG_LABCRYPTO_ABETTOR_byte encoding_table[] = {
  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
  'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
  'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
  'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
  'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
  'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
  'w', 'x', 'y', 'z', '0', '1', '2', '3',
  '4', '5', '6', '7', '8', '9', '+', '/'
};
static ORG_LABCRYPTO_ABETTOR_byte *decoding_table = NULL;
static ORG_LABCRYPTO_ABETTOR_uint32 mod_table[] = {0, 2, 1};

void 
__base64_setup_decoding_table__() {
  ORG_LABCRYPTO_ABETTOR_counter i;
  decoding_table = malloc(256);
  for (i = 0; i < 64; i++) {
    decoding_table[(ORG_LABCRYPTO_ABETTOR_byte) encoding_table[i]] = i;
  }
}


void 
__base64_cleanup__() {
  free(decoding_table);
}


ORG_LABCRYPTO_ABETTOR_data
ORG_LABCRYPTO_ABETTOR__crypto_base64__encode (
  ORG_LABCRYPTO_ABETTOR_data data,
  ORG_LABCRYPTO_ABETTOR_length data_length,
  ORG_LABCRYPTO_ABETTOR_length_ptr length_ptr
) {
  ORG_LABCRYPTO_ABETTOR_counter i, j;
  ORG_LABCRYPTO_ABETTOR_data encoded_data;
  ORG_LABCRYPTO_ABETTOR_uint32 octet_a;
  ORG_LABCRYPTO_ABETTOR_uint32 octet_b;
  ORG_LABCRYPTO_ABETTOR_uint32 octet_c;
  ORG_LABCRYPTO_ABETTOR_uint32 triple;
  __base64_setup_decoding_table__();
  *length_ptr = 4 * ((data_length + 2) / 3);
  encoded_data = malloc(*length_ptr + 1);
  if (encoded_data == NULL) {
    return NULL;
  }
  for (i = 0, j = 0; i < data_length;) {
    octet_a = i < data_length ? (ORG_LABCRYPTO_ABETTOR_byte)data[i++] : 0;
    octet_b = i < data_length ? (ORG_LABCRYPTO_ABETTOR_byte)data[i++] : 0;
    octet_c = i < data_length ? (ORG_LABCRYPTO_ABETTOR_byte)data[i++] : 0;
    triple = (octet_a << 0x10) + (octet_b << 0x08) + octet_c;
    encoded_data[j++] = encoding_table[(triple >> 3 * 6) & 0x3F];
    encoded_data[j++] = encoding_table[(triple >> 2 * 6) & 0x3F];
    encoded_data[j++] = encoding_table[(triple >> 1 * 6) & 0x3F];
    encoded_data[j++] = encoding_table[(triple >> 0 * 6) & 0x3F];
  }
  for (i = 0; i < mod_table[data_length % 3]; i++) {
    encoded_data[*length_ptr - 1 - i] = '=';
  }
  encoded_data[*length_ptr] = 0;
  __base64_cleanup__();
  return encoded_data;
}

  
ORG_LABCRYPTO_ABETTOR_data
ORG_LABCRYPTO_ABETTOR__crypto_base64__decode (
  ORG_LABCRYPTO_ABETTOR_data str,
  ORG_LABCRYPTO_ABETTOR_length string_length,
  ORG_LABCRYPTO_ABETTOR_length_ptr length_ptr
) {
  ORG_LABCRYPTO_ABETTOR_data decoded_data;
  ORG_LABCRYPTO_ABETTOR_counter i, j;
  ORG_LABCRYPTO_ABETTOR_uint32 sxtet_a;
  ORG_LABCRYPTO_ABETTOR_uint32 sxtet_b;
  ORG_LABCRYPTO_ABETTOR_uint32 sxtet_c;
  ORG_LABCRYPTO_ABETTOR_uint32 sxtet_d;
  ORG_LABCRYPTO_ABETTOR_uint32 triple;
  __base64_setup_decoding_table__();
  if (string_length % 4 != 0) {
    return NULL;
  }
  *length_ptr = string_length / 4 * 3;
  if (str[string_length - 1] == '=') {
    (*length_ptr)--;
  }
  if (str[string_length - 2] == '=') {
    (*length_ptr)--;
  }
  decoded_data = malloc(*length_ptr);
  if (decoded_data == NULL) {
    return NULL;
  }
  for (i = 0, j = 0; i < string_length;) {
    sxtet_a = str[i] == '=' ? 0 & i++ : decoding_table[str[i++]];
    sxtet_b = str[i] == '=' ? 0 & i++ : decoding_table[str[i++]];
    sxtet_c = str[i] == '=' ? 0 & i++ : decoding_table[str[i++]];
    sxtet_d = str[i] == '=' ? 0 & i++ : decoding_table[str[i++]];
    triple = (sxtet_a << 3 * 6)
    + (sxtet_b << 2 * 6)
    + (sxtet_c << 1 * 6)
    + (sxtet_d << 0 * 6);
    if (j < *length_ptr) decoded_data[j++] = (triple >> 2 * 8) & 0xFF;
    if (j < *length_ptr) decoded_data[j++] = (triple >> 1 * 8) & 0xFF;
    if (j < *length_ptr) decoded_data[j++] = (triple >> 0 * 8) & 0xFF;
  }
  __base64_cleanup__();
  return decoded_data;
}