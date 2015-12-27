#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#endif

#include <naeem/os.h>


NAEEM_void
NAEEM_os__read_file (FILE *fd, 
                     NAEEM_data_ptr data, 
                     NAEEM_uint32_ptr data_length) {
  NAEEM_uint32 current_limit = 128;  
  NAEEM_uint32 buffer_size = 64;
  NAEEM_data buffer = (NAEEM_data)malloc(buffer_size * sizeof(NAEEM_byte));
  NAEEM_uint32 j = 0, i = 0;
  NAEEM_uint32 n = 0;
  *data_length = 0;
  *data = (NAEEM_data)malloc(current_limit * sizeof(NAEEM_byte));
  while (1) {
    n = fread(buffer, sizeof(NAEEM_byte), buffer_size, fd);
    if (n == 0) {
      break;
    }
    if (*data_length + n > current_limit) {
      NAEEM_uint32 old_limit = current_limit;
	    NAEEM_data temp = *data;
      current_limit += (NAEEM_uint32)(current_limit * 1.5);
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
#ifdef _WIN32
  FILE *file = fopen(file_path, "rb");
#else
  FILE *file = fopen(file_path, "r");
#endif
  NAEEM_os__read_file(file, data, data_length);
  fclose(file);
}


NAEEM_void
NAEEM_os__read_file_with_path (NAEEM_string base_dir,
                               NAEEM_string file_name,
                               NAEEM_data_ptr buffer,
                               NAEEM_uint32_ptr buffer_length) {
  FILE *f;
  NAEEM_char path[512];
  strcpy(path, "");
  strcat(path, base_dir);
  strcat(path, "/");
  strcat(path, file_name);
#ifdef _WIN32
  f = fopen(path, "rb");
#else
  f = fopen(path, "r");
#endif
  NAEEM_os__read_file(f, buffer, buffer_length);
  fclose(f);
}


NAEEM_void
NAEEM_os__mkdir(NAEEM_string dir_name) {
#ifdef _WIN32
	wchar_t wpath[1024] = { 0 };
	mbstowcs(wpath, dir_name, strlen(dir_name) + 1);
	CreateDirectory(wpath, NULL);
#else
  struct stat st = {0};
  if (stat(dir_name, &st) == -1) {
    mkdir(dir_name, 0700);
  }
#endif
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
  FILE *f;
  NAEEM_char path[512];
  strcpy(path, "");
  strcat(path, base_dir);
  strcat(path, "/");
  strcat(path, file_name);
#ifdef _WIN32
  f = fopen(path, "wb");
#else
  f = fopen(path, "w");
#endif
  fwrite(buffer, buffer_length, sizeof(NAEEM_char), f);
  fclose(f);
}


NAEEM_bool
NAEEM_os__file_exists (NAEEM_path base_dir,
                       NAEEM_string file_name) {
#ifdef _WIN32
  wchar_t wpath[1024] = { 0 };
#endif
  NAEEM_char path[512];
  strcpy(path, "");
  strcat(path, base_dir);
  strcat(path, "/");
  strcat(path, file_name);
#ifdef _WIN32
  mbstowcs(wpath, path, strlen(path) + 1);
  GetFileAttributes(wpath);
  if(INVALID_FILE_ATTRIBUTES == GetFileAttributes(wpath) && 
	 GetLastError() == ERROR_FILE_NOT_FOUND) {
	return FALSE;
  }
  return TRUE;
#else
  struct stat st = {0};
  if (stat(path, &st) == 0) {
    return TRUE;
  }
  return FALSE;
#endif
}


NAEEM_void
NAEEM_os__create_file (NAEEM_path base_dir,
                       NAEEM_string file_name) {
  FILE *f;
  NAEEM_char path[512];
  strcpy(path, "");
  strcat(path, base_dir);
  strcat(path, "/");
  strcat(path, file_name);
#ifdef _WIN32
  f = fopen(path, "wb");
#else
  f = fopen(path, "w");
#endif
  // NAEEM_byte buffer[1] = {0};
  // fwrite(buffer, 1, sizeof(NAEEM_char), f);
  fclose(f);
}