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
 
#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h> 
#include <fcntl.h>
#endif

#include <org/labcrypto/abettor/fs.h>


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__fs__read_file (
  FILE *fd, 
  ORG_LABCRYPTO_ABETTOR_data_ptr data, 
  ORG_LABCRYPTO_ABETTOR_uint32_ptr data_length
) {
  ORG_LABCRYPTO_ABETTOR_uint32 current_limit = 128;  
  ORG_LABCRYPTO_ABETTOR_uint32 buffer_size = 64;
  ORG_LABCRYPTO_ABETTOR_data buffer = (ORG_LABCRYPTO_ABETTOR_data)malloc(buffer_size * sizeof(ORG_LABCRYPTO_ABETTOR_byte));
  ORG_LABCRYPTO_ABETTOR_uint32 j = 0, i = 0;
  ORG_LABCRYPTO_ABETTOR_uint32 n = 0;
  ORG_LABCRYPTO_ABETTOR_uint32 length = 0;
  *data = (ORG_LABCRYPTO_ABETTOR_data)malloc(current_limit * sizeof(ORG_LABCRYPTO_ABETTOR_byte));
  while (1) {
    n = fread(buffer, sizeof(ORG_LABCRYPTO_ABETTOR_byte), buffer_size, fd);
    if (n == 0) {
      break;
    }
    if (length + n > current_limit) {
      ORG_LABCRYPTO_ABETTOR_uint32 old_limit = current_limit;
	    ORG_LABCRYPTO_ABETTOR_data temp = *data;
      current_limit += (ORG_LABCRYPTO_ABETTOR_uint32)(current_limit * 1.5);
      *data = (ORG_LABCRYPTO_ABETTOR_data)malloc(current_limit * sizeof(ORG_LABCRYPTO_ABETTOR_char));
      for (i = 0; i < old_limit; i++) {
        (*data)[i] = temp[i];
      }
      free(temp);
    }
    length += n;
    for(i = 0; i < n; i++) {
      (*data)[j] = buffer[i];
      j++;
    }
  }
  if (data_length) {
    *data_length = length;
  }
  free(buffer);
  if (j != length) {
    printf("Error in reading from pipe\r\n");
    free(buffer);
    exit(1);
  }
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__fs__read_file_with_path (
  ORG_LABCRYPTO_ABETTOR_path file_path, 
  ORG_LABCRYPTO_ABETTOR_data_ptr data, 
  ORG_LABCRYPTO_ABETTOR_uint32_ptr data_length
) {
#ifdef _WIN32
  FILE *file = fopen(file_path, "rb");
#else
  FILE *file = fopen(file_path, "r");
#endif
  ORG_LABCRYPTO_ABETTOR__fs__read_file(file, data, data_length);
  fclose(file);
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__fs__read_file_into_buffer (
  ORG_LABCRYPTO_ABETTOR_path file_path, 
  ORG_LABCRYPTO_ABETTOR_data buffer, 
  ORG_LABCRYPTO_ABETTOR_uint32 start_index
) {
  ORG_LABCRYPTO_ABETTOR_counter i = 0;
  ORG_LABCRYPTO_ABETTOR_data data;
  ORG_LABCRYPTO_ABETTOR_length data_length;
  ORG_LABCRYPTO_ABETTOR__fs__read_file_with_path(file_path, &data, &data_length);
  if (data_length == 0) {
    return;
  }
  for (i = 0; i < data_length; i++) {
    buffer[start_index + i] = data[i];
  }
  free(data);
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__fs__read_file_with_base_dir (
  ORG_LABCRYPTO_ABETTOR_string base_dir,
  ORG_LABCRYPTO_ABETTOR_string file_name,
  ORG_LABCRYPTO_ABETTOR_data_ptr buffer,
  ORG_LABCRYPTO_ABETTOR_uint32_ptr buffer_length
) {
  FILE *f;
  ORG_LABCRYPTO_ABETTOR_char path[512];
  strcpy(path, "");
  strcat(path, base_dir);
  strcat(path, "/");
  strcat(path, file_name);
#ifdef _WIN32
  f = fopen(path, "rb");
#else
  f = fopen(path, "r");
#endif
  ORG_LABCRYPTO_ABETTOR__fs__read_file(f, buffer, buffer_length);
  fclose(f);
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__fs__mkdir (
  ORG_LABCRYPTO_ABETTOR_string dir_name
) {
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


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__fs__rmdir (
  ORG_LABCRYPTO_ABETTOR_path dir_name
) {
  // TODO
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__fs__write_to_file (
  ORG_LABCRYPTO_ABETTOR_path base_dir,
  ORG_LABCRYPTO_ABETTOR_string file_name,
  ORG_LABCRYPTO_ABETTOR_data buffer,
  ORG_LABCRYPTO_ABETTOR_uint32 buffer_length
) {
  FILE *f;
  ORG_LABCRYPTO_ABETTOR_char path[512];
  strcpy(path, "");
  strcat(path, base_dir);
  strcat(path, "/");
  strcat(path, file_name);
#ifdef _WIN32
  f = fopen(path, "wb");
#else
  f = fopen(path, "w");
#endif
  fwrite(buffer, buffer_length, sizeof(ORG_LABCRYPTO_ABETTOR_char), f);
  fclose(f);
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__fs__write_to_file2 (
  ORG_LABCRYPTO_ABETTOR_path file_path,
  ORG_LABCRYPTO_ABETTOR_data buffer,
  ORG_LABCRYPTO_ABETTOR_uint32 buffer_length
) {
  FILE *f;
#ifdef _WIN32
  f = fopen(file_path, "wb");
#else
  f = fopen(file_path, "w");
#endif
  fwrite(buffer, buffer_length, sizeof(ORG_LABCRYPTO_ABETTOR_char), f);
  fclose(f);
}

ORG_LABCRYPTO_ABETTOR_bool
ORG_LABCRYPTO_ABETTOR__fs__dir_exists (
  ORG_LABCRYPTO_ABETTOR_path dir_path
) {
  return ORG_LABCRYPTO_ABETTOR__fs__file_exists2(dir_path);
}


ORG_LABCRYPTO_ABETTOR_bool
ORG_LABCRYPTO_ABETTOR__fs__file_exists (
  ORG_LABCRYPTO_ABETTOR_path base_dir,
  ORG_LABCRYPTO_ABETTOR_string file_name
) {
#ifdef _WIN32
  wchar_t wpath[1024] = { 0 };
#endif
  ORG_LABCRYPTO_ABETTOR_char path[512];
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


ORG_LABCRYPTO_ABETTOR_bool
ORG_LABCRYPTO_ABETTOR__fs__file_exists2 (
  ORG_LABCRYPTO_ABETTOR_path file_path
) {
#ifdef _WIN32
  wchar_t wpath[1024] = { 0 };
  mbstowcs(wpath, file_path, strlen(file_path) + 1);
  GetFileAttributes(wpath);
  if(INVALID_FILE_ATTRIBUTES == GetFileAttributes(wpath) && 
     GetLastError() == ERROR_FILE_NOT_FOUND) {
    return FALSE;
  }
  return TRUE;
#else
  struct stat st = {0};
  if (stat(file_path, &st) == 0) {
    return TRUE;
  }
  return FALSE;
#endif
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__fs__create_file (
  ORG_LABCRYPTO_ABETTOR_path base_dir,
  ORG_LABCRYPTO_ABETTOR_string file_name
) {
  FILE *f;
  ORG_LABCRYPTO_ABETTOR_char path[512];
  strcpy(path, "");
  strcat(path, base_dir);
  strcat(path, "/");
  strcat(path, file_name);
#ifdef _WIN32
  f = fopen(path, "wb");
#else
  f = fopen(path, "w");
#endif
  fclose(f);
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__fs__create_file2 (
  ORG_LABCRYPTO_ABETTOR_path file_path
) {
  FILE *f;
#ifdef _WIN32
  f = fopen(file_path, "wb");
#else
  f = fopen(file_path, "w");
#endif
  fclose(f);
}


ORG_LABCRYPTO_ABETTOR_bool
ORG_LABCRYPTO_ABETTOR__fs__delete_file (
  ORG_LABCRYPTO_ABETTOR_path base_dir,
  ORG_LABCRYPTO_ABETTOR_string file_name
) {
  ORG_LABCRYPTO_ABETTOR_char path[512];
  strcpy(path, "");
  strcat(path, base_dir);
  strcat(path, "/");
  strcat(path, file_name);
  return ORG_LABCRYPTO_ABETTOR__fs__delete_file2(path);
}


ORG_LABCRYPTO_ABETTOR_bool
ORG_LABCRYPTO_ABETTOR__fs__delete_file2 (
  ORG_LABCRYPTO_ABETTOR_path file_path
) {
#ifdef _WIN32
  // TODO
  return FALSE;
#else
  if (unlink(file_path) == 0) {
    return TRUE;
  }
  return FALSE;
#endif
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__fs__enum_file_names (
  ORG_LABCRYPTO_ABETTOR_path dir_path,
  ORG_LABCRYPTO_ABETTOR_string_ptr_ptr filenames_ptr,
  ORG_LABCRYPTO_ABETTOR_length_ptr length_ptr
) {
#ifdef _WIN32
  // TODO
#else
  ORG_LABCRYPTO_ABETTOR_counter i = 0, c = 0;
  DIR *d;
  struct dirent *dir;
  d = opendir(dir_path);
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      if (dir->d_type == DT_REG) {
        c++;
      }
    }
    closedir(d);
    *length_ptr = c;
    if (c == 0) {
      return;
    }
    *filenames_ptr = (ORG_LABCRYPTO_ABETTOR_string_ptr) malloc(c * sizeof(ORG_LABCRYPTO_ABETTOR_string));
    d = opendir(dir_path);
    i = 0;
    while ((dir = readdir(d)) != NULL) {
      if (dir->d_type == DT_REG) {
        (*filenames_ptr)[i] = (ORG_LABCRYPTO_ABETTOR_string)malloc(256 * sizeof(ORG_LABCRYPTO_ABETTOR_char));
        strcpy((*filenames_ptr)[i], dir->d_name);
        i++;
      }
    }
    if (i != c) {
      printf("libnaeem-os::ORG_LABCRYPTO_ABETTOR__fs__enum_file_names: WARNING > Inconsistency in number of files.");
    }
    closedir(d);
  } else {
    *length_ptr = 0;
  }
#endif
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__fs__num_files_in_dir (
  ORG_LABCRYPTO_ABETTOR_path dir_path,
  ORG_LABCRYPTO_ABETTOR_length_ptr length_ptr
) {
#ifdef _WIN32
  // TODO
#else
  ORG_LABCRYPTO_ABETTOR_counter c = 0;
  DIR *d;
  struct dirent *dir;
  d = opendir(dir_path);
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      if (dir->d_type == DT_REG) {
        c++;
      }
    }
    closedir(d);
    *length_ptr = c;
  } else {
    *length_ptr = 0;
  }
#endif
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__fs__free_file_names (
  ORG_LABCRYPTO_ABETTOR_string_ptr filenames,
  ORG_LABCRYPTO_ABETTOR_length length
) {
  ORG_LABCRYPTO_ABETTOR_counter i = 0;
  for (; i < length; i++) {
    free(filenames[i]);
  }
  if (length > 0) {
    free(filenames);
  }
}


ORG_LABCRYPTO_ABETTOR_bool
ORG_LABCRYPTO_ABETTOR__fs__copy_file (
  ORG_LABCRYPTO_ABETTOR_path first_base_dir_path,
  ORG_LABCRYPTO_ABETTOR_string first_filename,
  ORG_LABCRYPTO_ABETTOR_path second_base_dir_path,
  ORG_LABCRYPTO_ABETTOR_string second_filename
) {
  ORG_LABCRYPTO_ABETTOR_char path1[512];
  ORG_LABCRYPTO_ABETTOR_char path2[512];
  strcpy(path1, "");
  strcat(path1, first_base_dir_path);
  strcat(path1, "/");
  strcat(path1, first_filename);
  strcpy(path2, "");
  strcat(path2, second_base_dir_path);
  strcat(path2, "/");
  if (second_filename) {
    strcat(path2, second_filename);
  } else {
    strcat(path2, first_filename);
  }
#ifdef _WIN32
  // TODO
  return FALSE;
#else
  int fd_to, fd_from;
  char buf[4096];
  ssize_t nread;
  fd_from = open(path1, O_RDONLY);
  if (fd_from < 0) {
    return FALSE;
  }
  fd_to = open(path2, O_WRONLY | O_CREAT | O_EXCL, 0666);
  if (fd_to < 0) {
    return FALSE;
  }
  while (nread = read(fd_from, buf, sizeof buf), nread > 0) {
    char *out_ptr = buf;
    ssize_t nwritten;
    do {
      nwritten = write(fd_to, out_ptr, nread);
      if (nwritten >= 0) {
          nread -= nwritten;
          out_ptr += nwritten;
      }
    } while (nread > 0);
  }
  if (nread == 0) {
    close(fd_to);
    close(fd_from);
    return TRUE;
  } else {
    printf("libnaeem-os::ORG_LABCRYPTO_ABETTOR__fs__copy_file: WARNING > Inconsistency in copy operation.");
  }
  return FALSE;
#endif
}


ORG_LABCRYPTO_ABETTOR_bool
ORG_LABCRYPTO_ABETTOR__fs__move_file (
  ORG_LABCRYPTO_ABETTOR_path first_base_dir_path,
  ORG_LABCRYPTO_ABETTOR_string first_filename,
  ORG_LABCRYPTO_ABETTOR_path second_base_dir_path,
  ORG_LABCRYPTO_ABETTOR_string second_filename
) {
  return 
    ORG_LABCRYPTO_ABETTOR__fs__copy_file (
      first_base_dir_path,
      first_filename,
      second_base_dir_path,
      second_filename
    ) &&
    ORG_LABCRYPTO_ABETTOR__fs__delete_file (
      first_base_dir_path,
      first_filename
    );
}