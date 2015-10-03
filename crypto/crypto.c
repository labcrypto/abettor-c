#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <openssl/des.h>
#include <openssl/sha.h>
#include <openssl/bn.h>
#include <openssl/rsa.h>

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
  DES_cblock iv = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  DES_key_schedule ks;
  NAEEM_uint32 cipher_length;
  NAEEM_data internal_cipher;
  DES_cblock cb;
  for (i = 0; i < DES_KEY_LENGTH; i++) {
    cb[i] = key[i];
  }
  DES_set_odd_parity(&cb);
  if (DES_set_key_checked(&cb, &ks)) {
      return NAEEM_RESULT_INVALID_DES_KEY;
   }
   cipher_length = (data_length / DES_KEY_LENGTH + ((data_length % DES_KEY_LENGTH) == 0 ? 0 : 1)) * 8;
   if (cipher_length_ptr) {
     *cipher_length_ptr = cipher_length;
   }
   internal_cipher = (NAEEM_data)malloc(cipher_length * sizeof(NAEEM_byte));
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
  DES_cblock iv = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  DES_key_schedule ks;
  NAEEM_data internal_data;
  NAEEM_uint32 data_length;
  for (i = 0; i < DES_KEY_LENGTH; i++) {
    cb[i] = key[i];
  }
  DES_set_odd_parity(&cb);
  if (DES_set_key_checked(&cb, &ks)) {
      return NAEEM_RESULT_INVALID_DES_KEY;
   }
   data_length = cipher_length;
   if (data_length_ptr) {
     *data_length_ptr = data_length;
   }
   internal_data = (NAEEM_data)malloc(data_length * sizeof(NAEEM_byte));
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
  DES_cblock cb2;
  DES_cblock cb3;
  DES_cblock iv = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  DES_key_schedule ks1, ks2, ks3;
  NAEEM_uint32 cipher_length;
  NAEEM_data internal_cipher;
  for (i = 0; i < DES_KEY_LENGTH; i++) {
    cb1[i] = first_key[i];
  }
  for (i = 0; i < DES_KEY_LENGTH; i++) {
    cb2[i] = second_key[i];
  }
  for (i = 0; i < DES_KEY_LENGTH; i++) {
    cb3[i] = thrid_key[i];
  }
  DES_set_odd_parity(&cb1);
  DES_set_odd_parity(&cb2);
  DES_set_odd_parity(&cb3);
  if (DES_set_key_checked(&cb1, &ks1) ||
      DES_set_key_checked(&cb2, &ks2) ||
      DES_set_key_checked(&cb3, &ks3)) {
      return NAEEM_RESULT_INVALID_DES_KEY;
   }
   cipher_length = (data_length / DES_KEY_LENGTH + ((data_length % DES_KEY_LENGTH) == 0 ? 0 : 1)) * 8;
   if (cipher_length_ptr) {
     *cipher_length_ptr = cipher_length;
   }
   internal_cipher = (NAEEM_data)malloc(cipher_length * sizeof(NAEEM_byte));
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
  DES_cblock cb2;
  DES_cblock cb3;
  DES_cblock iv = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  DES_key_schedule ks1,ks2,ks3;
  NAEEM_uint32 data_length;
  NAEEM_data internal_data;
  for (i = 0; i < DES_KEY_LENGTH; i++) {
    cb1[i] = first_key[i];
  }
  for (i = 0; i < DES_KEY_LENGTH; i++) {
    cb2[i] = second_key[i];
  }
  for (i = 0; i < DES_KEY_LENGTH; i++) {
    cb3[i] = thrid_key[i];
  }
  DES_set_odd_parity(&cb1);
  DES_set_odd_parity(&cb2);
  DES_set_odd_parity(&cb3);
  if (DES_set_key_checked(&cb1, &ks1) ||
      DES_set_key_checked(&cb2, &ks2) ||
      DES_set_key_checked(&cb3, &ks3)) {
      return NAEEM_RESULT_INVALID_DES_KEY;
   }
   data_length = cipher_length;
   if (data_length_ptr) {
     *data_length_ptr = data_length;
   }
   internal_data = (NAEEM_data)malloc(data_length * sizeof(NAEEM_byte));
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
  // TODO (kamran) Use NAEEM_util_pad function.
  NAEEM_uint32 i = 0, j = 0;
  NAEEM_byte check_block[8];
  NAEEM_byte decipher[8];
  NAEEM_test__assert((message_length % 8) == 0, "Message length is not a product of 8 bytes.");
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
	NAEEM_byte cipher[8];
    NAEEM_util__copy_array(block, message, i, 8);
    NAEEM_util__xor(check_block, 8, block);
    NAEEM_crypto__DES_cbc_encrypt(check_block, 8, cipher, NULL, key1);
    for (j = 0; j < 8; j++) {
      check_block[j] = cipher[j];
    }
    i += 8;
  }
  if (!padded) {
    NAEEM_byte padding[8];
	NAEEM_byte cipher[8];
    padding[0] = 0x80;
    padding[1] = padding[2] = padding[3] = padding[4] = padding[5] = padding[6] = padding[7] = 0x00;
    NAEEM_util__xor(check_block, 8, padding);
    NAEEM_crypto__DES_cbc_encrypt(check_block, 8, cipher, NULL, key1);  
    for (j = 0; j < 8; j++) {
      check_block[j] = cipher[j];
    }
  }
  NAEEM_crypto__DES_cbc_decrypt(check_block, 8, decipher, NULL, key2);
  for (j = 0; j < 8; j++) {
    check_block[j] = decipher[j];
  }
  // NAEEM_util_print_array("DECIPHER    ", check_block, 8); 
  NAEEM_crypto__DES_cbc_encrypt(check_block, 8, mac, NULL, key1);
  // NAEEM_util_print_array("CIPHER    ", check_block, 8);
  return NAEEM_RESULT_SUCCESS;
}

