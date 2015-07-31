#include <stdio.h>
#include <stdlib.h>

#include <naeem/test.h>
#include <naeem/utils.h>


NAEEM_void
NAEEM_test_assert (NAEEM_bool value, 
                   NAEEM_string failure_message) {
  if (!value) {
    printf("> FAILURE: %s\n", failure_message);
    exit(1);
  }  
}


NAEEM_void
NAEEM_test_assert_equal_uint32 (NAEEM_uint32 expected_value,
                                NAEEM_uint32 actual_value,
                                NAEEM_string failure_message) {
	if (expected_value != actual_value) {
    printf("> FAILURE: %s\n", failure_message);
	  exit(1);
	}
}


NAEEM_void
NAEEM_test_assert_equal_byte_arrays (NAEEM_data expected_data, 
                                     NAEEM_uint32 expected_data_length, 
                                     NAEEM_data actual_data,
                                     NAEEM_uint32 actual_data_length,
                                     NAEEM_string failure_message) {
	if (!NAEEM_util_compare_data(expected_data, expected_data_length, actual_data, actual_data_length)) {
	  printf("> FAILURE: %s\n", failure_message);
	  exit(1);
	}
}
