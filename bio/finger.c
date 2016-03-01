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
