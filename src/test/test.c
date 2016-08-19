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

#include <stdio.h>
#include <stdlib.h>

#include <org/labcrypto/abettor/test.h>
#include <org/labcrypto/abettor/util.h>


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__test__assert (
  ORG_LABCRYPTO_ABETTOR_bool value, 
  ORG_LABCRYPTO_ABETTOR_string failure_message
) {
  if (!value) {
    printf("> FAILURE: %s\n", failure_message);
    exit(1);
  }  
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__test__assert_equal_uint32 (
  ORG_LABCRYPTO_ABETTOR_uint32 expected_value,
  ORG_LABCRYPTO_ABETTOR_uint32 actual_value,
  ORG_LABCRYPTO_ABETTOR_string failure_message
) {
	if (expected_value != actual_value) {
    printf("> FAILURE: %s\n", failure_message);
	  exit(1);
	}
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__test__assert_equal_byte_arrays (
  ORG_LABCRYPTO_ABETTOR_data expected_data, 
  ORG_LABCRYPTO_ABETTOR_uint32 expected_data_length, 
  ORG_LABCRYPTO_ABETTOR_data actual_data,
  ORG_LABCRYPTO_ABETTOR_uint32 actual_data_length,
  ORG_LABCRYPTO_ABETTOR_string failure_message
) {
	if (!ORG_LABCRYPTO_ABETTOR__util__compare_data(expected_data, expected_data_length, actual_data, actual_data_length)) {
	  printf("> FAILURE: %s\n", failure_message);
	  exit(1);
	}
}