NAEEM_void
NAEEM_crypto__generate_RSA (NAEEM_crypto__RSA_key_pair_ptr RSA_key_pair_ptr) {
  RSA *keypair = RSA_generate_key(1024, 257, NULL, NULL);
  NAEEM_byte buffer[512];
  NAEEM_uint32 copied = 0;

  copied = BN_bn2bin(keypair->n, buffer);
  RSA_key_pair_ptr->N_length = copied;
  RSA_key_pair_ptr->N_data = malloc(RSA_key_pair_ptr->N_length * sizeof(NAEEM_byte));
  NAEEM_util__copy_array(RSA_key_pair_ptr->N_data, buffer, 0, RSA_key_pair_ptr->N_length);
  // NAEEM_util__print_array("N           ", RSA_key_pair_ptr->N_data, RSA_key_pair_ptr->N_length);

  copied = BN_bn2bin(keypair->e, buffer);
  RSA_key_pair_ptr->E_length = copied;
  RSA_key_pair_ptr->E_data = malloc(RSA_key_pair_ptr->E_length * sizeof(NAEEM_byte));
  NAEEM_util__copy_array(RSA_key_pair_ptr->E_data, buffer, 0, RSA_key_pair_ptr->E_length);
  // NAEEM_util__print_array("E           ", RSA_key_pair_ptr->E_data, RSA_key_pair_ptr->E_length);

  copied = BN_bn2bin(keypair->d, buffer);
  RSA_key_pair_ptr->D_length = copied;
  RSA_key_pair_ptr->D_data = malloc(RSA_key_pair_ptr->D_length * sizeof(NAEEM_byte));
  NAEEM_util__copy_array(RSA_key_pair_ptr->D_data, buffer, 0, RSA_key_pair_ptr->D_length);
  // NAEEM_util__print_array("D           ", RSA_key_pair_ptr->D_data, RSA_key_pair_ptr->D_length);

  copied = BN_bn2bin(keypair->p, buffer);
  RSA_key_pair_ptr->P_length = copied;
  RSA_key_pair_ptr->P_data = malloc(RSA_key_pair_ptr->P_length * sizeof(NAEEM_byte));
  NAEEM_util__copy_array(RSA_key_pair_ptr->P_data, buffer, 0, RSA_key_pair_ptr->P_length);
  // NAEEM_util__print_array("P           ", RSA_key_pair_ptr->P_data, RSA_key_pair_ptr->P_length);

  copied = BN_bn2bin(keypair->q, buffer);
  RSA_key_pair_ptr->Q_length = copied;
  RSA_key_pair_ptr->Q_data = malloc(RSA_key_pair_ptr->Q_length * sizeof(NAEEM_byte));
  NAEEM_util__copy_array(RSA_key_pair_ptr->Q_data, buffer, 0, RSA_key_pair_ptr->Q_length);
  // NAEEM_util__print_array("Q           ", RSA_key_pair_ptr->Q_data, RSA_key_pair_ptr->Q_length);

  copied = BN_bn2bin(keypair->dmp1, buffer);
  RSA_key_pair_ptr->EXP1_length = copied;
  RSA_key_pair_ptr->EXP1_data = malloc(RSA_key_pair_ptr->EXP1_length * sizeof(NAEEM_byte));
  NAEEM_util__copy_array(RSA_key_pair_ptr->EXP1_data, buffer, 0, RSA_key_pair_ptr->EXP1_length);
  // NAEEM_util__print_array("EXP1        ", RSA_key_pair_ptr->EXP1_data, RSA_key_pair_ptr->EXP1_length);

  copied = BN_bn2bin(keypair->dmq1, buffer);
  RSA_key_pair_ptr->EXP2_length = copied;
  RSA_key_pair_ptr->EXP2_data = malloc(RSA_key_pair_ptr->EXP2_length * sizeof(NAEEM_byte));
  NAEEM_util__copy_array(RSA_key_pair_ptr->EXP2_data, buffer, 0, RSA_key_pair_ptr->EXP2_length);
  // NAEEM_util__print_array("EXP2        ", RSA_key_pair_ptr->EXP2_data, RSA_key_pair_ptr->EXP2_length);

  copied = BN_bn2bin(keypair->iqmp, buffer);
  RSA_key_pair_ptr->C_length = copied;
  RSA_key_pair_ptr->C_data = malloc(RSA_key_pair_ptr->C_length * sizeof(NAEEM_byte));
  NAEEM_util__copy_array(RSA_key_pair_ptr->C_data, buffer, 0, RSA_key_pair_ptr->C_length);
  // NAEEM_util__print_array("C           ", RSA_key_pair_ptr->C_data, RSA_key_pair_ptr->C_length);

  NAEEM_crypto__calculate_public_key(RSA_key_pair_ptr);
}

