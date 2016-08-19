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
#include <org/labcrypto/abettor/bio/cbeff.h>
#include <org/labcrypto/abettor/bio/face.h>
#include <org/labcrypto/abettor/bio/finger.h>


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__bio__create_CBEFF_template_from_serialized_FAC_BDB (
  ORG_LABCRYPTO_ABETTOR_data buffer,
  ORG_LABCRYPTO_ABETTOR_uint32 buffer_length,
  ORG_LABCRYPTO_ABETTOR__bio__CBEFF_template_ptr CBEFF_template_ptr
) {
  ORG_LABCRYPTO_ABETTOR__bio__biometric_information_group_template_ptr BIG_record_ptr;
  BIG_record_ptr = (ORG_LABCRYPTO_ABETTOR__bio__biometric_information_group_template_ptr)malloc(
    sizeof(ORG_LABCRYPTO_ABETTOR__bio__biometric_information_group_template));

  BIG_record_ptr->BHT_record.patron_header_format_is_present = FALSE;
  BIG_record_ptr->BHT_record.biometric_type_is_present = TRUE;
  BIG_record_ptr->BHT_record.biometric_subtype_is_present = TRUE;
  BIG_record_ptr->BHT_record.creation_date_and_time_is_present = FALSE;
  BIG_record_ptr->BHT_record.validity_period_is_present = FALSE;
  BIG_record_ptr->BHT_record.pid_is_present = FALSE;
  BIG_record_ptr->BHT_record.biometric_type = malloc(sizeof(ORG_LABCRYPTO_ABETTOR_byte));
  BIG_record_ptr->BHT_record.biometric_type[0] = ORG_LABCRYPTO_ABETTOR__BIO__CBEFF__BIOMETRIC_TYPE__FACIAL_FEATURES;
  BIG_record_ptr->BHT_record.biometric_type_length = 1;
  BIG_record_ptr->BHT_record.biometric_subtype = ORG_LABCRYPTO_ABETTOR__BIO__CBEFF__BIOMETRIC_SUBTYPE__NO_INFORMATION_GIVEN;
  BIG_record_ptr->BHT_record.format_owner[0] = 0x01;
  BIG_record_ptr->BHT_record.format_owner[1] = 0x01;
  BIG_record_ptr->BHT_record.format_type[0] = 0x00;
  BIG_record_ptr->BHT_record.format_type[1] = 0x08;
  BIG_record_ptr->BDB_record = buffer;
  BIG_record_ptr->BDB_record_type = ORG_LABCRYPTO_ABETTOR__BIO__CBEFF__BDB_RECORD_TYPE__FAC;
  BIG_record_ptr->BDB_record_length = buffer_length;

  CBEFF_template_ptr->BIG_records = (ORG_LABCRYPTO_ABETTOR__bio__biometric_information_group_template_ptr_ptr)malloc(
                                            sizeof(ORG_LABCRYPTO_ABETTOR__bio__biometric_information_group_template_ptr));

  CBEFF_template_ptr->BIG_records_length = 1;
  CBEFF_template_ptr->BIG_records[0] = BIG_record_ptr;
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__bio__create_CBEFF_template_from_serialized_FIR_BDB (
  ORG_LABCRYPTO_ABETTOR_data buffer,
  ORG_LABCRYPTO_ABETTOR_uint32 buffer_length,
  ORG_LABCRYPTO_ABETTOR__bio__CBEFF_template_ptr CBEFF_template_ptr
) {
  // TODO
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__bio__extract_BDB_data_from_CBEFF_template (
  ORG_LABCRYPTO_ABETTOR__bio__CBEFF_template_ptr CBEFF_template_ptr,
  ORG_LABCRYPTO_ABETTOR_data_ptr buffer_ptr,
  ORG_LABCRYPTO_ABETTOR_uint32_ptr buffer_length_ptr
) {
  // TODO
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__bio__serialize_CBEFF_template (
  ORG_LABCRYPTO_ABETTOR__bio__CBEFF_template_ptr CBEFF_template_ptr,
  ORG_LABCRYPTO_ABETTOR_data_ptr buffer_ptr,
  ORG_LABCRYPTO_ABETTOR_uint32_ptr buffer_length_ptr
) {
  ORG_LABCRYPTO_ABETTOR_uint32 i = 0, j = 0;
  ORG_LABCRYPTO_ABETTOR_uint32 c = 0, cc = 0;
  ORG_LABCRYPTO_ABETTOR_data buffer;
  ORG_LABCRYPTO_ABETTOR_uint32 a1_block_length;
  ORG_LABCRYPTO_ABETTOR_uint32 overal_length = 2 /* 0x76f1 */ + 3 /* Length */;
  overal_length += 1 /* 0x02 */ + 1 /* Length: 0x01 */ + 1 /* Value */;
  for (i = 0; i < CBEFF_template_ptr->BIG_records_length; i++) {
    overal_length += 2 /* 0x7f60 */ + 3 /* Length */;
    overal_length += 1 /* 0xa1 */ + 1 /* Length */;
    if (CBEFF_template_ptr->BIG_records[i]->BHT_record.patron_header_format_is_present) {
      overal_length += 1 /* 0x80 */ + 1 /* Length: 0x02 */ + 2 /* Value */;
    }
    if (CBEFF_template_ptr->BIG_records[i]->BHT_record.biometric_type_is_present) {
      overal_length += 1 /* 0x81 */ + 1 /* Length */ + 
                       CBEFF_template_ptr->BIG_records[i]->BHT_record.biometric_type_length /* Value */;
    }
    if (CBEFF_template_ptr->BIG_records[i]->BHT_record.biometric_subtype_is_present) {
      overal_length += 1 /* 0x82 */ + 1 /* Length: 0x01 */ + 1 /* Value */;
    }
    if (CBEFF_template_ptr->BIG_records[i]->BHT_record.creation_date_and_time_is_present) {
      overal_length += 1 /* 0x83 */ + 1 /* Length: 0x07 */ + 7 /* Value */;
    }
    if (CBEFF_template_ptr->BIG_records[i]->BHT_record.validity_period_is_present) {
      overal_length += 1 /* 0x85 */ + 1 /* Length: 0x08 */ + 8 /* Value */;
    }
    if (CBEFF_template_ptr->BIG_records[i]->BHT_record.pid_is_present) {
      overal_length += 1 /* 0x86 */ + 1 /* Length: 0x02 */ + 2 /* Value */;
    }
    overal_length += 1 /* 0x87 */ + 1 /* Length: 0x02 */ + 2 /* Value */;
    overal_length += 1 /* 0x88 */ + 1 /* Length: 0x02 */ + 2 /* Value */;
    overal_length += 2 /* 0x5f2e */ + 3 /* Length */;
    overal_length += CBEFF_template_ptr->BIG_records[i]->BDB_record_length;
  }
  *buffer_length_ptr = overal_length;
  buffer = *buffer_ptr = (ORG_LABCRYPTO_ABETTOR_data)malloc(overal_length * sizeof(ORG_LABCRYPTO_ABETTOR_byte));
  c = 0;
  buffer[c++] = 0x7f;
  buffer[c++] = 0x61;
  buffer[c++] = 0x82;
  buffer[c] = (overal_length - (c + 2)) / 256;
  c++;
  buffer[c] = (overal_length - (c + 1)) % 256;
  c++;
  buffer[c++] = 0x02;
  buffer[c++] = 0x01;
  buffer[c++] = CBEFF_template_ptr->BIG_records_length;
  for (i = 0; i < CBEFF_template_ptr->BIG_records_length; i++) {
    buffer[c++] = 0x7f;
    buffer[c++] = 0x60;
    buffer[c++] = 0x82;
    buffer[c] = (overal_length - (c + 2)) / 256;
    c++;
    buffer[c] = (overal_length - (c + 1)) % 256;
    c++;
    a1_block_length = 0;
    if (CBEFF_template_ptr->BIG_records[i]->BHT_record.patron_header_format_is_present) {
      a1_block_length += 1 /* 0x80 */ + 1 /* Length: 0x02 */ + 2 /* Value */;
    }
    if (CBEFF_template_ptr->BIG_records[i]->BHT_record.biometric_type_is_present) {
      a1_block_length += 1 /* 0x81 */ + 1 /* Length */ + 
                       CBEFF_template_ptr->BIG_records[i]->BHT_record.biometric_type_length /* Value */;
    }
    if (CBEFF_template_ptr->BIG_records[i]->BHT_record.biometric_subtype_is_present) {
      a1_block_length += 1 /* 0x82 */ + 1 /* Length: 0x01 */ + 1 /* Value */;
    }
    if (CBEFF_template_ptr->BIG_records[i]->BHT_record.creation_date_and_time_is_present) {
      a1_block_length += 1 /* 0x83 */ + 1 /* Length: 0x07 */ + 7 /* Value */;
    }
    if (CBEFF_template_ptr->BIG_records[i]->BHT_record.validity_period_is_present) {
      a1_block_length += 1 /* 0x85 */ + 1 /* Length: 0x08 */ + 8 /* Value */;
    }
    if (CBEFF_template_ptr->BIG_records[i]->BHT_record.pid_is_present) {
      a1_block_length += 1 /* 0x86 */ + 1 /* Length: 0x02 */ + 2 /* Value */;
    }
    a1_block_length += 1 /* 0x87 */ + 1 /* Length: 0x02 */ + 2 /* Value */;
    a1_block_length += 1 /* 0x88 */ + 1 /* Length: 0x02 */ + 2 /* Value */;
    buffer[c++] = 0xa1;
    buffer[c++] = a1_block_length;
    if (CBEFF_template_ptr->BIG_records[i]->BHT_record.patron_header_format_is_present) {
      buffer[c++] = 0x80;
      buffer[c++] = 0x02;
      buffer[c++] = CBEFF_template_ptr->BIG_records[i]->BHT_record.patron_header_format[0];
      buffer[c++] = CBEFF_template_ptr->BIG_records[i]->BHT_record.patron_header_format[1];
    }
    if (CBEFF_template_ptr->BIG_records[i]->BHT_record.biometric_type_is_present) {
      buffer[c++] = 0x81;
      buffer[c++] = CBEFF_template_ptr->BIG_records[i]->BHT_record.biometric_type_length;
      cc = 0;
      for (; cc < CBEFF_template_ptr->BIG_records[i]->BHT_record.biometric_type_length; cc++) {
        buffer[c++] = CBEFF_template_ptr->BIG_records[i]->BHT_record.biometric_type[cc];
      }
    }
    if (CBEFF_template_ptr->BIG_records[i]->BHT_record.biometric_subtype_is_present) {
      buffer[c++] = 0x82;
      buffer[c++] = 0x01;
      buffer[c++] = CBEFF_template_ptr->BIG_records[i]->BHT_record.biometric_subtype;
    }
    if (CBEFF_template_ptr->BIG_records[i]->BHT_record.creation_date_and_time_is_present) {
      buffer[c++] = 0x83;
      buffer[c++] = 0x07;
      cc = 0;
      for(; cc < 7; cc++) {
        buffer[c++] = CBEFF_template_ptr->BIG_records[i]->BHT_record.creation_date_and_time[cc];
      }
    }
    if (CBEFF_template_ptr->BIG_records[i]->BHT_record.validity_period_is_present) {
      buffer[c++] = 0x85;
      buffer[c++] = 0x08;
      cc = 0;
      for(; cc < 8; cc++) {
        buffer[c++] = CBEFF_template_ptr->BIG_records[i]->BHT_record.validity_period[cc];
      }
    }
    if (CBEFF_template_ptr->BIG_records[i]->BHT_record.pid_is_present) {
      buffer[c++] = 0x86;
      buffer[c++] = 0x02;
      buffer[c++] = CBEFF_template_ptr->BIG_records[i]->BHT_record.pid[0];
      buffer[c++] = CBEFF_template_ptr->BIG_records[i]->BHT_record.pid[1];
    }
    buffer[c++] = 0x87;
    buffer[c++] = 0x02;
    buffer[c++] = CBEFF_template_ptr->BIG_records[i]->BHT_record.format_owner[0];
    buffer[c++] = CBEFF_template_ptr->BIG_records[i]->BHT_record.format_owner[1];
    buffer[c++] = 0x88;
    buffer[c++] = 0x02;
    buffer[c++] = CBEFF_template_ptr->BIG_records[i]->BHT_record.format_type[0];
    buffer[c++] = CBEFF_template_ptr->BIG_records[i]->BHT_record.format_type[1];
    buffer[c++] = 0x5f;
    buffer[c++] = 0x2e;
    buffer[c++] = 0x82;
    buffer[c++] = CBEFF_template_ptr->BIG_records[i]->BDB_record_length / 256;
    buffer[c++] = CBEFF_template_ptr->BIG_records[i]->BDB_record_length % 256;
    //------------------------ BDB --------------------------------
    for (j = 0; j < CBEFF_template_ptr->BIG_records[i]->BDB_record_length; j++) {
      buffer[c++] = CBEFF_template_ptr->BIG_records[i]->BDB_record[j];
    }
    ORG_LABCRYPTO_ABETTOR__test__assert(c == overal_length, "ORG_LABCRYPTO_ABETTOR__bio__serialize_CBEFF_template: Inconsistency in bio structure.");
  }
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__bio__deserialize_CBEFF_template (
  ORG_LABCRYPTO_ABETTOR_data buffer,
  ORG_LABCRYPTO_ABETTOR_uint32 buffer_length,
  ORG_LABCRYPTO_ABETTOR__bio__CBEFF_template_ptr CBEFF_template_ptr
) {
  // TODO
}

