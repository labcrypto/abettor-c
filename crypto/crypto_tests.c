/*  The MIT License (MIT)
 *
 *  Copyright (c) 2015 Noavaran Tejarat Gostar NAEEM Co.
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

#include <naeem/types.h>
#include <naeem/crypto.h>
#include <naeem/test.h>
#include <naeem/util.h>
#include <naeem/crypto_tests.h>

NAEEM_void
NAEEM_test_SHA1() {
  /* SHA1 value for the message is : 0x93 0x62 0x5d 0xcb 0x47 0x9d 0x1c 0x4e 0x30 0x0d 
                                     0xdb 0xcc 0x58 0x09 0x09 0xd4 0x58 0x47 0xc3 0xd9 */
  NAEEM_string message = "This is a message from NAEEM!";
  NAEEM_byte expected_hash_value[20] = {0x93, 0x62, 0x5d, 0xcb, 0x47, 0x9d, 0x1c, 0x4e, 0x30, 0x0d, 
  	                                    0xdb, 0xcc, 0x58, 0x09, 0x09, 0xd4, 0x58, 0x47, 0xc3, 0xd9};
  NAEEM_data hash = (NAEEM_data)malloc(20 * sizeof(NAEEM_char));
  NAEEM_result result = NAEEM_crypto__SHA1(message, strlen((const char*)message), hash);
  if (result != NAEEM_RESULT_SUCCESS) {
    printf("> FAILURE: SHA1 is not working!\n");
    exit(1);
  }
  NAEEM_test__assert_equal_byte_arrays(expected_hash_value, 20, hash, 20, "SHA1 value is incorrect.");
  free(hash);
  printf("SUCCESS: SHA1 test is passed.\n");
}


NAEEM_void
NAEEM_test_SHA256() {
  /* SHA1 value for the message is : 0x3a 0x71 0x05 0x4e 0x51 0xf0 0xbc 0xf3 0x51 0x79 0x2d 0x77 0x7e 0xe4 0x35 0xc9
                                     0xba 0x5e 0x18 0x43 0xfc 0x19 0x84 0xad 0x93 0x74 0x22 0x9c 0x7d 0x2e 0xac 0xb1
                                      */
  NAEEM_string message = "This is a message from NAEEM!";
   NAEEM_byte expected_hash_value[32] = {0x3a, 0x71, 0x05, 0x4e, 0x51, 0xf0, 0xbc, 0xf3, 0x51, 0x79, 0x2d, 0x77, 0x7e, 0xe4, 0x35, 0xc9, 
  	                                    0xba, 0x5e, 0x18, 0x43, 0xfc, 0x19, 0x84, 0xad, 0x93, 0x74, 0x22, 0x9c, 0x7d, 0x2e, 0xac, 0xb1};
  NAEEM_data hash = (NAEEM_data)malloc(32 * sizeof(NAEEM_char));
  NAEEM_result result = NAEEM_crypto__SHA256(message, strlen((const char*)message), hash);
  if (result != NAEEM_RESULT_SUCCESS) {
    printf("> FAILURE: SHA256 is not working!\n");
    exit(1);
  }
  NAEEM_test__assert_equal_byte_arrays(expected_hash_value, 32, hash, 32, "SHA256 value is incorrect.");
  free(hash);
  printf("SUCCESS: SHA256 test is passed.\n");
}

NAEEM_void
NAEEM_test_DES() {
  NAEEM_uint32 cipher_length = 0;
  NAEEM_data cipher;
  NAEEM_DES_key key = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07};
  NAEEM_byte data[9] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99};
  NAEEM_result result = 0;
  NAEEM_data plain;
  NAEEM_uint32 plain_length = 0;
  NAEEM_util__print_array("DES DATA", data, 9);
  cipher = (NAEEM_data)malloc(16 * sizeof(NAEEM_byte));
  result = NAEEM_crypto__DES_cbc_encrypt(data, 9, cipher, &cipher_length, key);
  if (result != NAEEM_RESULT_SUCCESS) {
    printf("> FAILURE: DES ecnryption is not working!\n");
    exit(1);
  }
  printf("DES cipher length: %d\n", cipher_length);
  NAEEM_test__assert_equal_uint32(16, cipher_length, "DES cipher length is wrong.");
  NAEEM_util__print_array("DES CIPHER", cipher, cipher_length);
  plain = (NAEEM_data)malloc(16 * sizeof(NAEEM_byte));
  result = NAEEM_crypto__DES_cbc_decrypt(cipher, cipher_length, plain, &plain_length, key);
  if (result != NAEEM_RESULT_SUCCESS) {
    printf("> FAILURE: DES decryption is not working!\n");
    exit(1);
  }
  printf("Plain length: %d\n", plain_length);
  NAEEM_test__assert_equal_uint32(16, plain_length, "DES plain length is wrong.");
  NAEEM_util__print_array("DES PLAIN", plain, plain_length);
  NAEEM_test__assert_equal_byte_arrays(data, 9, plain, 9, "DES is working.");
  free(cipher);
  free(plain);
  printf("SUCCESS: DES test is passed.\n");
}

NAEEM_void
NAEEM_test_3DES() {
  NAEEM_byte data[9] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99};
  NAEEM_uint32 cipher_length = 0;
  NAEEM_data cipher;
  NAEEM_DES_key key1 = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07};
  NAEEM_DES_key key2 = {0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17};
  NAEEM_DES_key key3 = {0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27};
  NAEEM_result result = 0;
  NAEEM_data plain;
  NAEEM_uint32 plain_length = 0;
  NAEEM_util__print_array("3DES DATA", data, 9);
  cipher = (NAEEM_data)malloc(16 * sizeof(NAEEM_byte));
  result = NAEEM_crypto__3DES_cbc_encrypt(data, 9, cipher, &cipher_length, key1, key2, key3);
  if (result != NAEEM_RESULT_SUCCESS) {
    printf("> FAILURE: 3DES ecnryption is not working!\n");
    exit(1);
  }
  printf("3DES cipher length: %d\n", cipher_length);
  NAEEM_test__assert_equal_uint32(16, cipher_length, "3DES cipher length is wrong.");
  NAEEM_util__print_array("3DES CIPHER", cipher, cipher_length);
  plain = (NAEEM_data)malloc(16 * sizeof(NAEEM_byte));
  result = NAEEM_crypto__3DES_cbc_decrypt(cipher, cipher_length, plain, &plain_length, key1, key2, key3);
  if (result != NAEEM_RESULT_SUCCESS) {
    printf("> FAILURE: 3DES decryption is not working!\n");
    exit(1);
  }
  printf("Plain length: %d\n", plain_length);
  NAEEM_test__assert_equal_uint32(16, plain_length, "3DES plain length is wrong.");
  NAEEM_util__print_array("3DES PLAIN", plain, plain_length);
  NAEEM_test__assert_equal_byte_arrays(data, 9, plain, 9, "3DES is working.");
  free(cipher);
  free(plain);
  printf("SUCCESS: 3DES test is passed.\n");
}

