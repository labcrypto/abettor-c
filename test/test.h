#ifndef _NAEEM_TEST_H_
#define _NAEEM_TEST_H_

#include <naeem/types.h>

#ifdef __cplusplus
extern "C" {
#endif


NAEEM_void
NAEEM_test__assert (NAEEM_bool      /* Boolean value */, 
                    NAEEM_string    /* Failure message */);


NAEEM_void
NAEEM_test__assert_equal_uint32 (NAEEM_uint32      /* Expected value */,
                                 NAEEM_uint32      /* Actual value */,
                                 NAEEM_string      /* Failure message */);


NAEEM_void
NAEEM_test__assert_equal_byte_arrays (NAEEM_data      /* Expected data */, 
                                      NAEEM_uint32    /* Expected data length */, 
                                      NAEEM_data      /* Actual data */,
                                      NAEEM_uint32    /* Actual data length */,
                                      NAEEM_string    /* Failure message */);


#ifdef __cplusplus
}
#endif

#endif