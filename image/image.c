#include <naeem/image.h>


NAEEM_result
NAEEM_image__load_image(NAEEM_path path,
                        NAEEM_image__image_ptr image_ptr) {
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