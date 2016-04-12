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
 
#include <stdlib.h>

#include <naeem/test.h>
#include <naeem/util.h>
#include <naeem/bio/finger.h>


NAEEM_void
NAEEM_bio__create_FIR_biometric_data_block_from_jpeg2000_data (
  NAEEM_data jpeg2000_image_data,
  NAEEM_uint32 jpeg2000_image_data_length,
  NAEEM_pixel width,
  NAEEM_pixel height,
  NAEEM_bio__FIR_biometric_data_block_ptr FIR_biometric_data_block_ptr
) {
  // TODO
}


NAEEM_void
NAEEM_bio__serialize_FIR_BDB (
  NAEEM_bio__FIR_biometric_data_block_ptr FIR_biometric_data_block_ptr,
  NAEEM_data_ptr buffer_ptr,
  NAEEM_uint32_ptr buffer_length_ptr
) {
  // TODO
}

NAEEM_void
NAEEM_bio__deserialize_FIR_BDB (
  NAEEM_data buffer,
  NAEEM_uint32 buffer_length,
  NAEEM_bio__FIR_biometric_data_block_ptr FIR_biometric_data_block_ptr
) {
  // TODO
}


NAEEM_void
NAEEM_bio__exract_fingerprint_image (
  NAEEM_bio__FIR_biometric_data_block_ptr FIR_biometric_data_block_ptr,
  NAEEM_data_ptr buffer_ptr,
  NAEEM_uint32_ptr buffer_length_ptr
) {
  // TODO
}
