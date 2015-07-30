#ifndef _NAEEM_RAND_H_
#define _NAEEM_RAND_H_

#include <naeem/types.h>

#ifdef __cplusplus
extern "C" {
#endif


NAEEM_void
NAEEM_rand_generate_8_bytes (NAEEM_data /* Buffer to store generated random bytes */);


NAEEM_void
NAEEM_rand_generate_16_bytes (NAEEM_data /* Buffer to store generate random bytes */);


#ifdef __cplusplus
}
#endif

#endif