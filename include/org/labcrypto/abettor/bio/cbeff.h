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

#ifndef _ORG_LABCRYPTO_ABETTOR__C__BIO__CBEFF_H_
#define _ORG_LABCRYPTO_ABETTOR__C__BIO__CBEFF_H_

#include <org/labcrypto/abettor/types.h>


#ifdef __cplusplus
extern "C" {
#endif


#define ORG_LABCRYPTO_ABETTOR__BIO__CBEFF__BIOMETRIC_INFORMATION_GROUP_TEMPLATE_TAG                          0x7f61
#define ORG_LABCRYPTO_ABETTOR__BIO__CBEFF__BIOMETRIC_INFORMATION_GROUP_TEMPLATE_NUM_OF_INSTANCES_TAG         0x02
#define ORG_LABCRYPTO_ABETTOR__BIO__CBEFF__BIOMETRIC_INFORMATION_TEMPLATE_TAG                                0x7f60
#define ORG_LABCRYPTO_ABETTOR__BIO__CBEFF__BIOMETRIC_HEADER_TEMPLATE_TAG                                     0xa1
#define ORG_LABCRYPTO_ABETTOR__BIO__CBEFF__BIOMETRIC_HEADER_TEMPLATE_PATRON_HEADER_FORMAT_TAG                0x80
#define ORG_LABCRYPTO_ABETTOR__BIO__CBEFF__BIOMETRIC_HEADER_TEMPLATE_BIOMETRIC_TYPE_TAG                      0x81
#define ORG_LABCRYPTO_ABETTOR__BIO__CBEFF__BIOMETRIC_HEADER_TEMPLATE_BIOMETRIC_SUBTYPE_TAG                   0x82
#define ORG_LABCRYPTO_ABETTOR__BIO__CBEFF__BIOMETRIC_HEADER_TEMPLATE_CREATION_DATE_AND_TIME_TAG              0x83
#define ORG_LABCRYPTO_ABETTOR__BIO__CBEFF__BIOMETRIC_HEADER_TEMPLATE_VALIDITY_PERIOD_TAG                     0x85
#define ORG_LABCRYPTO_ABETTOR__BIO__CBEFF__BIOMETRIC_HEADER_TEMPLATE_PID_TAG                                 0x86
#define ORG_LABCRYPTO_ABETTOR__BIO__CBEFF__BIOMETRIC_HEADER_TEMPLATE_FORMAT_OWNER_TAG                        0x87
#define ORG_LABCRYPTO_ABETTOR__BIO__CBEFF__BIOMETRIC_HEADER_TEMPLATE_FORMAT_TYPE_TAG                         0x88
#define ORG_LABCRYPTO_ABETTOR__BIO__CBEFF__BIOMETRIC_DATA_BLOCK_TAG                                          0x5f2e

#define ORG_LABCRYPTO_ABETTOR__BIO__CBEFF__BDB_RECORD_TYPE__FAC                                              0x00000001
#define ORG_LABCRYPTO_ABETTOR__BIO__CBEFF__BDB_RECORD_TYPE__FIR                                              0x00000002

#define ORG_LABCRYPTO_ABETTOR__BIO__CBEFF__BIOMETRIC_TYPE__FACIAL_FEATURES                                   0x02
#define ORG_LABCRYPTO_ABETTOR__BIO__CBEFF__BIOMETRIC_TYPE__FINGERPRINT                                       0x08
#define ORG_LABCRYPTO_ABETTOR__BIO__CBEFF__BIOMETRIC_TYPE__IRIS                                              0x10

#define ORG_LABCRYPTO_ABETTOR__BIO__CBEFF__BIOMETRIC_SUBTYPE__NO_INFORMATION_GIVEN                           0x00


typedef struct {
  ORG_LABCRYPTO_ABETTOR_byte patron_header_format[2];
  ORG_LABCRYPTO_ABETTOR_bool patron_header_format_is_present;
  ORG_LABCRYPTO_ABETTOR_data biometric_type;
  ORG_LABCRYPTO_ABETTOR_uint32 biometric_type_length;
  ORG_LABCRYPTO_ABETTOR_bool biometric_type_is_present;
  ORG_LABCRYPTO_ABETTOR_byte biometric_subtype;
  ORG_LABCRYPTO_ABETTOR_bool biometric_subtype_is_present;
  ORG_LABCRYPTO_ABETTOR_byte creation_date_and_time[7];
  ORG_LABCRYPTO_ABETTOR_bool creation_date_and_time_is_present;
  ORG_LABCRYPTO_ABETTOR_byte validity_period[8];
  ORG_LABCRYPTO_ABETTOR_bool validity_period_is_present;
  ORG_LABCRYPTO_ABETTOR_byte pid[2];
  ORG_LABCRYPTO_ABETTOR_bool pid_is_present;
  ORG_LABCRYPTO_ABETTOR_byte format_owner[2];
  ORG_LABCRYPTO_ABETTOR_byte format_type[2];
} ORG_LABCRYPTO_ABETTOR__bio__biometric_header_template;
typedef ORG_LABCRYPTO_ABETTOR__bio__biometric_header_template PTR   ORG_LABCRYPTO_ABETTOR__bio__biometric_header_template_ptr;


typedef struct {
  ORG_LABCRYPTO_ABETTOR__bio__biometric_header_template BHT_record;
  ORG_LABCRYPTO_ABETTOR_data BDB_record;
  ORG_LABCRYPTO_ABETTOR_uint32 BDB_record_type;
  ORG_LABCRYPTO_ABETTOR_uint32 BDB_record_length;
} ORG_LABCRYPTO_ABETTOR__bio__biometric_information_group_template;
typedef ORG_LABCRYPTO_ABETTOR__bio__biometric_information_group_template PTR   ORG_LABCRYPTO_ABETTOR__bio__biometric_information_group_template_ptr;
typedef ORG_LABCRYPTO_ABETTOR__bio__biometric_information_group_template_ptr PTR   ORG_LABCRYPTO_ABETTOR__bio__biometric_information_group_template_ptr_ptr;


typedef struct {
  ORG_LABCRYPTO_ABETTOR__bio__biometric_information_group_template_ptr_ptr BIG_records;   
  ORG_LABCRYPTO_ABETTOR_uint32 BIG_records_length; 
} ORG_LABCRYPTO_ABETTOR__bio__CBEFF_template;
typedef ORG_LABCRYPTO_ABETTOR__bio__CBEFF_template PTR   ORG_LABCRYPTO_ABETTOR__bio__CBEFF_template_ptr;


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__bio__create_CBEFF_template_from_serialized_FAC_BDB (
  ORG_LABCRYPTO_ABETTOR_data /* FAC BDB serialized data */,
  ORG_LABCRYPTO_ABETTOR_uint32 /* FAC BDB serialized data length */,
  ORG_LABCRYPTO_ABETTOR__bio__CBEFF_template_ptr /* Pointer to CBEFF record */
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__bio__create_CBEFF_template_from_serialized_FIR_BDB (
  ORG_LABCRYPTO_ABETTOR_data /* FIR BDB serialized data */,
  ORG_LABCRYPTO_ABETTOR_uint32 /* FIR BDB serialized data length */,
  ORG_LABCRYPTO_ABETTOR__bio__CBEFF_template_ptr /* Pointer to CBEFF record */
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__bio__extract_BDB_data_from_CBEFF_template (
  ORG_LABCRYPTO_ABETTOR__bio__CBEFF_template_ptr /* Pointer to CBEFF record */,
  ORG_LABCRYPTO_ABETTOR_data_ptr /* Pointer to buffer */,
  ORG_LABCRYPTO_ABETTOR_uint32_ptr /* Pointer to buffer length */
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__bio__serialize_CBEFF_template (
  ORG_LABCRYPTO_ABETTOR__bio__CBEFF_template_ptr /* Pointer to CBEFF record */,
  ORG_LABCRYPTO_ABETTOR_data_ptr /* Pointer to target data buffer */,
  ORG_LABCRYPTO_ABETTOR_uint32_ptr /* Pointer to target data buffer length */
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__bio__deserialize_CBEFF_template (
  ORG_LABCRYPTO_ABETTOR_data /* Data buffer */,
  ORG_LABCRYPTO_ABETTOR_uint32 /* Data buffer length */,
  ORG_LABCRYPTO_ABETTOR__bio__CBEFF_template_ptr /* Pointer to CBEFF record */
);


#ifdef __cplusplus
}
#endif

#endif