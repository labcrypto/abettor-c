#ifndef _NAEEM_CORELIBS__DATE_TIME_H_
#define _NAEEM_CORELIBS__DATE_TIME_H_

#include <naeem/types.h>

#ifdef __cplusplus
extern "C" {
#endif


typedef struct {
  NAEEM_uint32       hour;
  NAEEM_uint32       minute;
  NAEEM_uint32       second;
  NAEEM_uint32       millisecond;
} NAEEM_date__time;
typedef NAEEM_date__time PTR NAEEM_date__time_ptr;


typedef struct {
  NAEEM_date__date         date;
  NAEEM_date__time         time;
} NAEEM_date__datetime;
typedef NAEEM_date__datetime PTR NAEEM_date__datetime_ptr;


#ifdef __cplusplus
}
#endif

#endif