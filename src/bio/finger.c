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
 
#include <stdlib.h>

#include <org/labcrypto/abettor/test.h>
#include <org/labcrypto/abettor/util.h>
#include <org/labcrypto/abettor/bio/finger.h>


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__bio__create_FIR_biometric_data_block_from_jpeg2000_data (
  ORG_LABCRYPTO_ABETTOR_data jpeg2000_image_data,
  ORG_LABCRYPTO_ABETTOR_uint32 jpeg2000_image_data_length,
  ORG_LABCRYPTO_ABETTOR_pixel width,
  ORG_LABCRYPTO_ABETTOR_pixel height,
  ORG_LABCRYPTO_ABETTOR__bio__FIR_biometric_data_block_ptr FIR_biometric_data_block_ptr
) {
  // TODO
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__bio__serialize_FIR_BDB (
  ORG_LABCRYPTO_ABETTOR__bio__FIR_biometric_data_block_ptr FIR_biometric_data_block_ptr,
  ORG_LABCRYPTO_ABETTOR_data_ptr buffer_ptr,
  ORG_LABCRYPTO_ABETTOR_uint32_ptr buffer_length_ptr
) {
  // TODO
}

ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__bio__deserialize_FIR_BDB (
  ORG_LABCRYPTO_ABETTOR_data buffer,
  ORG_LABCRYPTO_ABETTOR_uint32 buffer_length,
  ORG_LABCRYPTO_ABETTOR__bio__FIR_biometric_data_block_ptr FIR_biometric_data_block_ptr
) {
  // TODO
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__bio__exract_fingerprint_image (
  ORG_LABCRYPTO_ABETTOR__bio__FIR_biometric_data_block_ptr FIR_biometric_data_block_ptr,
  ORG_LABCRYPTO_ABETTOR_data_ptr buffer_ptr,
  ORG_LABCRYPTO_ABETTOR_uint32_ptr buffer_length_ptr
) {
  // TODO
}
