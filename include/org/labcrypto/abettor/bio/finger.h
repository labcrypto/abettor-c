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
 
#ifndef _ORG_LABCRYPTO_ABETTOR__C__BIO__FINGER_H_
#define _ORG_LABCRYPTO_ABETTOR__C__BIO__FINGER_H_

#include <org/labcrypto/abettor/bio/cbeff.h>


#ifdef __cplusplus
extern "C" {
#endif


typedef struct {
  ORG_LABCRYPTO_ABETTOR_uint8 certification_authority_identifier;
  ORG_LABCRYPTO_ABETTOR_uint8 certification_scheme_identifier;
} ORG_LABCRYPTO_ABETTOR__bio__fingerprint_certification_block_data;
typedef ORG_LABCRYPTO_ABETTOR__bio__fingerprint_certification_block_data PTR   ORG_LABCRYPTO_ABETTOR__bio__fingerprint_certification_block_data_ptr;


typedef struct {
  ORG_LABCRYPTO_ABETTOR_uint8 quality_score;
  ORG_LABCRYPTO_ABETTOR_uint16 quality_algorithm_vendor_id;
  ORG_LABCRYPTO_ABETTOR_uint16 quality_vendor_id;
} ORG_LABCRYPTO_ABETTOR__bio__fingerprint_quality_block_data;
typedef ORG_LABCRYPTO_ABETTOR__bio__fingerprint_quality_block_data PTR   ORG_LABCRYPTO_ABETTOR__bio__fingerprint_quality_block_data_ptr;


typedef struct {
  ORG_LABCRYPTO_ABETTOR_length representation_length;
  ORG_LABCRYPTO_ABETTOR_char capture_date_and_time[9];
  ORG_LABCRYPTO_ABETTOR_uint8 capture_device_technology_identifier;
  ORG_LABCRYPTO_ABETTOR_uint16 capture_device_vendor_identifier;
  ORG_LABCRYPTO_ABETTOR_uint16 capture_device_type_identifier;
  ORG_LABCRYPTO_ABETTOR_uint8 number_of_quality_blocks;
  ORG_LABCRYPTO_ABETTOR__bio__fingerprint_quality_block_data_ptr quality_data_blocks;
  ORG_LABCRYPTO_ABETTOR_uint8 number_of_certification_blocks;
  ORG_LABCRYPTO_ABETTOR__bio__fingerprint_certification_block_data certification_data_blocks;
  ORG_LABCRYPTO_ABETTOR_uint8 finger_or_palm_position;
  ORG_LABCRYPTO_ABETTOR_uint8 representation_number;
  ORG_LABCRYPTO_ABETTOR_uint8 scale_units;
  ORG_LABCRYPTO_ABETTOR_uint16 capture_device_horizantal_spatial_sampling_rate;
  ORG_LABCRYPTO_ABETTOR_uint16 capture_device_vertical_spatial_sampling_rate;
  ORG_LABCRYPTO_ABETTOR_uint16 image_horizantal_spatial_sampling_rate;
  ORG_LABCRYPTO_ABETTOR_uint16 image_vertical_spatial_sampling_rate;
  ORG_LABCRYPTO_ABETTOR_uint8 bit_depth;
  ORG_LABCRYPTO_ABETTOR_uint8 image_compression_algorithm;
  ORG_LABCRYPTO_ABETTOR_uint8 impression_type;
  ORG_LABCRYPTO_ABETTOR_uint16 horizantal_line_length;
  ORG_LABCRYPTO_ABETTOR_uint16 vertical_line_length;
  ORG_LABCRYPTO_ABETTOR_length image_data_length;
} ORG_LABCRYPTO_ABETTOR__bio__fingerprint_represenation_header;
typedef ORG_LABCRYPTO_ABETTOR__bio__fingerprint_represenation_header PTR   ORG_LABCRYPTO_ABETTOR__bio__fingerprint_represenation_header_ptr;


typedef struct {
  ORG_LABCRYPTO_ABETTOR_uint16 type_identification_code;
  ORG_LABCRYPTO_ABETTOR_uint16 length_of_data;
  ORG_LABCRYPTO_ABETTOR_data data_section;
} ORG_LABCRYPTO_ABETTOR__bio__fingerprint_extended_data_block;
typedef ORG_LABCRYPTO_ABETTOR__bio__fingerprint_extended_data_block PTR   ORG_LABCRYPTO_ABETTOR__bio__fingerprint_extended_data_block_ptr;


typedef struct {
  ORG_LABCRYPTO_ABETTOR_data image_data;
  ORG_LABCRYPTO_ABETTOR__bio__fingerprint_extended_data_block_ptr extended_data_blocks;
} ORG_LABCRYPTO_ABETTOR__bio__fingerprint_representation_body;
typedef ORG_LABCRYPTO_ABETTOR__bio__fingerprint_representation_body PTR   ORG_LABCRYPTO_ABETTOR__bio__fingerprint_representation_body_ptr;


typedef struct {
  ORG_LABCRYPTO_ABETTOR__bio__fingerprint_represenation_header fingerprint_representation_header;
  ORG_LABCRYPTO_ABETTOR__bio__fingerprint_representation_body fingerprint_representation_body;
} ORG_LABCRYPTO_ABETTOR__bio__fingerprint_representation;
typedef ORG_LABCRYPTO_ABETTOR__bio__fingerprint_representation PTR   ORG_LABCRYPTO_ABETTOR__bio__fingerprint_representation_ptr;


typedef struct {
  ORG_LABCRYPTO_ABETTOR_char format_identitfier[4];
  ORG_LABCRYPTO_ABETTOR_char version_number[4];
  ORG_LABCRYPTO_ABETTOR_length length_of_record;
  ORG_LABCRYPTO_ABETTOR_uint16 number_of_representations;
  ORG_LABCRYPTO_ABETTOR_bool certification_flag;
  ORG_LABCRYPTO_ABETTOR_uint8 number_of_distinct_positions;
} ORG_LABCRYPTO_ABETTOR__bio__fingerprint_general_header;
typedef ORG_LABCRYPTO_ABETTOR__bio__fingerprint_general_header PTR   ORG_LABCRYPTO_ABETTOR__bio__fingerprint_general_header_ptr;


typedef struct {
  ORG_LABCRYPTO_ABETTOR__bio__fingerprint_general_header fingerprint_general_header;
  ORG_LABCRYPTO_ABETTOR__bio__fingerprint_representation_ptr fingerprint_representations;
} ORG_LABCRYPTO_ABETTOR__bio__FIR_biometric_data_block;
typedef ORG_LABCRYPTO_ABETTOR__bio__FIR_biometric_data_block PTR   ORG_LABCRYPTO_ABETTOR__bio__FIR_biometric_data_block_ptr;


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__bio__create_FIR_biometric_data_block_from_jpeg2000_data (
  ORG_LABCRYPTO_ABETTOR_data /* JPEG2000 image data */,
  ORG_LABCRYPTO_ABETTOR_uint32 /* JPEG2000 image data length */,
  ORG_LABCRYPTO_ABETTOR_pixel /* Width */,
  ORG_LABCRYPTO_ABETTOR_pixel /* Height */,
  ORG_LABCRYPTO_ABETTOR__bio__FIR_biometric_data_block_ptr /* Pointer to FIR BDB */
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__bio__serialize_FIR_BDB (
  ORG_LABCRYPTO_ABETTOR__bio__FIR_biometric_data_block_ptr /* Pointer to FIR BDB */,
  ORG_LABCRYPTO_ABETTOR_data_ptr /* Pointer to target data buffer */,
  ORG_LABCRYPTO_ABETTOR_uint32_ptr /* Pointer to target data buffer length */
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__bio__deserialize_FIR_BDB (
  ORG_LABCRYPTO_ABETTOR_data /* Data buffer */,
  ORG_LABCRYPTO_ABETTOR_uint32 /* Data buffer length */,
  ORG_LABCRYPTO_ABETTOR__bio__FIR_biometric_data_block_ptr /* Pointer to FIR BDB */
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__bio__exract_fingerprint_image (
  ORG_LABCRYPTO_ABETTOR__bio__FIR_biometric_data_block_ptr /* Pointer to FIR BDB */,
  ORG_LABCRYPTO_ABETTOR_data_ptr /* Pointer to target data buffer */,
  ORG_LABCRYPTO_ABETTOR_uint32_ptr /* Pointer to target data buffer length */
);


#ifdef __cplusplus
}
#endif

#endif