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
 
#ifndef _ORG_LABCRYPTO_ABETTOR__C__DATE_DATE_H_
#define _ORG_LABCRYPTO_ABETTOR__C__DATE_DATE_H_

#include <org/labcrypto/abettor/types.h>


#ifdef __cplusplus
extern "C" {
#endif


typedef struct {
  ORG_LABCRYPTO_ABETTOR_uint32       year;
  ORG_LABCRYPTO_ABETTOR_uint32       month;
  ORG_LABCRYPTO_ABETTOR_uint32       day;
} ORG_LABCRYPTO_ABETTOR__date__date;
typedef ORG_LABCRYPTO_ABETTOR__date__date PTR ORG_LABCRYPTO_ABETTOR__date__date_ptr;

typedef ORG_LABCRYPTO_ABETTOR__date__date ORG_LABCRYPTO_ABETTOR__date__jalali_date;
typedef ORG_LABCRYPTO_ABETTOR__date__date ORG_LABCRYPTO_ABETTOR__date__gregorian_date;

typedef ORG_LABCRYPTO_ABETTOR__date__jalali_date PTR ORG_LABCRYPTO_ABETTOR__date__jalali_date_ptr;
typedef ORG_LABCRYPTO_ABETTOR__date__gregorian_date PTR ORG_LABCRYPTO_ABETTOR__date__gregorian_date_ptr;


ORG_LABCRYPTO_ABETTOR_unix_epoch
ORG_LABCRYPTO_ABETTOR__date__get_epoch_from_gregorian_date (
  ORG_LABCRYPTO_ABETTOR__date__gregorian_date
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__date__get_gregorian_date_from_epoch (
  ORG_LABCRYPTO_ABETTOR_unix_epoch,
  ORG_LABCRYPTO_ABETTOR__date__gregorian_date_ptr
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__date__add_years_to_gregorian_date (
  ORG_LABCRYPTO_ABETTOR__date__gregorian_date_ptr,
  ORG_LABCRYPTO_ABETTOR_uint32
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__date__add_years_to_jalali_date (
  ORG_LABCRYPTO_ABETTOR__date__gregorian_date_ptr,
  ORG_LABCRYPTO_ABETTOR_uint32
);


ORG_LABCRYPTO_ABETTOR_unix_epoch
ORG_LABCRYPTO_ABETTOR__date__get_current_unix_epoch();


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__date__get_current_gregorian_date (
  ORG_LABCRYPTO_ABETTOR__date__gregorian_date_ptr
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__date__get_current_jalali_date (
  ORG_LABCRYPTO_ABETTOR__date__jalali_date_ptr
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__date__convert_jalali_to_gregorian (
  ORG_LABCRYPTO_ABETTOR__date__jalali_date,
  ORG_LABCRYPTO_ABETTOR__date__gregorian_date_ptr
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__date__convert_gregorian_to_jalali (
  ORG_LABCRYPTO_ABETTOR__date__gregorian_date,
  ORG_LABCRYPTO_ABETTOR__date__jalali_date_ptr
);


ORG_LABCRYPTO_ABETTOR_uint32
ORG_LABCRYPTO_ABETTOR__date__get_gregorian_day_of_week (
  ORG_LABCRYPTO_ABETTOR__date__gregorian_date
);


ORG_LABCRYPTO_ABETTOR_uint32
ORG_LABCRYPTO_ABETTOR__date__get_jalali_day_of_week (
  ORG_LABCRYPTO_ABETTOR__date__jalali_date
);
                                      

ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__date__get_gregorian_month_name (
  ORG_LABCRYPTO_ABETTOR_uint32, 
  ORG_LABCRYPTO_ABETTOR_string_ptr
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__date__get_jalali_month_name (
  ORG_LABCRYPTO_ABETTOR_uint32, 
  ORG_LABCRYPTO_ABETTOR_string_ptr
);


#ifdef __cplusplus
}
#endif

#endif