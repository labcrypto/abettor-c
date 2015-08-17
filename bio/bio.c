#include <naeem/bio.h>
#include <naeem/test.h>
#include <naeem/util.h>


NAEEM_void
NAEEM_bio__create_CBEFF_record_from_facial_image_data (NAEEM_data image_data,
                                                       NAEEM_uint32 image_data_length,
                                                       NAEEM_pixel width,
                                                       NAEEM_pixel height,
                                                       NAEEM_bio__CBEFF_template_ptr CBEFF_record_ptr) {

  NAEEM_bio__FAC_biometric_data_block_ptr FAC_biometric_data_block = 
              (NAEEM_bio__FAC_biometric_data_block_ptr)malloc(
                    sizeof(NAEEM_bio__FAC_biometric_data_block));

  FAC_biometric_data_block->facial_record_header.version_number[0] = 0x30;
  FAC_biometric_data_block->facial_record_header.version_number[1] = 0x31;
  FAC_biometric_data_block->facial_record_header.version_number[2] = 0x30;
  FAC_biometric_data_block->facial_record_header.version_number[3] = 0x00;
  FAC_biometric_data_block->facial_record_header.length_of_record[0] = 0x00;
  FAC_biometric_data_block->facial_record_header.length_of_record[1] = 0x00;
  FAC_biometric_data_block->facial_record_header.length_of_record[2] = (image_data_length + 54) / 256;
  FAC_biometric_data_block->facial_record_header.length_of_record[3] = (image_data_length + 54) % 256;
  FAC_biometric_data_block->facial_record_header.number_of_facial_images[0] = 0x00;
  FAC_biometric_data_block->facial_record_header.number_of_facial_images[1] = 0x01;

  FAC_biometric_data_block->facial_record_data.facial_information.length_of_record[0] = 0x00;
  FAC_biometric_data_block->facial_record_data.facial_information.length_of_record[1] = 0x00;
  FAC_biometric_data_block->facial_record_data.facial_information.length_of_record[2] = (image_data_length + 40) / 256;
  FAC_biometric_data_block->facial_record_data.facial_information.length_of_record[3] = (image_data_length + 40) % 256;
  FAC_biometric_data_block->facial_record_data.facial_information.number_of_feature_points[0] = 0x00;
  FAC_biometric_data_block->facial_record_data.facial_information.number_of_feature_points[1] = 0x01;
  FAC_biometric_data_block->facial_record_data.facial_information.gender = 0x00; // ????
  FAC_biometric_data_block->facial_record_data.facial_information.eye_color = 0x00;
  FAC_biometric_data_block->facial_record_data.facial_information.hair_color = 0x00;
  FAC_biometric_data_block->facial_record_data.facial_information.property_mask[0] = 0x00;
  FAC_biometric_data_block->facial_record_data.facial_information.property_mask[1] = 0x00;
  FAC_biometric_data_block->facial_record_data.facial_information.property_mask[2] = 0x00;
  FAC_biometric_data_block->facial_record_data.facial_information.expression[0] = 0x00;
  FAC_biometric_data_block->facial_record_data.facial_information.expression[1] = 0x01;
  FAC_biometric_data_block->facial_record_data.facial_information.pose_angle[0] = 0x01;
  FAC_biometric_data_block->facial_record_data.facial_information.pose_angle[1] = 0x01;
  FAC_biometric_data_block->facial_record_data.facial_information.pose_angle[2] = 0x01;
  FAC_biometric_data_block->facial_record_data.facial_information.pose_angle_uncertainty[0] = 0x00;
  FAC_biometric_data_block->facial_record_data.facial_information.pose_angle_uncertainty[1] = 0x00;
  FAC_biometric_data_block->facial_record_data.facial_information.pose_angle_uncertainty[2] = 0x00;

  FAC_biometric_data_block->facial_record_data.feature_points = (NAEEM_bio__feature_point_ptr)malloc(
                    sizeof(NAEEM_bio__feature_point));

  FAC_biometric_data_block->facial_record_data.feature_points[0].feature_point_type = 0x01;
  FAC_biometric_data_block->facial_record_data.feature_points[0].feature_point_code = 0xc1;
  FAC_biometric_data_block->facial_record_data.feature_points[0].horizantal_position[0] = 0x00;
  FAC_biometric_data_block->facial_record_data.feature_points[0].horizantal_position[1] = 0x59;
  FAC_biometric_data_block->facial_record_data.feature_points[0].vertical_position[0] = 0x00;
  FAC_biometric_data_block->facial_record_data.feature_points[0].vertical_position[1] = 0x90;

  FAC_biometric_data_block->facial_record_data.image_information.face_image_type = 0x01; // Full frontal
  FAC_biometric_data_block->facial_record_data.image_information.image_data_type = 0x00;
  FAC_biometric_data_block->facial_record_data.image_information.width[0] = width / 256;
  FAC_biometric_data_block->facial_record_data.image_information.width[1] = width % 256;
  FAC_biometric_data_block->facial_record_data.image_information.height[0] = height / 256;
  FAC_biometric_data_block->facial_record_data.image_information.height[1] = height % 256;
  FAC_biometric_data_block->facial_record_data.image_information.image_color_space = 0x01;
  FAC_biometric_data_block->facial_record_data.image_information.source_type = 0x03;
  FAC_biometric_data_block->facial_record_data.image_information.device_type[0] = 0x00;
  FAC_biometric_data_block->facial_record_data.image_information.device_type[1] = 0x00;
  FAC_biometric_data_block->facial_record_data.image_information.quality[0] = 0x00;
  FAC_biometric_data_block->facial_record_data.image_information.quality[1] = 0x00;

  FAC_biometric_data_block->facial_record_data.jpeg_image.data = 
                           (NAEEM_data)malloc(image_data_length * sizeof(NAEEM_byte));

  NAEEM_util__copy_array(FAC_biometric_data_block->facial_record_data.jpeg_image.data, 
                        image_data,
                        0,
                        image_data_length);
  FAC_biometric_data_block->facial_record_data.jpeg_image.length = image_data_length;
  FAC_biometric_data_block->facial_record_data.jpeg_image.type = NAEEM_BIO_JPEG_TYPE_JPEG_JFIF;

  NAEEM_bio__biometric_information_group_template_ptr BIG_record = 
              (NAEEM_bio__biometric_information_group_template_ptr)malloc(
                    sizeof(NAEEM_bio__biometric_information_group_template));

  BIG_record->BHT_record.patron_header_format_is_present = FALSE;
  BIG_record->BHT_record.biometric_type_is_present = TRUE;
  BIG_record->BHT_record.biometric_subtype_is_present = TRUE;
  BIG_record->BHT_record.creation_date_and_time_is_present = FALSE;
  BIG_record->BHT_record.validity_period_is_present = FALSE;
  BIG_record->BHT_record.pid_is_present = FALSE;
  BIG_record->BHT_record.biometric_type = malloc(sizeof(NAEEM_byte));
  BIG_record->BHT_record.biometric_type[0] = 0x02;
  BIG_record->BHT_record.biometric_type_length = 1;
  BIG_record->BHT_record.biometric_subtype = 0x00;
  BIG_record->BHT_record.format_owner[0] = 0x01;
  BIG_record->BHT_record.format_owner[1] = 0x01;
  BIG_record->BHT_record.format_type[0] = 0x00;
  BIG_record->BHT_record.format_type[1] = 0x08;
  BIG_record->BDB_record = (NAEEM_data)FAC_biometric_data_block;
  BIG_record->BDB_record_type = NAEEM_BIO_BDB_TYPE_FAC;
  BIG_record->BDB_record_length = image_data_length + 54;

  CBEFF_record_ptr->BIG_records = (NAEEM_bio__biometric_information_group_template_ptr_ptr)malloc(
                                            sizeof(NAEEM_bio__biometric_information_group_template_ptr));

  CBEFF_record_ptr->BIG_records_length = 1;
  CBEFF_record_ptr->BIG_records[0] = BIG_record;
}


