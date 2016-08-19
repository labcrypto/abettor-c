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
 
#ifndef _ORG_LABCRYPTO_ABETTOR__C__BIO__FACE_H_
#define _ORG_LABCRYPTO_ABETTOR__C__BIO__FACE_H_

#include <org/labcrypto/abettor/bio/cbeff.h>


#ifdef __cplusplus
extern "C" {
#endif


#define ORG_LABCRYPTO_ABETTOR__BIO__FACE__JPEG_TYPE__JPEG2000                                               0x00000100
#define ORG_LABCRYPTO_ABETTOR__BIO__FACE__JPEG_TYPE__JFIF                                                   0x00000101

#define ORG_LABCRYPTO_ABETTOR__BIO__FACE__IMAGE_TYPE__TOKEN_FRONTAL                                         0x02


typedef struct {
  ORG_LABCRYPTO_ABETTOR_data data;
  ORG_LABCRYPTO_ABETTOR_length length;
  ORG_LABCRYPTO_ABETTOR_uint32 type;
} ORG_LABCRYPTO_ABETTOR__bio__JPEG_image;
typedef ORG_LABCRYPTO_ABETTOR__bio__JPEG_image PTR   ORG_LABCRYPTO_ABETTOR__bio_JPEG_image_ptr;


typedef struct {
  ORG_LABCRYPTO_ABETTOR_byte face_image_type;
  ORG_LABCRYPTO_ABETTOR_byte image_data_type;
  ORG_LABCRYPTO_ABETTOR_uint16 width;
  ORG_LABCRYPTO_ABETTOR_uint16 height;
  ORG_LABCRYPTO_ABETTOR_uint8 image_color_space;
  ORG_LABCRYPTO_ABETTOR_uint8 source_type;
  ORG_LABCRYPTO_ABETTOR_uint16 device_type;
  ORG_LABCRYPTO_ABETTOR_uint16 quality;
} ORG_LABCRYPTO_ABETTOR__bio__image_information;
typedef ORG_LABCRYPTO_ABETTOR__bio__image_information PTR   ORG_LABCRYPTO_ABETTOR__bio__image_information_ptr;


typedef struct {
  ORG_LABCRYPTO_ABETTOR_byte feature_point_type;
  ORG_LABCRYPTO_ABETTOR_byte feature_point_code;
  ORG_LABCRYPTO_ABETTOR_uint16 horizantal_position;
  ORG_LABCRYPTO_ABETTOR_uint16 vertical_position;
} ORG_LABCRYPTO_ABETTOR__bio__feature_point;
typedef ORG_LABCRYPTO_ABETTOR__bio__feature_point PTR   ORG_LABCRYPTO_ABETTOR__bio__feature_point_ptr;


typedef struct {
  ORG_LABCRYPTO_ABETTOR_length length_of_record;
  ORG_LABCRYPTO_ABETTOR_uint16 number_of_feature_points;
  ORG_LABCRYPTO_ABETTOR_byte gender;
  ORG_LABCRYPTO_ABETTOR_byte eye_color;
  ORG_LABCRYPTO_ABETTOR_byte hair_color;
  ORG_LABCRYPTO_ABETTOR_byte property_mask[3];
  ORG_LABCRYPTO_ABETTOR_uint8 expression[2];
  ORG_LABCRYPTO_ABETTOR_uint8 pose_angle[3];
  ORG_LABCRYPTO_ABETTOR_uint8 pose_angle_uncertainty[3];
} ORG_LABCRYPTO_ABETTOR__bio__facial_information;
typedef ORG_LABCRYPTO_ABETTOR__bio__facial_information PTR   ORG_LABCRYPTO_ABETTOR__bio__facial_information_ptr;


typedef struct {
  ORG_LABCRYPTO_ABETTOR__bio__facial_information facial_information;
  ORG_LABCRYPTO_ABETTOR__bio__feature_point_ptr feature_points;
  ORG_LABCRYPTO_ABETTOR__bio__image_information image_information;
  ORG_LABCRYPTO_ABETTOR__bio__JPEG_image jpeg_image;
} ORG_LABCRYPTO_ABETTOR__bio__facial_record_data;
typedef ORG_LABCRYPTO_ABETTOR__bio__facial_record_data PTR   ORG_LABCRYPTO_ABETTOR__bio_facial__record_data_ptr;


typedef struct {
  ORG_LABCRYPTO_ABETTOR_char format_identitfier[4];
  ORG_LABCRYPTO_ABETTOR_byte version_number[4];
  ORG_LABCRYPTO_ABETTOR_length length_of_record;
  ORG_LABCRYPTO_ABETTOR_uint16 number_of_facial_images;
} ORG_LABCRYPTO_ABETTOR__bio__facial_record_header;
typedef ORG_LABCRYPTO_ABETTOR__bio__facial_record_header PTR   ORG_LABCRYPTO_ABETTOR__bio__facial_record_header_ptr;


typedef struct {
  ORG_LABCRYPTO_ABETTOR__bio__facial_record_header facial_record_header;
  ORG_LABCRYPTO_ABETTOR__bio__facial_record_data facial_record_data;                          
} ORG_LABCRYPTO_ABETTOR__bio__FAC_biometric_data_block;
typedef ORG_LABCRYPTO_ABETTOR__bio__FAC_biometric_data_block PTR    ORG_LABCRYPTO_ABETTOR__bio__FAC_biometric_data_block_ptr;


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__bio__create_FAC_biometric_data_block_from_jpeg2000_data (
  ORG_LABCRYPTO_ABETTOR_data /* JPEG2000 image data */,
  ORG_LABCRYPTO_ABETTOR_uint32 /* JPEG2000 image data length */,
  ORG_LABCRYPTO_ABETTOR_pixel /* Width */,
  ORG_LABCRYPTO_ABETTOR_pixel /* Height */,
  ORG_LABCRYPTO_ABETTOR__bio__FAC_biometric_data_block_ptr /* Pointer to CBEFF FAC BDB */
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__bio__serialize_FAC_BDB (
  ORG_LABCRYPTO_ABETTOR__bio__FAC_biometric_data_block_ptr /* Pointer to FAC BDB */,
  ORG_LABCRYPTO_ABETTOR_data_ptr /* Pointer to target data buffer */,
  ORG_LABCRYPTO_ABETTOR_uint32_ptr /* Pointer to target data buffer length */
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__bio__deserialize_FAC_BDB (
  ORG_LABCRYPTO_ABETTOR_data /* Data buffer */,
  ORG_LABCRYPTO_ABETTOR_uint32 /* Data buffer length */,
  ORG_LABCRYPTO_ABETTOR__bio__FAC_biometric_data_block_ptr /* Pointer to FAC BDB */
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__bio__exract_face_image (
  ORG_LABCRYPTO_ABETTOR__bio__FAC_biometric_data_block_ptr /* Pointer to FAC BDB */,
  ORG_LABCRYPTO_ABETTOR_data_ptr /* Pointer to target data buffer */,
  ORG_LABCRYPTO_ABETTOR_uint32_ptr /* Pointer to target data buffer length */
);


#ifdef __cplusplus
}
#endif

#endif