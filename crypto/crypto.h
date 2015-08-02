#ifndef _NAEEM_CORELIBS__CRYPTO_H_
#define _NAEEM_CORELIBS__CRYPTO_H_

#include <stdlib.h>
#include <stdio.h>

#include <naeem/types.h>


#ifdef __cplusplus
extern "C" {
#endif

#define DES_KEY_LENGTH 8

typedef NAEEM_byte NAEEM_DES_key[DES_KEY_LENGTH];

typedef struct {
  NAEEM_data        public_key;
  NAEEM_uint32      public_key_length;
  NAEEM_data        private_key;
  NAEEM_uint32      private_key_length;
  NAEEM_data        private_key_N_data;
  NAEEM_uint32      private_key_N_length;
  NAEEM_data        private_key_E_data;
  NAEEM_uint32      private_E_length;
  NAEEM_data        private_key_D_data;
  NAEEM_uint32      private_D_length;
  NAEEM_data        private_key_P_data;
  NAEEM_uint32      private_P_length;
  NAEEM_data        private_key_Q_data;
  NAEEM_uint32      private_Q_length;
  NAEEM_data        private_key_EXP1_data;
  NAEEM_uint32      private_EXP1_length;
  NAEEM_data        private_key_EXP2_data;
  NAEEM_uint32      private_EXP2_length;
  NAEEM_data        private_key_C_data;
  NAEEM_uint32      private_C_length;
} NAEEM_crypto__RSA_key_pair;
typedef NAEEM_crypto__RSA_key_pair PTR NAEEM_crypto__RSA_key_pair_ptr;


NAEEM_result
NAEEM_crypto__SHA1 (NAEEM_data      /* Data */,
                    NAEEM_uint32    /* Data length */,
                    NAEEM_data      /* Hash */);


NAEEM_result
NAEEM_crypto__SHA256 (NAEEM_data      /* Data */,
                      NAEEM_uint32    /* Data length */,
                      NAEEM_data      /* Hash */);


NAEEM_result
NAEEM_crypto__DES_cbc_encrypt (NAEEM_data          /* Data */,
                               NAEEM_uint32        /* Data length */,
                               NAEEM_data          /* Cipher */,
                               NAEEM_uint32_ptr    /* Pointer to cipher length */,
                               NAEEM_DES_key       /* DES key */);


NAEEM_result    
NAEEM_crypto__DES_cbc_decrypt (NAEEM_data          /* Cipher */,
                               NAEEM_uint32        /* Cipher length */,
                               NAEEM_data          /* Data */,
                               NAEEM_uint32_ptr    /* Pointer to data length */,
                               NAEEM_DES_key       /* DES key */);


NAEEM_result
NAEEM_crypto__3DES_cbc_encrypt (NAEEM_data           /* Data */,
                                NAEEM_uint32         /* Data length */,
                                NAEEM_data           /* Cipher */,
                                NAEEM_uint32_ptr     /* Pointer to cipher length */,
                                NAEEM_DES_key        /* First DES key */,
                                NAEEM_DES_key        /* Second DES key */,
                                NAEEM_DES_key        /* Third DES key */);


NAEEM_result
NAEEM_crypto__3DES_cbc_decrypt (NAEEM_data           /* Cipher */,
                                NAEEM_uint32         /* Cipher length */,
                                NAEEM_data           /* Data */,
                                NAEEM_uint32_ptr     /* Pointer to data length */,
                                NAEEM_DES_key        /* First DES key */,
                                NAEEM_DES_key        /* Second DES key */,
                                NAEEM_DES_key        /* Third DES key */);


NAEEM_result
NAEEM_crypto__MAC_v3 (NAEEM_data         /* Message */,
                      NAEEM_uint32       /* Message length */,
                      NAEEM_data         /* MAC */,
                      NAEEM_data         /* Initial check block */,
                      NAEEM_bool         /* Is padded ? */,
                      NAEEM_DES_key      /* Key 1*/,
                      NAEEM_DES_key      /* Key 2*/);


#ifdef __cplusplus
}
#endif

#endif
