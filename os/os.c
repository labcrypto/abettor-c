#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h> 
#include <fcntl.h>
#endif

#include <naeem/os.h>


NAEEM_void
NAEEM_os__read_file (
  FILE *fd, 
  NAEEM_data_ptr data, 
  NAEEM_uint32_ptr data_length
) {
  NAEEM_uint32 current_limit = 128;  
  NAEEM_uint32 buffer_size = 64;
  NAEEM_data buffer = (NAEEM_data)malloc(buffer_size * sizeof(NAEEM_byte));
  NAEEM_uint32 j = 0, i = 0;
  NAEEM_uint32 n = 0;
  NAEEM_uint32 length = 0;
  *data = (NAEEM_data)malloc(current_limit * sizeof(NAEEM_byte));
  while (1) {
    n = fread(buffer, sizeof(NAEEM_byte), buffer_size, fd);
    if (n == 0) {
      break;
    }
    if (length + n > current_limit) {
      NAEEM_uint32 old_limit = current_limit;
	    NAEEM_data temp = *data;
      current_limit += (NAEEM_uint32)(current_limit * 1.5);
      *data = (NAEEM_data)malloc(current_limit * sizeof(NAEEM_char));
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


NAEEM_void
NAEEM_os__read_file2 (
  NAEEM_path file_path, 
  NAEEM_data_ptr data, 
  NAEEM_uint32_ptr data_length
) {
#ifdef _WIN32
  FILE *file = fopen(file_path, "rb");
#else
  FILE *file = fopen(file_path, "r");
#endif
  NAEEM_os__read_file(file, data, data_length);
  fclose(file);
}


NAEEM_void
NAEEM_os__read_file3 (
  NAEEM_path file_path, 
  NAEEM_data buffer, 
  NAEEM_uint32 start_index
) {
  NAEEM_counter i = 0;
  NAEEM_data data;
  NAEEM_length data_length;
  NAEEM_os__read_file2(file_path, &data, &data_length);
  if (data_length == 0) {
    return;
  }
  for (i = 0; i < data_length; i++) {
    buffer[start_index + i] = data[i];
  }
  free(data);
}


NAEEM_void
NAEEM_os__read_file_with_path (
  NAEEM_string base_dir,
  NAEEM_string file_name,
  NAEEM_data_ptr buffer,
  NAEEM_uint32_ptr buffer_length
) {
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
NAEEM_os__mkdir (
  NAEEM_string dir_name
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


NAEEM_void
NAEEM_os__rmdir (
  NAEEM_path dir_name
) {
  // TODO
}


NAEEM_void
NAEEM_os__write_to_file (
  NAEEM_path base_dir,
  NAEEM_string file_name,
  NAEEM_data buffer,
  NAEEM_uint32 buffer_length
) {
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


NAEEM_void
NAEEM_os__write_to_file2 (
  NAEEM_path file_path,
  NAEEM_data buffer,
  NAEEM_uint32 buffer_length
) {
  FILE *f;
#ifdef _WIN32
  f = fopen(file_path, "wb");
#else
  f = fopen(file_path, "w");
#endif
  fwrite(buffer, buffer_length, sizeof(NAEEM_char), f);
  fclose(f);
}

NAEEM_bool
NAEEM_os__dir_exists (
  NAEEM_path dir_path
) {
  return NAEEM_os__file_exists2(dir_path);
}


NAEEM_bool
NAEEM_os__file_exists (
  NAEEM_path base_dir,
  NAEEM_string file_name
) {
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


NAEEM_bool
NAEEM_os__file_exists2 (
  NAEEM_path file_path
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


NAEEM_void
NAEEM_os__create_file (
  NAEEM_path base_dir,
  NAEEM_string file_name
) {
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
  fclose(f);
}


NAEEM_void
NAEEM_os__create_file2 (
  NAEEM_path file_path
) {
  FILE *f;
#ifdef _WIN32
  f = fopen(file_path, "wb");
#else
  f = fopen(file_path, "w");
#endif
  fclose(f);
}


NAEEM_bool
NAEEM_os__delete_file (
  NAEEM_path base_dir,
  NAEEM_string file_name
) {
  NAEEM_char path[512];
  strcpy(path, "");
  strcat(path, base_dir);
  strcat(path, "/");
  strcat(path, file_name);
  return NAEEM_os__delete_file2(path);
}


NAEEM_bool
NAEEM_os__delete_file2 (
  NAEEM_path file_path
) {
#ifdef _WIN32
  // TODO
#else
  if (unlink(file_path) == 0) {
    return TRUE;
  }
  return FALSE;
#endif
}


NAEEM_void
NAEEM_os__enum_file_names (
  NAEEM_path dir_path,
  NAEEM_string_ptr_ptr filenames_ptr,
  NAEEM_length_ptr length_ptr
) {
#ifdef _WIN32
  // TODO
#else
  NAEEM_counter i = 0, c = 0;
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
    *filenames_ptr = (NAEEM_string_ptr) malloc(c * sizeof(NAEEM_string));
    d = opendir(dir_path);
    i = 0;
    while ((dir = readdir(d)) != NULL) {
      if (dir->d_type == DT_REG) {
        (*filenames_ptr)[i] = (NAEEM_string)malloc(256 * sizeof(NAEEM_char));
        strcpy((*filenames_ptr)[i], dir->d_name);
        i++;
      }
    }
    if (i != c) {
      printf("libnaeem-os::NAEEM_os__enum_file_names: WARNING > Inconsistency in number of files.");
    }
    closedir(d);
  } else {
    *length_ptr = 0;
  }
#endif
}


NAEEM_void
NAEEM_os__num_files_in_dir (
  NAEEM_path dir_path,
  NAEEM_length_ptr length_ptr
) {
#ifdef _WIN32
  // TODO
#else
  NAEEM_counter c = 0;
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


NAEEM_void
NAEEM_os__free_file_names (
  NAEEM_string_ptr filenames,
  NAEEM_length length
) {
  NAEEM_counter i = 0;
  for (; i < length; i++) {
    free(filenames[i]);
  }
  if (length > 0) {
    free(filenames);
  }
}


NAEEM_bool
NAEEM_os__copy_file (
  NAEEM_path first_base_dir_path,
  NAEEM_string first_filename,
  NAEEM_path second_base_dir_path,
  NAEEM_string second_filename
) {
  NAEEM_char path1[512];
  strcpy(path1, "");
  strcat(path1, first_base_dir_path);
  strcat(path1, "/");
  strcat(path1, first_filename);
  NAEEM_char path2[512];
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
    printf("libnaeem-os::NAEEM_os__copy_file: WARNING > Inconsistency in copy operation.");
  }
  return FALSE;
#endif
}


NAEEM_bool
NAEEM_os__move_file (
  NAEEM_path first_base_dir_path,
  NAEEM_string first_filename,
  NAEEM_path second_base_dir_path,
  NAEEM_string second_filename
) {
  return 
    NAEEM_os__copy_file (
      first_base_dir_path,
      first_filename,
      second_base_dir_path,
      second_filename
    ) &&
    NAEEM_os__delete_file (
      first_base_dir_path,
      first_filename
    );
}