#include <string.h>

#include <naeem/image.h>


NAEEM_void
NAEEM_image__start_library(NAEEM_int32 argc, 
                           NAEEM_string_ptr argv) {
  MagickCoreGenesis(*argv, MagickTrue);
}


NAEEM_void
NAEEM_image__shutdown_library() {
  MagickCoreTerminus();
}


NAEEM_result
NAEEM_image__load_image(NAEEM_path path,
                        NAEEM_image__image_ptr image_ptr) {
  printf(">>>>> %s\n", path);
  ExceptionInfo *exception;
  Image *images;
  ImageInfo *image_info;
  exception = AcquireExceptionInfo();
  image_info = CloneImageInfo((ImageInfo *) NULL);
  strcpy(image_info->filename, path);
  images = ReadImage(image_info, exception);
  if (exception->severity != UndefinedException) {
    CatchException(exception);
    return NAEEM_RESULT_GENERAL_ERROR;
  }
  if (images == (Image *) NULL) {
    return NAEEM_RESULT_GENERAL_ERROR;
  }
  printf ("Dim: %dx%d\n", (int)images->columns, (int)images->rows);
  image_ptr->image = images;
  image_ptr->dimension.width = images->columns;
  image_ptr->dimension.height = images->rows;
  return NAEEM_RESULT_SUCCESS;
}


NAEEM_result
NAEEM_image__put_text(NAEEM_image__image_ptr image_ptr,
                      NAEEM_image__position position,
                      NAEEM_string text) {
  return NAEEM_RESULT_SUCCESS;
}


NAEEM_result
NAEEM_image__put_image(NAEEM_image__image_ptr image_ptr,
                       NAEEM_image__position position,
                       NAEEM_image__image_ptr image) {
  return NAEEM_RESULT_SUCCESS;
}


NAEEM_result
NAEEM_image__save_image(NAEEM_image__image_ptr image_ptr,
                        NAEEM_path path) {
  return NAEEM_RESULT_SUCCESS;
}