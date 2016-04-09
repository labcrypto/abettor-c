#include <stdint.h>
#include <stdlib.h>

#include <naeem/base64.h>


static NAEEM_byte encoding_table[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                                'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                                'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                                'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                                'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                                'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                                'w', 'x', 'y', 'z', '0', '1', '2', '3',
                                '4', '5', '6', '7', '8', '9', '+', '/'};
static NAEEM_byte *decoding_table = NULL;
static NAEEM_uint32 mod_table[] = {0, 2, 1};

void 
__base64_setup_decoding_table__() {
  NAEEM_counter i;
  decoding_table = malloc(256);
  for (i = 0; i < 64; i++) {
    decoding_table[(NAEEM_byte) encoding_table[i]] = i;
  }
}


void 
__base64_cleanup__() {
  free(decoding_table);
}


NAEEM_data
NAEEM_crypto_base64__encode (
  NAEEM_data data,
  NAEEM_length data_length,
  NAEEM_length_ptr length_ptr
) {
  NAEEM_counter i, j;
  NAEEM_data encoded_data;
  NAEEM_uint32 octet_a;
  NAEEM_uint32 octet_b;
  NAEEM_uint32 octet_c;
  NAEEM_uint32 triple;
  __base64_setup_decoding_table__();
  *length_ptr = 4 * ((data_length + 2) / 3);
  encoded_data = malloc(*length_ptr);
  if (encoded_data == NULL) {
    return NULL;
  }
  for (i = 0, j = 0; i < data_length;) {
    octet_a = i < data_length ? (NAEEM_byte)data[i++] : 0;
    octet_b = i < data_length ? (NAEEM_byte)data[i++] : 0;
    octet_c = i < data_length ? (NAEEM_byte)data[i++] : 0;
    triple = (octet_a << 0x10) + (octet_b << 0x08) + octet_c;
    encoded_data[j++] = encoding_table[(triple >> 3 * 6) & 0x3F];
    encoded_data[j++] = encoding_table[(triple >> 2 * 6) & 0x3F];
    encoded_data[j++] = encoding_table[(triple >> 1 * 6) & 0x3F];
    encoded_data[j++] = encoding_table[(triple >> 0 * 6) & 0x3F];
  }
  for (i = 0; i < mod_table[data_length % 3]; i++) {
    encoded_data[*length_ptr - 1 - i] = '=';
  }
  __base64_cleanup__();
  return encoded_data;
}

  
NAEEM_data
NAEEM_crypto_base64__decode (
  NAEEM_data data,
  NAEEM_length data_length,
  NAEEM_length_ptr length_ptr
) {
  NAEEM_data decoded_data;
  NAEEM_counter i, j;
  NAEEM_uint32 sxtet_a;
  NAEEM_uint32 sxtet_b;
  NAEEM_uint32 sxtet_c;
  NAEEM_uint32 sxtet_d;
  NAEEM_uint32 triple;
  __base64_setup_decoding_table__();
  if (data_length % 4 != 0) {
    return NULL;
  }
  *length_ptr = data_length / 4 * 3;
  if (data[data_length - 1] == '=') {
    (*length_ptr)--;
  }
  if (data[data_length - 2] == '=') {
    (*length_ptr)--;
  }
  decoded_data = malloc(*length_ptr);
  if (decoded_data == NULL) {
    return NULL;
  }
  for (i = 0, j = 0; i < data_length;) {
    sxtet_a = data[i] == '=' ? 0 & i++ : decoding_table[data[i++]];
    sxtet_b = data[i] == '=' ? 0 & i++ : decoding_table[data[i++]];
    sxtet_c = data[i] == '=' ? 0 & i++ : decoding_table[data[i++]];
    sxtet_d = data[i] == '=' ? 0 & i++ : decoding_table[data[i++]];
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


