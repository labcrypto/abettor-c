#ifndef _NAEEM_CORELIBS__DATE_DATE_H_
#define _NAEEM_CORELIBS__DATE_DATE_H_

#include <naeem/types.h>


#ifdef __cplusplus
extern "C" {
#endif


typedef struct {
  NAEEM_uint32       year;
  NAEEM_uint32       month;
  NAEEM_uint32       day;
} NAEEM_date__date;
typedef NAEEM_date__date PTR NAEEM_date__date_ptr;

typedef NAEEM_date__date NAEEM_date__jalali_date;
typedef NAEEM_date__date NAEEM_date__gregorian_date;

typedef NAEEM_date__jalali_date PTR NAEEM_date__jalali_date_ptr;
typedef NAEEM_date__gregorian_date PTR NAEEM_date__gregorian_date_ptr;


NAEEM_unix_epoch
NAEEM_date__get_epoch_from_gregorian_date(NAEEM_date__gregorian_date);


NAEEM_void
NAEEM_date__get_gregorian_date_from_epoch(NAEEM_unix_epoch,
                                          NAEEM_date__gregorian_date_ptr);


NAEEM_void
NAEEM_date__add_years_to_gregorian_date(NAEEM_date__gregorian_date_ptr,
                                        NAEEM_uint32);


NAEEM_void
NAEEM_date__add_years_to_jalali_date(NAEEM_date__gregorian_date_ptr,
                                        NAEEM_uint32);


NAEEM_void
NAEEM_date__get_current_gregorian_date(NAEEM_date__gregorian_date_ptr);


NAEEM_void
NAEEM_date__get_current_jalali_date(NAEEM_date__jalali_date_ptr);


NAEEM_void
NAEEM_date__convert_jalali_to_gregorian(NAEEM_date__jalali_date,
                                        NAEEM_date__gregorian_date_ptr);


NAEEM_void
NAEEM_date__convert_gregorian_to_jalali(NAEEM_date__gregorian_date,
                                        NAEEM_date__jalali_date_ptr);


NAEEM_uint32
NAEEM_date__get_gregorian_day_of_week(NAEEM_date__gregorian_date);


NAEEM_uint32
NAEEM_date__get_jalali_day_of_week(NAEEM_date__jalali_date);
                                      

NAEEM_void
NAEEM_date__get_gregorian_month_name(NAEEM_uint32, 
                                     NAEEM_string_ptr);


NAEEM_void
NAEEM_date__get_jalali_month_name(NAEEM_uint32, 
                                  NAEEM_string_ptr);


#ifdef __cplusplus
}
#endif

#endif