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
 
#ifndef _ORG_LABCRYPTO_ABETTOR__C__CRYPTO_H_
#define _ORG_LABCRYPTO_ABETTOR__C__CRYPTO_H_

#include <stdlib.h>
#include <stdio.h>

#include <org/labcrypto/abettor/types.h>


#ifdef __cplusplus
extern "C" {
#endif

#define DES_KEY_LENGTH 8


typedef ORG_LABCRYPTO_ABETTOR_byte ORG_LABCRYPTO_ABETTOR_DES_key[DES_KEY_LENGTH];

typedef struct {
  ORG_LABCRYPTO_ABETTOR_data        public_key;
  ORG_LABCRYPTO_ABETTOR_uint32      public_key_length;
  ORG_LABCRYPTO_ABETTOR_data        private_key;
  ORG_LABCRYPTO_ABETTOR_uint32      private_key_length;
  ORG_LABCRYPTO_ABETTOR_data        N_data;
  ORG_LABCRYPTO_ABETTOR_uint32      N_length;
  ORG_LABCRYPTO_ABETTOR_data        E_data;
  ORG_LABCRYPTO_ABETTOR_uint32      E_length;
  ORG_LABCRYPTO_ABETTOR_data        D_data;
  ORG_LABCRYPTO_ABETTOR_uint32      D_length;
  ORG_LABCRYPTO_ABETTOR_data        P_data;
  ORG_LABCRYPTO_ABETTOR_uint32      P_length;
  ORG_LABCRYPTO_ABETTOR_data        Q_data;
  ORG_LABCRYPTO_ABETTOR_uint32      Q_length;
  ORG_LABCRYPTO_ABETTOR_data        EXP1_data;
  ORG_LABCRYPTO_ABETTOR_uint32      EXP1_length;
  ORG_LABCRYPTO_ABETTOR_data        EXP2_data;
  ORG_LABCRYPTO_ABETTOR_uint32      EXP2_length;
  ORG_LABCRYPTO_ABETTOR_data        C_data;
  ORG_LABCRYPTO_ABETTOR_uint32      C_length;
} ORG_LABCRYPTO_ABETTOR__crypto__RSA_key_pair;
typedef ORG_LABCRYPTO_ABETTOR__crypto__RSA_key_pair PTR ORG_LABCRYPTO_ABETTOR__crypto__RSA_key_pair_ptr;


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__crypto__SHA1 (
  ORG_LABCRYPTO_ABETTOR_data      /* Data */,
  ORG_LABCRYPTO_ABETTOR_uint32    /* Data length */,
  ORG_LABCRYPTO_ABETTOR_data      /* Hash */
);


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__crypto__SHA256 (
  ORG_LABCRYPTO_ABETTOR_data      /* Data */,
  ORG_LABCRYPTO_ABETTOR_uint32    /* Data length */,
  ORG_LABCRYPTO_ABETTOR_data      /* Hash */
);


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__crypto__DES_cbc_encrypt (
  ORG_LABCRYPTO_ABETTOR_data          /* Data */,
  ORG_LABCRYPTO_ABETTOR_uint32        /* Data length */,
  ORG_LABCRYPTO_ABETTOR_data          /* Cipher */,
  ORG_LABCRYPTO_ABETTOR_uint32_ptr    /* Pointer to cipher length */,
  ORG_LABCRYPTO_ABETTOR_DES_key       /* DES key */
);


ORG_LABCRYPTO_ABETTOR_result    
ORG_LABCRYPTO_ABETTOR__crypto__DES_cbc_decrypt (
  ORG_LABCRYPTO_ABETTOR_data          /* Cipher */,
  ORG_LABCRYPTO_ABETTOR_uint32        /* Cipher length */,
  ORG_LABCRYPTO_ABETTOR_data          /* Data */,
  ORG_LABCRYPTO_ABETTOR_uint32_ptr    /* Pointer to data length */,
  ORG_LABCRYPTO_ABETTOR_DES_key       /* DES key */
);


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__crypto__3DES_cbc_encrypt (
  ORG_LABCRYPTO_ABETTOR_data           /* Data */,
  ORG_LABCRYPTO_ABETTOR_uint32         /* Data length */,
  ORG_LABCRYPTO_ABETTOR_data           /* Cipher */,
  ORG_LABCRYPTO_ABETTOR_uint32_ptr     /* Pointer to cipher length */,
  ORG_LABCRYPTO_ABETTOR_DES_key        /* First DES key */,
  ORG_LABCRYPTO_ABETTOR_DES_key        /* Second DES key */,
  ORG_LABCRYPTO_ABETTOR_DES_key        /* Third DES key */
);


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__crypto__3DES_cbc_decrypt (
  ORG_LABCRYPTO_ABETTOR_data           /* Cipher */,
  ORG_LABCRYPTO_ABETTOR_uint32         /* Cipher length */,
  ORG_LABCRYPTO_ABETTOR_data           /* Data */,
  ORG_LABCRYPTO_ABETTOR_uint32_ptr     /* Pointer to data length */,
  ORG_LABCRYPTO_ABETTOR_DES_key        /* First DES key */,
  ORG_LABCRYPTO_ABETTOR_DES_key        /* Second DES key */,
  ORG_LABCRYPTO_ABETTOR_DES_key        /* Third DES key */
);


ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__crypto__MAC_v3 (
  ORG_LABCRYPTO_ABETTOR_data         /* Message */,
  ORG_LABCRYPTO_ABETTOR_uint32       /* Message length */,
  ORG_LABCRYPTO_ABETTOR_data         /* MAC */,
  ORG_LABCRYPTO_ABETTOR_data         /* Initial check block */,
  ORG_LABCRYPTO_ABETTOR_bool         /* Is padded ? */,
  ORG_LABCRYPTO_ABETTOR_DES_key      /* Key 1*/,
  ORG_LABCRYPTO_ABETTOR_DES_key      /* Key 2*/
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__crypto__generate_RSA (
  ORG_LABCRYPTO_ABETTOR_uint32                      /* Modulus size */,
  ORG_LABCRYPTO_ABETTOR__crypto__RSA_key_pair_ptr    /* Pointer to RSA key pair struct */
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__crypto__free_RSA_key (
  ORG_LABCRYPTO_ABETTOR__crypto__RSA_key_pair_ptr    /* Pointer to RSA key pair struct */
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__crypto__calculate_public_key (
  ORG_LABCRYPTO_ABETTOR__crypto__RSA_key_pair_ptr    /* Pointer to RSA key pair struct */
);


#ifdef __cplusplus
}
#endif

#endif