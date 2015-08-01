#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <openssl/des.h>
#include <openssl/sha.h>

#include <naeem/crypto.h>
#include <naeem/util.h>
#include <naeem/test.h>
#include <naeem/error.h>


NAEEM_result
NAEEM_crypto__SHA1 (NAEEM_data data,
                    NAEEM_uint32 data_length,
                    NAEEM_data hash) {
  SHA_CTX ctx;
  SHA1_Init(&ctx);
  SHA1_Update(&ctx, data, data_length);
  SHA1_Final(hash, &ctx);
  return NAEEM_RESULT_SUCCESS;
}


NAEEM_result
NAEEM_crypto__SHA256 (NAEEM_data data,
                      NAEEM_uint32 data_length,
                      NAEEM_data hash) {
  SHA256_CTX ctx;
  SHA256_Init(&ctx);
  SHA256_Update(&ctx, data, data_length);
  SHA256_Final(hash, &ctx);
  return NAEEM_RESULT_SUCCESS;
}


NAEEM_result
NAEEM_crypto__DES_cbc_encrypt (NAEEM_data data,
                               NAEEM_uint32 data_length,
                               NAEEM_data cipher,
                               NAEEM_uint32_ptr cipher_length_ptr,
                               NAEEM_DES_key key) {
  NAEEM_uint32 i = 0;
  DES_cblock cb;
  for (i = 0; i < DES_KEY_LENGTH; i++) {
    cb[i] = key[i];
  }
  DES_set_odd_parity(&cb);

  DES_cblock iv = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  
  DES_key_schedule ks;
  if (DES_set_key_checked(&cb, &ks)) {
      return NAEEM_RESULT_INVALID_DES_KEY;
   }

   NAEEM_uint32 cipher_length = (data_length / DES_KEY_LENGTH + ((data_length % DES_KEY_LENGTH) == 0 ? 0 : 1)) * 8;
   if (cipher_length_ptr) {
     *cipher_length_ptr = cipher_length;
   }
   NAEEM_data internal_cipher = (NAEEM_data)malloc(cipher_length * sizeof(NAEEM_byte));
   memset(internal_cipher, 0x00, cipher_length * sizeof(NAEEM_byte));
   DES_cbc_encrypt(data, internal_cipher, data_length, &ks, &iv, DES_ENCRYPT);

  for (i = 0; i < cipher_length; i++) {
    cipher[i] = internal_cipher[i];
  } 
  free(internal_cipher);
  return NAEEM_RESULT_SUCCESS;
}


NAEEM_result
NAEEM_crypto__DES_cbc_decrypt (NAEEM_data cipher,
                               NAEEM_uint32 cipher_length,
                               NAEEM_data data,
                               NAEEM_uint32_ptr data_length_ptr,
                               NAEEM_DES_key key) {
  NAEEM_uint32 i = 0;
  DES_cblock cb;
  for (i = 0; i < DES_KEY_LENGTH; i++) {
    cb[i] = key[i];
  }
  DES_set_odd_parity(&cb);

  DES_cblock iv = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  
  DES_key_schedule ks;
  if (DES_set_key_checked(&cb, &ks)) {
      return NAEEM_RESULT_INVALID_DES_KEY;
   }

   NAEEM_uint32 data_length = cipher_length;
   if (data_length_ptr) {
     *data_length_ptr = data_length;
   }
   NAEEM_data internal_data = (NAEEM_data)malloc(data_length * sizeof(NAEEM_byte));
   memset(internal_data, 0x00, data_length * sizeof(NAEEM_byte));
   DES_cbc_encrypt(cipher, internal_data, cipher_length, &ks, &iv, DES_DECRYPT);

  for (i = 0; i < data_length; i++) {
    data[i] = internal_data[i];
  } 
  free(internal_data);
  return NAEEM_RESULT_SUCCESS;
}


NAEEM_result
NAEEM_crypto__3DES_cbc_encrypt (NAEEM_data data,
                                NAEEM_uint32 data_length,
                                NAEEM_data cipher,
                                NAEEM_uint32_ptr cipher_length_ptr,
                                NAEEM_DES_key first_key,
                                NAEEM_DES_key second_key,
                                NAEEM_DES_key thrid_key) {
  NAEEM_uint32 i = 0;
  DES_cblock cb1;
  for (i = 0; i < DES_KEY_LENGTH; i++) {
    cb1[i] = first_key[i];
  }
  DES_cblock cb2;
  for (i = 0; i < DES_KEY_LENGTH; i++) {
    cb2[i] = second_key[i];
  }
  DES_cblock cb3;
  for (i = 0; i < DES_KEY_LENGTH; i++) {
    cb3[i] = thrid_key[i];
  }
  
  DES_set_odd_parity(&cb1);
  DES_set_odd_parity(&cb2);
  DES_set_odd_parity(&cb3);

  DES_cblock iv = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  
  DES_key_schedule ks1, ks2, ks3;
  if (DES_set_key_checked(&cb1, &ks1) ||
      DES_set_key_checked(&cb2, &ks2) ||
      DES_set_key_checked(&cb3, &ks3)) {
      return NAEEM_RESULT_INVALID_DES_KEY;
   }

   NAEEM_uint32 cipher_length = (data_length / DES_KEY_LENGTH + ((data_length % DES_KEY_LENGTH) == 0 ? 0 : 1)) * 8;
   if (cipher_length_ptr) {
     *cipher_length_ptr = cipher_length;
   }
   NAEEM_data internal_cipher = (NAEEM_data)malloc(cipher_length * sizeof(NAEEM_byte));
   memset(internal_cipher, 0x00, cipher_length * sizeof(NAEEM_byte));
   DES_ede3_cbc_encrypt(data, internal_cipher, data_length, &ks1, &ks2, &ks3, &iv, DES_ENCRYPT);
 
  for (i = 0; i < cipher_length; i++) {
    cipher[i] = internal_cipher[i];
  } 
  free(internal_cipher);
  return NAEEM_RESULT_SUCCESS;
}


