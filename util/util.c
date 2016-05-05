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

#include <string.h>

#include <org/labcrypto/abettor/util.h>


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__util__copy_array (
  ORG_LABCRYPTO_ABETTOR_data destination,
  ORG_LABCRYPTO_ABETTOR_data source,
  ORG_LABCRYPTO_ABETTOR_uint32 start_index,
  ORG_LABCRYPTO_ABETTOR_uint32 length
) {
  ORG_LABCRYPTO_ABETTOR_uint32 i = 0;
  for (; i < length; i++) {
    destination[i] = source[start_index + i];
  }
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__util__print_array (
  ORG_LABCRYPTO_ABETTOR_string title,
  ORG_LABCRYPTO_ABETTOR_data data, 
  ORG_LABCRYPTO_ABETTOR_uint32 data_length
) {
  ORG_LABCRYPTO_ABETTOR_uint32 title_length = 0;
  ORG_LABCRYPTO_ABETTOR_uint32 i = 0, j = 0;
  if (title) {
    printf("%s: ", title);
    title_length = strlen((const char*)title) + 2;
  }
  for (;i < data_length; i++) {
    printf("0x%02x ", data[i] & 0xff);
    if (((i + 1) % 8) == 0 && (i + 1) < data_length) {
      printf("\n");
      if (i + 1 < data_length) {
        for (j = 0; j < title_length; j++) {
          printf(" ");
        }
      }   
    }
  }
  printf("\n");
}


ORG_LABCRYPTO_ABETTOR_bool
ORG_LABCRYPTO_ABETTOR__util__compare_data (
  ORG_LABCRYPTO_ABETTOR_data first_data, 
  ORG_LABCRYPTO_ABETTOR_uint32 first_data_length, 
  ORG_LABCRYPTO_ABETTOR_data second_data,
  ORG_LABCRYPTO_ABETTOR_uint32 second_data_length
) {
  ORG_LABCRYPTO_ABETTOR_uint32 i = 0;
  if (first_data_length != second_data_length) {
    return FALSE;
  }
  for (; i < first_data_length; i++) {
    if (first_data[i] != second_data[i]) {
      return FALSE;
    }
  }
  return TRUE;
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__util__concat_data (
  ORG_LABCRYPTO_ABETTOR_data destination,
  ORG_LABCRYPTO_ABETTOR_uint32 start_index,           
  ORG_LABCRYPTO_ABETTOR_data source,
  ORG_LABCRYPTO_ABETTOR_uint32 source_length
) {
  ORG_LABCRYPTO_ABETTOR_uint32 i = 0;
  for (; i < source_length; i++) {
    destination[i + start_index] = source[i];
  }  
}


ORG_LABCRYPTO_ABETTOR_string
ORG_LABCRYPTO_ABETTOR__util__trim_string (
  ORG_LABCRYPTO_ABETTOR_string str
) {
  ORG_LABCRYPTO_ABETTOR_char *end;
  while (*str == ' ' || *str == '\t' || *str == '\r' || *str == '\n') {
    str++;
  }
  if(*str == 0) {
    return str;
  }
  end = str + strlen((const char*)str) - 1;
  while (end > str && 
         (*end == ' ' || *end == '\t' || *end == '\r' || *end == '\n')) {
    end--;
  }
  *(end + 1) = 0;
  return str;
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__util__xor (
  ORG_LABCRYPTO_ABETTOR_data destination,    
  ORG_LABCRYPTO_ABETTOR_uint32 destination_length,                      
  ORG_LABCRYPTO_ABETTOR_data source
) {
  ORG_LABCRYPTO_ABETTOR_uint32 i = 0;
  for (; i < destination_length; i++) {
    destination[i] = destination[i] ^ source[i];
  }
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__util__increment (
  ORG_LABCRYPTO_ABETTOR_data number,
  ORG_LABCRYPTO_ABETTOR_uint32 number_length
) {
  ORG_LABCRYPTO_ABETTOR_uint32 i = number_length - 1;
  for (; i >= 0; i--) {
    if (number[i] == 255) {
      number[i] = 0;
    } else {
      number[i]++;
      break;
    }
  }
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__util__make_zero (
  ORG_LABCRYPTO_ABETTOR_data buffer,
  ORG_LABCRYPTO_ABETTOR_uint32 buffer_length
) {
  ORG_LABCRYPTO_ABETTOR_uint32 i = 0;
  for (i = 0; i < buffer_length; i++) {
    buffer[i] = 0x00;
  }
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__util__pad (
  ORG_LABCRYPTO_ABETTOR_data buffer,
  ORG_LABCRYPTO_ABETTOR_uint32 buffer_length,
  ORG_LABCRYPTO_ABETTOR_data_ptr padded_buffer,
  ORG_LABCRYPTO_ABETTOR_uint32_ptr padded_buffer_length
) {
  ORG_LABCRYPTO_ABETTOR_uint32 i = 0;
  ORG_LABCRYPTO_ABETTOR_uint32 new_length = (buffer_length % 8) == 0 ? buffer_length + 8 : ((buffer_length / 8) + 1) * 8;
  *padded_buffer = (ORG_LABCRYPTO_ABETTOR_data)malloc(new_length * sizeof(ORG_LABCRYPTO_ABETTOR_byte));
  ORG_LABCRYPTO_ABETTOR__util__make_zero(*padded_buffer, new_length);
  
  for (; i < buffer_length; i++) {
    (*padded_buffer)[i] = buffer[i];
  }
  (*padded_buffer)[i] = 0x80;
  if (padded_buffer_length) {
    *padded_buffer_length = new_length;
  }
}


ORG_LABCRYPTO_ABETTOR_string
ORG_LABCRYPTO_ABETTOR__util__array_to_string (
  ORG_LABCRYPTO_ABETTOR_data array, 
  ORG_LABCRYPTO_ABETTOR_uint32 length
) {
  ORG_LABCRYPTO_ABETTOR_char temp[3];
  ORG_LABCRYPTO_ABETTOR_uint32 i = 0;
  ORG_LABCRYPTO_ABETTOR_string result = (ORG_LABCRYPTO_ABETTOR_string)malloc((2 * length + 1) * sizeof(ORG_LABCRYPTO_ABETTOR_char));
  strcpy(result, "");
  for (; i < length; i++) {
    sprintf(temp, "%02x", array[i]);
    strcat(result, temp);
  }
  return result;
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__util__to_upper(
  ORG_LABCRYPTO_ABETTOR_string str
) {
  ORG_LABCRYPTO_ABETTOR_uint32 i = 0;
  for (; i < strlen(str); i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      str[i] = str[i] - 32;
    }
  }
}