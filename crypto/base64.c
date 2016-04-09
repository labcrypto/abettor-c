#include <stdint.h>
#include <stdlib.h>


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
  decoding_table = malloc(256);
  for (NAEEM_counter i = 0; i < 64; i++) {
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
  return NULL;
}

  
NAEEM_data
NAEEM_crypto_base64__decode (
  NAEEM_data data,
  NAEEM_length data_length,
  NAEEM_length_ptr length_ptr
) {
  return NULL;
}


