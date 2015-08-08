#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <naeem/os.h>


NAEEM_void
NAEEM_os__read_file (FILE *fd, 
                     NAEEM_data_ptr data, 
                     NAEEM_uint32_ptr data_length) {
  NAEEM_uint32 current_limit = 128;
  *data_length = 0;
  *data = (NAEEM_data)malloc(current_limit * sizeof(NAEEM_byte));
  NAEEM_uint32 buffer_size = 64;
  NAEEM_data buffer = (NAEEM_data)malloc(buffer_size * sizeof(NAEEM_byte));
  NAEEM_uint32 j = 0, i = 0;
  NAEEM_uint32 n = 0;
  while (1) {
    n = fread(buffer, sizeof(NAEEM_byte), buffer_size, fd);
    if (n == 0) {
      break;
    }
    if (*data_length + n > current_limit) {
      NAEEM_uint32 old_limit = current_limit;
      current_limit += (NAEEM_uint32)(current_limit * 1.5);
      NAEEM_data temp = *data;
      *data = (NAEEM_data)malloc(current_limit * sizeof(NAEEM_char));
      for (i = 0; i < old_limit; i++) {
        (*data)[i] = temp[i];
      }
      free(temp);
    }
    *data_length += n;
    for(i = 0; i < n; i++) {
      (*data)[j] = buffer[i];
      j++;
    }
  }
  if (j != *data_length) {
    printf("Error in reading from pipe\r\n");
    exit(1);
  }
}


NAEEM_void
NAEEM_os__read_file2 (NAEEM_path file_path, 
                      NAEEM_data_ptr data, 
                      NAEEM_uint32_ptr data_length) {
  FILE *file = fopen(file_path, "r");
  NAEEM_os__read_file(file, data, data_length);
  fclose(file);
}


NAEEM_void
NAEEM_os__read_file_with_path (NAEEM_string base_dir,
                               NAEEM_string file_name,
                               NAEEM_data_ptr buffer,
                               NAEEM_uint32_ptr buffer_length) {
  NAEEM_char path[512];
  strcpy(path, "");
  strcat(path, base_dir);
  strcat(path, "/");
  strcat(path, file_name);
  FILE *f = fopen(path, "r");
  NAEEM_os__read_file(f, buffer, buffer_length);
  fclose(f);
}


NAEEM_void
NAEEM_os__mkdir(NAEEM_string dir_name) {
  struct stat st = {0};
  if (stat(dir_name, &st) == -1) {
    mkdir(dir_name, 0700);
  }
}


NAEEM_void
NAEEM_os__rmdir (NAEEM_path dir_name) {
  // TODO
}


NAEEM_void
NAEEM_os__write_to_file (NAEEM_path base_dir,
                         NAEEM_string file_name,
                         NAEEM_data buffer,
                         NAEEM_uint32 buffer_length) {
  NAEEM_char path[512];
  strcpy(path, "");
  strcat(path, base_dir);
  strcat(path, "/");
  strcat(path, file_name);
  FILE *f = fopen(path, "w");
  fwrite(buffer, buffer_length, sizeof(NAEEM_char), f);
  fclose(f);
}


NAEEM_bool
NAEEM_os__file_exists (NAEEM_path base_dir,
                       NAEEM_string file_name) {
  NAEEM_char path[512];
  strcpy(path, "");
  strcat(path, base_dir);
  strcat(path, "/");
  strcat(path, file_name);
  struct stat st = {0};
  if (stat(path, &st) == 0) {
    return TRUE;
  }
  return FALSE;
}


NAEEM_void
NAEEM_os__create_file (NAEEM_path base_dir,
                       NAEEM_string file_name) {
  NAEEM_char path[512];
  strcpy(path, "");
  strcat(path, base_dir);
  strcat(path, "/");
  strcat(path, file_name);
  FILE *f = fopen(path, "w");
  // NAEEM_byte buffer[1] = {0};
  // fwrite(buffer, 1, sizeof(NAEEM_char), f);
  fclose(f);
}