NAEEM_void
NAEEM_bio__get_CBEFF_data (NAEEM_bio__CBEFF_template_ptr CBEFF_record_ptr,
                           NAEEM_data_ptr data,
                           NAEEM_uint32_ptr data_length) {
  NAEEM_uint32 i = 0;
  NAEEM_uint32 overal_length = 2 /* 0x76f1 */ + 3 /* Length */;
  overal_length += 1 /* 0x02 */ + 1 /* Length: 0x01 */ + 1 /* Value */;
  for (i = 0; i < CBEFF_record_ptr->BIG_records_length; i++) {
    overal_length += 2 /* 0x7f60 */ + 3 /* Length */;
    overal_length += 1 /* 0xa1 */ + 1 /* Length */;
    if (CBEFF_record_ptr->BIG_records[i]->BHT_record.patron_header_format_is_present) {
      overal_length += 1 /* 0x80 */ + 1 /* Length: 0x02 */ + 2 /* Value */;
    }
    if (CBEFF_record_ptr->BIG_records[i]->BHT_record.biometric_type_is_present) {
      overal_length += 1 /* 0x81 */ + 1 /* Length */ + 
                       CBEFF_record_ptr->BIG_records[i]->BHT_record.biometric_type_length /* Value */;
    }
    if (CBEFF_record_ptr->BIG_records[i]->BHT_record.biometric_subtype_is_present) {
      overal_length += 1 /* 0x82 */ + 1 /* Length: 0x01 */ + 1 /* Value */;
    }
    if (CBEFF_record_ptr->BIG_records[i]->BHT_record.creation_date_and_time_is_present) {
      overal_length += 1 /* 0x83 */ + 1 /* Length: 0x07 */ + 7 /* Value */;
    }
    if (CBEFF_record_ptr->BIG_records[i]->BHT_record.validity_period_is_present) {
      overal_length += 1 /* 0x85 */ + 1 /* Length: 0x08 */ + 8 /* Value */;
    }
    if (CBEFF_record_ptr->BIG_records[i]->BHT_record.pid_is_present) {
      overal_length += 1 /* 0x86 */ + 1 /* Length: 0x02 */ + 2 /* Value */;
    }
    overal_length += 1 /* 0x87 */ + 1 /* Length: 0x02 */ + 2 /* Value */;
    overal_length += 1 /* 0x88 */ + 1 /* Length: 0x02 */ + 2 /* Value */;
    overal_length += 2 /* 0x5f2e */ + 3 /* Length */;
    overal_length += CBEFF_record_ptr->BIG_records[i]->BDB_record_length;
  }
  *data_length = overal_length;
  NAEEM_data buffer = *data = (NAEEM_data)malloc(overal_length * sizeof(NAEEM_byte));
  NAEEM_uint32 c = 0;
  buffer[c++] = 0x7f;
  buffer[c++] = 0x61;
  buffer[c++] = 0x82;
  buffer[c] = (overal_length - (c + 2)) / 256;
  c++;
  buffer[c] = (overal_length - (c + 1)) % 256;
  c++;
  buffer[c++] = 0x02;
  buffer[c++] = 0x01;
  buffer[c++] = CBEFF_record_ptr->BIG_records_length;
  for (i = 0; i < CBEFF_record_ptr->BIG_records_length; i++) {
    buffer[c++] = 0x7f;
    buffer[c++] = 0x60;
    buffer[c++] = 0x82;
    buffer[c] = (overal_length - (c + 2)) / 256;
    c++;
    buffer[c] = (overal_length - (c + 1)) % 256;
    c++;
    NAEEM_uint32 a1_block_length = 0;
    if (CBEFF_record_ptr->BIG_records[i]->BHT_record.patron_header_format_is_present) {
      a1_block_length += 1 /* 0x80 */ + 1 /* Length: 0x02 */ + 2 /* Value */;
    }
    if (CBEFF_record_ptr->BIG_records[i]->BHT_record.biometric_type_is_present) {
      a1_block_length += 1 /* 0x81 */ + 1 /* Length */ + 
                       CBEFF_record_ptr->BIG_records[i]->BHT_record.biometric_type_length /* Value */;
    }
    if (CBEFF_record_ptr->BIG_records[i]->BHT_record.biometric_subtype_is_present) {
      a1_block_length += 1 /* 0x82 */ + 1 /* Length: 0x01 */ + 1 /* Value */;
    }
    if (CBEFF_record_ptr->BIG_records[i]->BHT_record.creation_date_and_time_is_present) {
      a1_block_length += 1 /* 0x83 */ + 1 /* Length: 0x07 */ + 7 /* Value */;
    }
    if (CBEFF_record_ptr->BIG_records[i]->BHT_record.validity_period_is_present) {
      a1_block_length += 1 /* 0x85 */ + 1 /* Length: 0x08 */ + 8 /* Value */;
    }
    if (CBEFF_record_ptr->BIG_records[i]->BHT_record.pid_is_present) {
      a1_block_length += 1 /* 0x86 */ + 1 /* Length: 0x02 */ + 2 /* Value */;
    }
    a1_block_length += 1 /* 0x87 */ + 1 /* Length: 0x02 */ + 2 /* Value */;
    a1_block_length += 1 /* 0x88 */ + 1 /* Length: 0x02 */ + 2 /* Value */;
    buffer[c++] = 0xa1;
    buffer[c++] = a1_block_length;
    if (CBEFF_record_ptr->BIG_records[i]->BHT_record.patron_header_format_is_present) {
      buffer[c++] = 0x80;
      buffer[c++] = 0x02;
      buffer[c++] = CBEFF_record_ptr->BIG_records[i]->BHT_record.patron_header_format[0];
      buffer[c++] = CBEFF_record_ptr->BIG_records[i]->BHT_record.patron_header_format[1];
    }
    if (CBEFF_record_ptr->BIG_records[i]->BHT_record.biometric_type_is_present) {
      buffer[c++] = 0x81;
      buffer[c++] = CBEFF_record_ptr->BIG_records[i]->BHT_record.biometric_type_length;
      NAEEM_uint32 cc = 0;
      for (; cc < CBEFF_record_ptr->BIG_records[i]->BHT_record.biometric_type_length; cc++) {
        buffer[c++] = CBEFF_record_ptr->BIG_records[i]->BHT_record.biometric_type[cc];
      }
    }
    if (CBEFF_record_ptr->BIG_records[i]->BHT_record.biometric_subtype_is_present) {
      buffer[c++] = 0x82;
      buffer[c++] = 0x01;
      buffer[c++] = CBEFF_record_ptr->BIG_records[i]->BHT_record.biometric_subtype;
    }
    if (CBEFF_record_ptr->BIG_records[i]->BHT_record.creation_date_and_time_is_present) {
      buffer[c++] = 0x83;
      buffer[c++] = 0x07;
      NAEEM_uint32 cc = 0;
      for(; cc < 7; cc++) {
        buffer[c++] = CBEFF_record_ptr->BIG_records[i]->BHT_record.creation_date_and_time[cc];
      }
    }
    if (CBEFF_record_ptr->BIG_records[i]->BHT_record.validity_period_is_present) {
      buffer[c++] = 0x85;
      buffer[c++] = 0x08;
      NAEEM_uint32 cc = 0;
      for(; cc < 8; cc++) {
        buffer[c++] = CBEFF_record_ptr->BIG_records[i]->BHT_record.validity_period[cc];
      }
    }
    if (CBEFF_record_ptr->BIG_records[i]->BHT_record.pid_is_present) {
      buffer[c++] = 0x86;
      buffer[c++] = 0x02;
      buffer[c++] = CBEFF_record_ptr->BIG_records[i]->BHT_record.pid[0];
      buffer[c++] = CBEFF_record_ptr->BIG_records[i]->BHT_record.pid[1];
    }
    buffer[c++] = 0x87;
    buffer[c++] = 0x02;
    buffer[c++] = CBEFF_record_ptr->BIG_records[i]->BHT_record.format_owner[0];
    buffer[c++] = CBEFF_record_ptr->BIG_records[i]->BHT_record.format_owner[1];
    buffer[c++] = 0x88;
    buffer[c++] = 0x02;
    buffer[c++] = CBEFF_record_ptr->BIG_records[i]->BHT_record.format_type[0];
    buffer[c++] = CBEFF_record_ptr->BIG_records[i]->BHT_record.format_type[1];
    buffer[c++] = 0x5f;
    buffer[c++] = 0x2e;
    buffer[c++] = 0x82;
    buffer[c++] = CBEFF_record_ptr->BIG_records[i]->BDB_record_length / 256;
    buffer[c++] = CBEFF_record_ptr->BIG_records[i]->BDB_record_length % 256;
    //------------------------ BDB --------------------------------
    if (CBEFF_record_ptr->BIG_records[i]->BDB_record_type == NAEEM_BIO_BDB_TYPE_FAC) {
      NAEEM_bio__FAC_biometric_data_block_ptr FAC_biometric_data_block_ptr = 
                         (NAEEM_bio__FAC_biometric_data_block_ptr)CBEFF_record_ptr->BIG_records[i]->BDB_record;
      buffer[c++] = 0x46;
      buffer[c++] = 0x41;
      buffer[c++] = 0x43;
      buffer[c++] = 0x00;
      buffer[c++] = FAC_biometric_data_block_ptr->facial_record_header.version_number[0];
      buffer[c++] = FAC_biometric_data_block_ptr->facial_record_header.version_number[1];
      buffer[c++] = FAC_biometric_data_block_ptr->facial_record_header.version_number[2];
      buffer[c++] = FAC_biometric_data_block_ptr->facial_record_header.version_number[3];
      buffer[c++] = FAC_biometric_data_block_ptr->facial_record_header.length_of_record[0];
      buffer[c++] = FAC_biometric_data_block_ptr->facial_record_header.length_of_record[1];
      buffer[c++] = FAC_biometric_data_block_ptr->facial_record_header.length_of_record[2];
      buffer[c++] = FAC_biometric_data_block_ptr->facial_record_header.length_of_record[3];
      buffer[c++] = FAC_biometric_data_block_ptr->facial_record_header.number_of_facial_images[0];
      buffer[c++] = FAC_biometric_data_block_ptr->facial_record_header.number_of_facial_images[1];

      buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.facial_information.length_of_record[0];
      buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.facial_information.length_of_record[1];
      buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.facial_information.length_of_record[2];
      buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.facial_information.length_of_record[3];
      buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.facial_information.number_of_feature_points[0];
      buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.facial_information.number_of_feature_points[1];
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

      NAEEM_uint32 cc = 0;
      for (; cc < FAC_biometric_data_block_ptr->facial_record_data.facial_information.number_of_feature_points[0] * 256 + 
                  FAC_biometric_data_block_ptr->facial_record_data.facial_information.number_of_feature_points[1]; cc++) {
        buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.feature_points[cc].feature_point_type;
        buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.feature_points[cc].feature_point_code;
        buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.feature_points[cc].horizantal_position[0];
        buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.feature_points[cc].horizantal_position[1];
        buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.feature_points[cc].vertical_position[0];
        buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.feature_points[cc].vertical_position[1];
        buffer[c++] = 0x00;
        buffer[c++] = 0x00;
      }

      buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.image_information.face_image_type;
      buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.image_information.image_data_type;
      buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.image_information.width[0];
      buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.image_information.width[1];
      buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.image_information.height[0];
      buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.image_information.height[1];
      buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.image_information.image_color_space;
      buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.image_information.source_type;
      buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.image_information.device_type[0];
      buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.image_information.device_type[1];
      buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.image_information.quality[0];
      buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.image_information.quality[1];

      for (cc = 0; cc < FAC_biometric_data_block_ptr->facial_record_data.jpeg_image.length; cc++) {
        buffer[c++] = FAC_biometric_data_block_ptr->facial_record_data.jpeg_image.data[cc];
      }
    }
    NAEEM_test__assert(c == overal_length, "Inconsistency in bio structure.");
  }
}

