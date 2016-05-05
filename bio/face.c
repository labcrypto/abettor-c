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
#include <org/labcrypto/abettor/bio/face.h>


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__bio__create_FAC_biometric_data_block_from_jpeg2000_data (
  ORG_LABCRYPTO_ABETTOR_data jpeg2000_image_data,
  ORG_LABCRYPTO_ABETTOR_uint32 jpeg2000_image_data_length,
  ORG_LABCRYPTO_ABETTOR_pixel width,
  ORG_LABCRYPTO_ABETTOR_pixel height,
  ORG_LABCRYPTO_ABETTOR__bio__FAC_biometric_data_block_ptr FAC_biometric_data_block_ptr
) {
  // Copy JPEG2000 image data into FAC BDB
  FAC_biometric_data_block_ptr->facial_record_data.jpeg_image.data = 
    (ORG_LABCRYPTO_ABETTOR_data)malloc(jpeg2000_image_data_length * sizeof(ORG_LABCRYPTO_ABETTOR_byte));
  ORG_LABCRYPTO_ABETTOR__util__copy_array(
    FAC_biometric_data_block_ptr->facial_record_data.jpeg_image.data, 
    jpeg2000_image_data,
    0,
    jpeg2000_image_data_length
  );
  FAC_biometric_data_block_ptr->facial_record_data.jpeg_image.length = jpeg2000_image_data_length;
  FAC_biometric_data_block_ptr->facial_record_data.jpeg_image.type = ORG_LABCRYPTO_ABETTOR__BIO__FACE__JPEG_TYPE__JPEG2000;
  // Fill Image Information
  FAC_biometric_data_block_ptr->facial_record_data.image_information.face_image_type = ORG_LABCRYPTO_ABETTOR__BIO__FACE__IMAGE_TYPE__TOKEN_FRONTAL;
  FAC_biometric_data_block_ptr->facial_record_data.image_information.image_data_type = 0x01; // TODO
  FAC_biometric_data_block_ptr->facial_record_data.image_information.width = width;
  FAC_biometric_data_block_ptr->facial_record_data.image_information.height = height;
  FAC_biometric_data_block_ptr->facial_record_data.image_information.image_color_space = 0x01; // TODO
  FAC_biometric_data_block_ptr->facial_record_data.image_information.source_type = 0x03; // TODO
  FAC_biometric_data_block_ptr->facial_record_data.image_information.device_type = 0x00; // TODO
  FAC_biometric_data_block_ptr->facial_record_data.image_information.quality = 0x00; // TODO
  // Create and fill Feature Point struct
  FAC_biometric_data_block_ptr->facial_record_data.feature_points = 
    (ORG_LABCRYPTO_ABETTOR__bio__feature_point_ptr)malloc(sizeof(ORG_LABCRYPTO_ABETTOR__bio__feature_point));
  FAC_biometric_data_block_ptr->facial_record_data.feature_points[0].feature_point_type = 0x01; // TODO
  FAC_biometric_data_block_ptr->facial_record_data.feature_points[0].feature_point_code = 0xc1; // TODO
  FAC_biometric_data_block_ptr->facial_record_data.feature_points[0].horizantal_position = 0x59;
  FAC_biometric_data_block_ptr->facial_record_data.feature_points[0].vertical_position = 0x90;
  // Fill Facial Information
  FAC_biometric_data_block_ptr->facial_record_data.facial_information.length_of_record = jpeg2000_image_data_length + 40;
  FAC_biometric_data_block_ptr->facial_record_data.facial_information.number_of_feature_points = 1;
  FAC_biometric_data_block_ptr->facial_record_data.facial_information.gender = 0x00; // TODO
  FAC_biometric_data_block_ptr->facial_record_data.facial_information.eye_color = 0x00; // TODO
  FAC_biometric_data_block_ptr->facial_record_data.facial_information.hair_color = 0x00; // TODO
  FAC_biometric_data_block_ptr->facial_record_data.facial_information.property_mask[0] = 0x00; // TODO
  FAC_biometric_data_block_ptr->facial_record_data.facial_information.property_mask[1] = 0x00;
  FAC_biometric_data_block_ptr->facial_record_data.facial_information.property_mask[2] = 0x00;
  FAC_biometric_data_block_ptr->facial_record_data.facial_information.expression[0] = 0x00; // TODO
  FAC_biometric_data_block_ptr->facial_record_data.facial_information.expression[1] = 0x01; 
  FAC_biometric_data_block_ptr->facial_record_data.facial_information.pose_angle[0] = 0x01; // TODO
  FAC_biometric_data_block_ptr->facial_record_data.facial_information.pose_angle[1] = 0x01;
  FAC_biometric_data_block_ptr->facial_record_data.facial_information.pose_angle[2] = 0x01;
  FAC_biometric_data_block_ptr->facial_record_data.facial_information.pose_angle_uncertainty[0] = 0x00; // TODO
  FAC_biometric_data_block_ptr->facial_record_data.facial_information.pose_angle_uncertainty[1] = 0x00;
  FAC_biometric_data_block_ptr->facial_record_data.facial_information.pose_angle_uncertainty[2] = 0x00;
  // Fill Facial Record Header
  FAC_biometric_data_block_ptr->facial_record_header.format_identitfier[0] = 'F';
  FAC_biometric_data_block_ptr->facial_record_header.format_identitfier[1] = 'A';
  FAC_biometric_data_block_ptr->facial_record_header.format_identitfier[2] = 'C';
  FAC_biometric_data_block_ptr->facial_record_header.format_identitfier[3] = 0x00;
  FAC_biometric_data_block_ptr->facial_record_header.version_number[0] = 0x30;
  FAC_biometric_data_block_ptr->facial_record_header.version_number[1] = 0x31;
  FAC_biometric_data_block_ptr->facial_record_header.version_number[2] = 0x30;
  FAC_biometric_data_block_ptr->facial_record_header.version_number[3] = 0x00;
  FAC_biometric_data_block_ptr->facial_record_header.length_of_record = jpeg2000_image_data_length + 54;
  FAC_biometric_data_block_ptr->facial_record_header.number_of_facial_images = 1;
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__bio__serialize_FAC_BDB (
  ORG_LABCRYPTO_ABETTOR__bio__FAC_biometric_data_block_ptr FAC_biometric_data_block_ptr,
  ORG_LABCRYPTO_ABETTOR_data_ptr buffer_ptr,
  ORG_LABCRYPTO_ABETTOR_uint32_ptr buffer_length_ptr
) {
  // ORG_LABCRYPTO_ABETTOR_uint32 i = 0;
  ORG_LABCRYPTO_ABETTOR_uint32 c = 0, cc = 0;
  ORG_LABCRYPTO_ABETTOR_data buffer;
  // ORG_LABCRYPTO_ABETTOR_uint32 a1_block_length;
  ORG_LABCRYPTO_ABETTOR_uint32 overal_length = 0;
  overal_length += FAC_biometric_data_block_ptr->facial_record_header.length_of_record;
  *buffer_length_ptr = overal_length;
  buffer = *buffer_ptr = (ORG_LABCRYPTO_ABETTOR_data)malloc(overal_length * sizeof(ORG_LABCRYPTO_ABETTOR_byte));
  c = 0;
  buffer[c++] = 'F';
  buffer[c++] = 'A';
  buffer[c++] = 'C';
  buffer[c++] = 0x00;
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_header.version_number[0];
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_header.version_number[1];
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_header.version_number[2];
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_header.version_number[3];
  buffer[c++] = 0x00;
  buffer[c++] = 0x00;
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_header.length_of_record / 256;
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_header.length_of_record % 256;
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_header.number_of_facial_images / 256;
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_header.number_of_facial_images % 256;

  buffer[c++] = 0x00;
  buffer[c++] = 0x00;
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.facial_information.length_of_record / 256;
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.facial_information.length_of_record % 256;
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.facial_information.number_of_feature_points / 256;
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.facial_information.number_of_feature_points % 256;
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.facial_information.gender;
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.facial_information.eye_color;
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.facial_information.hair_color;
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.facial_information.property_mask[0];
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.facial_information.property_mask[1];
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.facial_information.property_mask[2];
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.facial_information.expression[0];
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.facial_information.expression[1];
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.facial_information.pose_angle[0];
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.facial_information.pose_angle[1];
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.facial_information.pose_angle[2];
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.facial_information.pose_angle_uncertainty[0];
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.facial_information.pose_angle_uncertainty[1];
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.facial_information.pose_angle_uncertainty[2];

  cc = 0;
  for (; 
       cc < FAC_biometric_data_block_ptr->facial_record_data.facial_information.number_of_feature_points;
       cc++) {
    buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.feature_points[cc].feature_point_type;
    buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.feature_points[cc].feature_point_code;
    buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.feature_points[cc].horizantal_position / 256;
    buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.feature_points[cc].horizantal_position % 256;
    buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.feature_points[cc].vertical_position / 256;
    buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.feature_points[cc].vertical_position % 256;
    buffer[c++] = 0x00;
    buffer[c++] = 0x00;
  }

  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.image_information.face_image_type;
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.image_information.image_data_type;
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.image_information.width / 256;
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.image_information.width % 256;
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.image_information.height / 256;
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.image_information.height % 256;
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.image_information.image_color_space;
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.image_information.source_type;
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.image_information.device_type / 256;
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.image_information.device_type % 256;
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.image_information.quality / 256;
  buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.image_information.quality % 256;

  for (cc = 0; 
       cc < FAC_biometric_data_block_ptr->facial_record_data.jpeg_image.length; 
       cc++) {
    buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.jpeg_image.data[cc];
  }

  ORG_LABCRYPTO_ABETTOR__test__assert(c == overal_length, "Inconsistency in bio structure.");
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__bio__deserialize_FAC_BDB (
  ORG_LABCRYPTO_ABETTOR_data buffer,
  ORG_LABCRYPTO_ABETTOR_uint32 buffer_length,
  ORG_LABCRYPTO_ABETTOR__bio__FAC_biometric_data_block_ptr FAC_biometric_data_block_ptr
) {
  // TODO
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__bio__exract_face_image (
  ORG_LABCRYPTO_ABETTOR__bio__FAC_biometric_data_block_ptr FAC_biometric_data_block_ptr,
  ORG_LABCRYPTO_ABETTOR_data_ptr buffer_ptr,
  ORG_LABCRYPTO_ABETTOR_uint32_ptr buffer_length_ptr
) {
  // TODO
}