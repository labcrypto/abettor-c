#ifndef _NAEEM_CORELIBS__BIO_H_
#define _NAEEM_CORELIBS__BIO_H_

#include <naeem/types.h>


#ifdef __cplusplus
extern "C" {
#endif


#define NAEEM_BIO_BIOMETRIC_INFORMATION_GROUP_TEMPLATE_TAG                          0x7f61
#define NAEEM_BIO_BIOMETRIC_INFORMATION_GROUP_TEMPLATE_NUM_OF_INSTANCES_TAG         0x02
#define NAEEM_BIO_BIOMETRIC_INFORMATION_TEMPLATE_TAG                                0x7f60
#define NAEEM_BIO_BIOMETRIC_HEADER_TEMPLATE_TAG                                     0xa1
#define NAEEM_BIO_BIOMETRIC_HEADER_TEMPLATE_PATRON_HEADER_FORMAT_TAG                0x80
#define NAEEM_BIO_BIOMETRIC_HEADER_TEMPLATE_BIOMETRIC_TYPE_TAG                      0x81
#define NAEEM_BIO_BIOMETRIC_HEADER_TEMPLATE_BIOMETRIC_SUBTYPE_TAG                   0x82
#define NAEEM_BIO_BIOMETRIC_HEADER_TEMPLATE_CREATION_DATE_AND_TIME_TAG              0x83
#define NAEEM_BIO_BIOMETRIC_HEADER_TEMPLATE_VALIDITY_PERIOD_TAG                     0x85
#define NAEEM_BIO_BIOMETRIC_HEADER_TEMPLATE_PID_TAG                                 0x86
#define NAEEM_BIO_BIOMETRIC_HEADER_TEMPLATE_FORMAT_OWNER_TAG                        0x87
#define NAEEM_BIO_BIOMETRIC_HEADER_TEMPLATE_FORMAT_TYPE_TAG                         0x88
#define NAEEM_BIO_BIOMETRIC_DATA_BLOCK_TAG                                          0x5f2e


#define NAEEM_BIO_JPEG_TYPE_JPEG_2000                                               0x00000100
#define NAEEM_BIO_JPEG_TYPE_JPEG_JFIF                                               0x00000101


#define NAEEM_BIO_BDB_TYPE_FAC                                                      0x00000001


typedef struct {
  NAEEM_data                                         data;
  NAEEM_uint32                                       length;
  NAEEM_uint32                                       type;
} NAEEM_bio__JPEG_image;
typedef NAEEM_bio__JPEG_image PTR   NAEEM__bio_JPEG_image_ptr;


typedef struct {
  NAEEM_byte                                        face_image_type;
  NAEEM_byte                                        image_data_type;
  NAEEM_byte                                        width[2];
  NAEEM_byte                                        height[2];
  NAEEM_byte                                        image_color_space;
  NAEEM_byte                                        source_type;
  NAEEM_byte                                        device_type[2];
  NAEEM_byte                                        quality[2];
} NAEEM_bio__image_information;
typedef NAEEM_bio__image_information PTR   NAEEM_bio__image_information_ptr;


typedef struct {
  NAEEM_byte                                        feature_point_type;
  NAEEM_byte                                        feature_point_code;
  NAEEM_byte                                        horizantal_position[2];
  NAEEM_byte                                        vertical_position[2];
} NAEEM_bio__feature_point;
typedef NAEEM_bio__feature_point PTR   NAEEM_bio__feature_point_ptr;


typedef struct {
  NAEEM_byte                                        length_of_record[4];
  NAEEM_byte                                        number_of_feature_points[2];
  NAEEM_byte                                        gender;
  NAEEM_byte                                        eye_color;
  NAEEM_byte                                        hair_color;
  NAEEM_byte                                        property_mask[3];
  NAEEM_byte                                        expression[2];
  NAEEM_byte                                        pose_angle[3];
  NAEEM_byte                                        pose_angle_uncertainty[3];
} NAEEM_bio__facial_information;
typedef NAEEM_bio__facial_information PTR   NAEEM_bio__facial_information_ptr;


typedef struct {
  NAEEM_bio__facial_information                      facial_information;
  NAEEM_bio__feature_point_ptr                       feature_points;
  NAEEM_bio__image_information                       image_information;
  NAEEM_bio__JPEG_image                              jpeg_image;
} NAEEM_bio__facial_record_data;
typedef NAEEM_bio__facial_record_data PTR   NAEEM_bio_facial__record_data_ptr;


typedef struct {
  NAEEM_byte                                         version_number[4];
  NAEEM_byte                                         length_of_record[4];
  NAEEM_byte                                         number_of_facial_images[2];
} NAEEM_bio__facial_record_header;
typedef NAEEM_bio__facial_record_header PTR   NAEEM_bio__facial_record_header_ptr;


typedef struct {
  NAEEM_bio__facial_record_header                         facial_record_header;
  NAEEM_bio__facial_record_data                           facial_record_data;                          
} NAEEM_bio__FAC_biometric_data_block;
typedef NAEEM_bio__FAC_biometric_data_block PTR    NAEEM_bio__FAC_biometric_data_block_ptr;


typedef struct {
  NAEEM_byte                                         patron_header_format[2];
  NAEEM_bool                                         patron_header_format_is_present;
  NAEEM_data                                         biometric_type;
  NAEEM_uint32                                       biometric_type_length;
  NAEEM_bool                                         biometric_type_is_present;
  NAEEM_byte                                         biometric_subtype;
  NAEEM_bool                                         biometric_subtype_is_present;
  NAEEM_byte                                         creation_date_and_time[7];
  NAEEM_bool                                         creation_date_and_time_is_present;
  NAEEM_byte                                         validity_period[8];
  NAEEM_bool                                         validity_period_is_present;
  NAEEM_byte                                         pid[2];
  NAEEM_bool                                         pid_is_present;
  NAEEM_byte                                         format_owner[2];
  NAEEM_byte                                         format_type[2];
} NAEEM_bio__biometric_header_template;
typedef NAEEM_bio__biometric_header_template PTR   NAEEM_bio__biometric_header_template_ptr;


typedef struct {
  NAEEM_bio__biometric_header_template                BHT_record;
  NAEEM_data                                         BDB_record;
  NAEEM_uint32                                       BDB_record_type;
  NAEEM_uint32                                       BDB_record_length;
} NAEEM_bio__biometric_information_group_template;
typedef NAEEM_bio__biometric_information_group_template PTR   NAEEM_bio__biometric_information_group_template_ptr;
typedef NAEEM_bio__biometric_information_group_template_ptr PTR   NAEEM_bio__biometric_information_group_template_ptr_ptr;

typedef struct {
  NAEEM_bio__biometric_information_group_template_ptr_ptr   BIG_records;   
  NAEEM_uint32                                             BIG_records_length; 
} NAEEM_bio__CBEFF_template;
typedef NAEEM_bio__CBEFF_template PTR   NAEEM_bio__CBEFF_template_ptr;


NAEEM_void
NAEEM_bio__create_CBEFF_record_from_facial_image_data (NAEEM_data                       /* Image data */,
                                                       NAEEM_uint32                     /* Image data length */,
                                                       NAEEM_pixel                      /* Width */,
                                                       NAEEM_pixel                      /* Height */,
                                                       NAEEM_bio__CBEFF_template_ptr    /* Pointer to CBEFF record */);


NAEEM_void
NAEEM_bio__get_CBEFF_data (NAEEM_bio__CBEFF_template_ptr     /* Pointer to CBEFF record */,
                           NAEEM_data_ptr                    /* Pointer to CBEFF data buffer */,
                           NAEEM_uint32_ptr                  /* Pointer to CBEFF data buffer length */);


#ifdef __cplusplus
}
#endif

#endif