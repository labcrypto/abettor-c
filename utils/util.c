#include <string.h>

#include <naeem/util.h>


NAEEM_void
NAEEM_util_copy_array (NAEEM_data destination,
                       NAEEM_data source,
                       NAEEM_uint32 start_index,
                       NAEEM_uint32 length) {
  NAEEM_uint32 i = 0;
  for (; i < length; i++) {
    destination[i] = source[start_index + i];
  }
}


NAEEM_void
NAEEM_util_print_array (NAEEM_string title,
                        NAEEM_data data, 
                        NAEEM_uint32 data_length) {
  NAEEM_uint32 title_length = 0;
  if (title) {
    printf("%s: ", title);
    title_length = strlen((const char*)title) + 2;
  }
  NAEEM_uint32 i = 0, j = 0;
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


NAEEM_bool
NAEEM_util_compare_data (NAEEM_data first_data, 
                         NAEEM_uint32 first_data_length, 
                         NAEEM_data second_data,
                         NAEEM_uint32 second_data_length) {
  if (first_data_length != second_data_length) {
    return FALSE;
  }
  NAEEM_uint32 i = 0;
  for (; i < first_data_length; i++) {
    if (first_data[i] != second_data[i]) {
      return FALSE;
    }
  }
  return TRUE;
}


NAEEM_void
NAEEM_util_concat_data (NAEEM_data destination,
                        NAEEM_uint32 start_index,           
                        NAEEM_data source,
                        NAEEM_uint32 source_length) {
  NAEEM_uint32 i = 0;
  for (; i < source_length; i++) {
    destination[i + start_index] = source[i];
  }  
}


NAEEM_string
NAEEM_util_trim_string (NAEEM_string str) {
  NAEEM_char *end;
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


NAEEM_void
NAEEM_util_xor (NAEEM_data destination,    
                NAEEM_uint32 destination_length,                      
                NAEEM_data source) {
  NAEEM_uint32 i = 0;
  for (; i < destination_length; i++) {
    destination[i] = destination[i] ^ source[i];
  }
}


NAEEM_void
NAEEM_util_increment (NAEEM_data number,
                      NAEEM_uint32 number_length) {
  NAEEM_uint32 i = number_length - 1;
  for (; i >= 0; i--) {
    if (number[i] == 255) {
      number[i] = 0;
    } else {
      number[i]++;
      break;
    }
  }
}


NAEEM_void
NAEEM_util_make_zero (NAEEM_data buffer,
                      NAEEM_uint32 buffer_length) {
  NAEEM_uint32 i = 0;
  for (i = 0; i < buffer_length; i++) {
    buffer[i] = 0x00;
  }
}


NAEEM_void
NAEEM_util_pad (NAEEM_data buffer,
                NAEEM_uint32 buffer_length,
                NAEEM_data_ptr padded_buffer,
                NAEEM_uint32_ptr padded_buffer_length) {
  NAEEM_uint32 new_length = (buffer_length % 8) == 0 ? buffer_length + 8 : ((buffer_length / 8) + 1) * 8;
  *padded_buffer = (NAEEM_data)malloc(new_length * sizeof(NAEEM_byte));
  NAEEM_util_make_zero(*padded_buffer, new_length);
  NAEEM_uint32 i = 0;
  for (; i < buffer_length; i++) {
    (*padded_buffer)[i] = buffer[i];
  }
  (*padded_buffer)[i] = 0x80;
  if (padded_buffer_length) {
    *padded_buffer_length = new_length;
  }
}
