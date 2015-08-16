#ifndef _NAEEM_CORELIBS__IMAGE_IMAGE_H_
#define _NAEEM_CORELIBS__IMAGE_IMAGE_H_

#include <naeem/types.h>

#include <magick/MagickCore.h>


#ifdef __cplusplus
extern "C" {
#endif


typedef struct {
  NAEEM_pixel             left;
  NAEEM_pixel             top;
} NAEEM_image__position;
typedef NAEEM_image__position PTR NAEEM_image__position_ptr;


typedef struct {
  NAEEM_pixel             width;
  NAEEM_pixel             height;
} NAEEM_image__dimension;
typedef NAEEM_image__dimension PTR NAEEM_image__dimension_ptr;


typedef struct {
  Image*                  image;
  NAEEM_image__dimension  dimension;
} NAEEM_image__image;
typedef NAEEM_image__image PTR NAEEM_image__image_ptr;


NAEEM_result
NAEEM_image__load_image(NAEEM_path,
                        NAEEM_image__image_ptr);


NAEEM_result
NAEEM_image__put_text(NAEEM_image__image_ptr,
                      NAEEM_image__position,
                      NAEEM_string);


NAEEM_result
NAEEM_image__put_image(NAEEM_image__image_ptr,
                       NAEEM_image__position,
                       NAEEM_image__image_ptr);


NAEEM_result
NAEEM_image__save_image(NAEEM_image__image_ptr,
                        NAEEM_path);


#ifdef __cplusplus
}
#endif

#endif