NAEEM_result
NAEEM_crypto__3DES_cbc_decrypt (NAEEM_data cipher,
                                NAEEM_uint32 cipher_length,
                                NAEEM_data data,
                                NAEEM_uint32_ptr data_length_ptr,
                                NAEEM_DES_key first_key,
                                NAEEM_DES_key second_key,
                                NAEEM_DES_key thrid_key) {
  NAEEM_uint32 i = 0;
  DES_cblock cb1;
  for (i = 0; i < DES_KEY_LENGTH; i++) {
    cb1[i] = first_key[i];
  }
  DES_cblock cb2;
  for (i = 0; i < DES_KEY_LENGTH; i++) {
    cb2[i] = second_key[i];
  }
  DES_cblock cb3;
  for (i = 0; i < DES_KEY_LENGTH; i++) {
    cb3[i] = thrid_key[i];
  }

  DES_set_odd_parity(&cb1);
  DES_set_odd_parity(&cb2);
  DES_set_odd_parity(&cb3);
  
  DES_cblock iv = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  
  DES_key_schedule ks1,ks2,ks3;
  if (DES_set_key_checked(&cb1, &ks1) ||
      DES_set_key_checked(&cb2, &ks2) ||
      DES_set_key_checked(&cb3, &ks3)) {
      return NAEEM_RESULT_INVALID_DES_KEY;
   }

   NAEEM_uint32 data_length = cipher_length;
   if (data_length_ptr) {
     *data_length_ptr = data_length;
   }
   NAEEM_data internal_data = (NAEEM_data)malloc(data_length * sizeof(NAEEM_byte));
   memset(internal_data, 0x00, data_length);
   DES_ede3_cbc_encrypt(cipher, internal_data, cipher_length, &ks1, &ks2, &ks3, &iv, DES_DECRYPT);
 
  for (i = 0; i < data_length; i++) {
    data[i] = internal_data[i];
  } 
  free(internal_data);
  return NAEEM_RESULT_SUCCESS;
}


NAEEM_result
NAEEM_crypto__MAC_v3 (NAEEM_data message,
                      NAEEM_uint32 message_length,
                      NAEEM_data mac,
                      NAEEM_data initial_check_block,
                      NAEEM_bool padded,
                      NAEEM_DES_key key1,
                      NAEEM_DES_key key2) {
  NAEEM_test__assert((message_length % 8) == 0, "Message length is not a product of 8 bytes.");
  // TODO (kamran) Use NAEEM_util_pad function.
  NAEEM_uint32 i = 0, j = 0;
  NAEEM_byte check_block[8];
  if (initial_check_block) {
    for (i = 0; i < 8; i++) {
      check_block[i] = initial_check_block[i];
    }
  } else {
    for (i = 0; i < 8; i++) {
      check_block[i] = 0x00;
    }
  }
  i = 0;
  while (i < message_length) {
    NAEEM_byte block[8];
    NAEEM_util__copy_array(block, message, i, 8);
    NAEEM_util__xor(check_block, 8, block);
    // NAEEM_util_print_array("CBLOCK    ", check_block, 8); 
    NAEEM_byte cipher[8];
    NAEEM_crypto__DES_cbc_encrypt(check_block, 8, cipher, NULL, key1);
    for (j = 0; j < 8; j++) {
      check_block[j] = cipher[j];
    }
    i += 8;
  }
  if (!padded) {
    NAEEM_byte padding[8];
    padding[0] = 0x80;
    padding[1] = padding[2] = padding[3] = padding[4] = padding[5] = padding[6] = padding[7] = 0x00;
    NAEEM_util__xor(check_block, 8, padding);
    NAEEM_byte cipher[8];
    NAEEM_crypto__DES_cbc_encrypt(check_block, 8, cipher, NULL, key1);  
    for (j = 0; j < 8; j++) {
      check_block[j] = cipher[j];
    }
  }
  NAEEM_byte decipher[8];
  NAEEM_crypto__DES_cbc_decrypt(check_block, 8, decipher, NULL, key2);
  for (j = 0; j < 8; j++) {
    check_block[j] = decipher[j];
  }
  // NAEEM_util_print_array("DECIPHER    ", check_block, 8); 
  NAEEM_crypto__DES_cbc_encrypt(check_block, 8, mac, NULL, key1);
  // NAEEM_util_print_array("CIPHER    ", check_block, 8);
  return NAEEM_RESULT_SUCCESS;
}