NAEEM_void
NAEEM_crypto__calculate_public_key(NAEEM_crypto__RSA_key_pair_ptr RSA_key_pair_ptr) {
  NAEEM_byte n_and_e[500];
  NAEEM_counter c = 0, i = 0;
  NAEEM_length n_and_e_length;
  NAEEM_length n_and_e_wrapper_data_length;
  NAEEM_length n_and_e_wrapper2_data_length;
  NAEEM_length n_and_e_wrapper3_data_length;
  NAEEM_length public_key_data_length;
  NAEEM_byte n_and_e_wrapper_data[500];
  NAEEM_byte n_and_e_wrapper2_data[500];
  NAEEM_byte n_and_e_wrapper3_data[500];
  NAEEM_byte public_key_data[500];
  n_and_e[c++] = 0x02;
  if ((RSA_key_pair_ptr->N_length + 1) > 255) {
    n_and_e[c++] = 0x82;
    n_and_e[c++] = (RSA_key_pair_ptr->N_length + 1) / 256;
    n_and_e[c++] = (RSA_key_pair_ptr->N_length + 1) % 256;
  } else {
    n_and_e[c++] = 0x81;
    n_and_e[c++] = (RSA_key_pair_ptr->N_length + 1);
  }
  n_and_e[c++] = 0x00;
  for (i = 0; i < RSA_key_pair_ptr->N_length; i++) {
    n_and_e[c++] = RSA_key_pair_ptr->N_data[i];
  }
  n_and_e[c++] = 0x02;
  n_and_e[c++] = RSA_key_pair_ptr->E_length;
  for (i = 0; i < RSA_key_pair_ptr->E_length; i++) {
    n_and_e[c++] = RSA_key_pair_ptr->E_data[i];
  }
  n_and_e_length = c;
  //--------------------------------
  c = 0;
  n_and_e_wrapper_data[c++] = 0x00;
  n_and_e_wrapper_data[c++] = 0x30;
  if (n_and_e_length > 255) {
    n_and_e_wrapper_data[c++] = 0x82;
    n_and_e_wrapper_data[c++] = n_and_e_length / 256;
    n_and_e_wrapper_data[c++] = n_and_e_length % 256;
  } else {
    n_and_e_wrapper_data[c++] = 0x81;
    n_and_e_wrapper_data[c++] = n_and_e_length;
  }
  for (i = 0; i < n_and_e_length; i++) {
    n_and_e_wrapper_data[c++] = n_and_e[i];
  }
  n_and_e_wrapper_data_length = c;
  //--------------------------------
  c = 0;
  n_and_e_wrapper2_data[c++] = 0x03;
  if (n_and_e_wrapper_data_length > 255) {
    n_and_e_wrapper2_data[c++] = 0x82;
    n_and_e_wrapper2_data[c++] = n_and_e_wrapper_data_length / 256;
    n_and_e_wrapper2_data[c++] = n_and_e_wrapper_data_length % 256;
  } else {
    n_and_e_wrapper2_data[c++] = 0x81;
    n_and_e_wrapper2_data[c++] = n_and_e_wrapper_data_length;
  }
  for (i = 0; i < n_and_e_wrapper_data_length; i++) {
    n_and_e_wrapper2_data[c++] = n_and_e_wrapper_data[i];
  }
  n_and_e_wrapper2_data_length = c;
  //--------------------------------
  c = 0;
  n_and_e_wrapper3_data[c++] = 0x30;
  n_and_e_wrapper3_data[c++] = 0x0d;
  n_and_e_wrapper3_data[c++] = 0x06;
  n_and_e_wrapper3_data[c++] = 0x09;
  n_and_e_wrapper3_data[c++] = 0x2a;
  n_and_e_wrapper3_data[c++] = 0x86;
  n_and_e_wrapper3_data[c++] = 0x48;
  n_and_e_wrapper3_data[c++] = 0x86;
  n_and_e_wrapper3_data[c++] = 0xf7;
  n_and_e_wrapper3_data[c++] = 0x0d;
  n_and_e_wrapper3_data[c++] = 0x01;
  n_and_e_wrapper3_data[c++] = 0x01;
  n_and_e_wrapper3_data[c++] = 0x01;
  n_and_e_wrapper3_data[c++] = 0x05;
  n_and_e_wrapper3_data[c++] = 0x00;
  for (i = 0; i < n_and_e_wrapper2_data_length; i++) {
    n_and_e_wrapper3_data[c++] = n_and_e_wrapper2_data[i];
  }
  n_and_e_wrapper3_data_length = c;
  //--------------------------------
  c = 0;  
  public_key_data[c++] = 0x30;
  if (n_and_e_wrapper3_data_length > 255) {
    public_key_data[c++] = 0x82;
    public_key_data[c++] = n_and_e_wrapper3_data_length / 256;
    public_key_data[c++] = n_and_e_wrapper3_data_length % 256;
  } else {
    public_key_data[c++] = 0x81;
    public_key_data[c++] = n_and_e_wrapper3_data_length;
  }
  for (i = 0; i < n_and_e_wrapper3_data_length; i++) {
    public_key_data[c++] = n_and_e_wrapper3_data[i];
  }
  public_key_data_length = c;
  //--------------------------------
  RSA_key_pair_ptr->public_key_length = public_key_data_length;
  RSA_key_pair_ptr->public_key = (NAEEM_data)malloc(RSA_key_pair_ptr->public_key_length * sizeof(NAEEM_byte));
  NAEEM_util__copy_array(RSA_key_pair_ptr->public_key, public_key_data, 0, RSA_key_pair_ptr->public_key_length);
}
