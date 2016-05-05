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
 
#include <time.h>

#include <org/labcrypto/abettor/date.h>


ORG_LABCRYPTO_ABETTOR_unix_epoch
ORG_LABCRYPTO_ABETTOR__date__get_epoch_from_gregorian_date (
  ORG_LABCRYPTO_ABETTOR__date__gregorian_date gregorian_date
) {
  struct tm t;
  time_t t_of_day;
  t.tm_year = gregorian_date.year - 1900;
  t.tm_mon = gregorian_date.month - 1;
  t.tm_mday = gregorian_date.day;
  t.tm_hour = 0;
  t.tm_min = 0;
  t.tm_sec = 0;
  t.tm_isdst = -1;
  t_of_day = mktime(&t);
  return (ORG_LABCRYPTO_ABETTOR_unix_epoch)t_of_day;
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__date__get_gregorian_date_from_epoch (
  ORG_LABCRYPTO_ABETTOR_unix_epoch epoch,
  ORG_LABCRYPTO_ABETTOR__date__gregorian_date_ptr gregorian_date_ptr
) {
  time_t t = epoch;
  struct tm tm = *localtime(&t);
  gregorian_date_ptr->year = tm.tm_year + 1900;
  gregorian_date_ptr->month = tm.tm_mon + 1;
  gregorian_date_ptr->day = tm.tm_mday;
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__date__add_years_to_gregorian_date (
  ORG_LABCRYPTO_ABETTOR__date__gregorian_date_ptr gregorian_date_ptr,
  ORG_LABCRYPTO_ABETTOR_uint32 number_of_years
) {
  ORG_LABCRYPTO_ABETTOR_unix_epoch epoch = ORG_LABCRYPTO_ABETTOR__date__get_epoch_from_gregorian_date(*gregorian_date_ptr);
  epoch += number_of_years * 365 * 24 * 3600;
  ORG_LABCRYPTO_ABETTOR__date__get_gregorian_date_from_epoch(epoch, gregorian_date_ptr);
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__date__add_years_to_jalali_date (
  ORG_LABCRYPTO_ABETTOR__date__jalali_date_ptr jalali_date_ptr,
  ORG_LABCRYPTO_ABETTOR_uint32 number_of_years
) {
  ORG_LABCRYPTO_ABETTOR__date__gregorian_date gregorian_date;
  ORG_LABCRYPTO_ABETTOR__date__convert_gregorian_to_jalali(*jalali_date_ptr, &gregorian_date);
  ORG_LABCRYPTO_ABETTOR__date__add_years_to_gregorian_date(&gregorian_date, number_of_years);
  ORG_LABCRYPTO_ABETTOR__date__convert_jalali_to_gregorian(gregorian_date, jalali_date_ptr);
}


ORG_LABCRYPTO_ABETTOR_unix_epoch
ORG_LABCRYPTO_ABETTOR__date__get_current_unix_epoch() {
  ORG_LABCRYPTO_ABETTOR__date__gregorian_date gregorian_date;
  ORG_LABCRYPTO_ABETTOR__date__get_current_gregorian_date(&gregorian_date);
  return ORG_LABCRYPTO_ABETTOR__date__get_epoch_from_gregorian_date(gregorian_date);
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__date__get_current_gregorian_date (
  ORG_LABCRYPTO_ABETTOR__date__gregorian_date_ptr gregorian_date_ptr
) {
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  gregorian_date_ptr->year = tm.tm_year + 1900;
  gregorian_date_ptr->month = tm.tm_mon + 1;
  gregorian_date_ptr->day = tm.tm_mday;
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__date__get_current_jalali_date (
  ORG_LABCRYPTO_ABETTOR__date__jalali_date_ptr jalali_date_ptr
) {
  ORG_LABCRYPTO_ABETTOR__date__gregorian_date gregorian_date;
  ORG_LABCRYPTO_ABETTOR__date__get_current_gregorian_date(&gregorian_date);
  ORG_LABCRYPTO_ABETTOR__date__convert_gregorian_to_jalali(gregorian_date, jalali_date_ptr);
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__date__convert_jalali_to_gregorian (
  ORG_LABCRYPTO_ABETTOR__date__jalali_date jalali_date,
  ORG_LABCRYPTO_ABETTOR__date__gregorian_date_ptr gregorian_date_ptr
) {
  ORG_LABCRYPTO_ABETTOR_uint32 year, month, day, d_4, d_33, doy_j, a, b, gy, gm = 0, gd, v;
  year = jalali_date.year;
  month = jalali_date.month;
  day = jalali_date.day;
  d_4 = (year + 1) % 4;
  if (month < 7)
    doy_j = ((month - 1) * 31) + day;
  else
    doy_j = ((month - 7) * 30) + day + 186;
  d_33 = (int)(((year - 55) % 132) * .0305);
  a = (d_33 != 3 && d_4 <= d_33) ? 287 : 286;
  if ((d_33 == 1 || d_33 == 2) && (d_33 == d_4 || d_4 == 1))
    b = 78;
  else
    b = (d_33 == 3 && d_4 == 0) ? 80 : 79;
  if ((int) ((year - 19) / 63) == 20) {
    a -= 1;
    b += 1;
  }
  if (doy_j <= a) {
    gy = year + 621;
    gd = doy_j + b;
  }
  else {
    gy = year + 622;
    gd = doy_j - a;
  }
  {
	  ORG_LABCRYPTO_ABETTOR_uint32 months[] = {
		0, 31, gy % 4 == 0 ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	  };
	  ORG_LABCRYPTO_ABETTOR_uint32 i = 0;
	  for (i = 0; i < 13; i++) {
		gm = i;
		v = months[i];
		if (gd <= v)
			break;
		gd -= v;
	  }
	  gregorian_date_ptr->year = gy;
	  gregorian_date_ptr->month = gm;
	  gregorian_date_ptr->day = gd;
  }
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__date__convert_gregorian_to_jalali (
  ORG_LABCRYPTO_ABETTOR__date__gregorian_date gregorian_date,
  ORG_LABCRYPTO_ABETTOR__date__jalali_date_ptr jalali_date_ptr
) {
  ORG_LABCRYPTO_ABETTOR_uint32 year, month, day, d_4, d_33, a, b, doy_j;
  ORG_LABCRYPTO_ABETTOR_uint32 doy_g, jm, jd, jy;
  ORG_LABCRYPTO_ABETTOR_uint32 g_a[] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
  year = gregorian_date.year;
  month = gregorian_date.month;
  day = gregorian_date.day;  
  d_4 = year % 4;
  doy_g = g_a[month] + day;
  if (d_4 == 0 && month > 2) {
    doy_g += 1;
  }
  d_33 = (ORG_LABCRYPTO_ABETTOR_uint32) (((year - 16) % 132) * .0305);
  a = (d_33 == 3 || d_33 < (d_4 - 1) || d_4 == 0) ? 286 : 287;
  if ((d_33 == 1 || d_33 == 2) && (d_33 == d_4 || d_4 == 1)) {
    b = 78;
  } else {
    b = (d_33 == 3 && d_4 == 0) ? 80 : 79;
  }
  if ((ORG_LABCRYPTO_ABETTOR_uint32) ((year - 10) / 63) == 30) {
    a -= 1;
    b += 1;
  }
  if (doy_g > b) {
    jy = year - 621;
    doy_j = doy_g - b;
  } else {
    jy = year - 622;
    doy_j = doy_g + a;
  }
  if (doy_j < 187) {
    jm = (ORG_LABCRYPTO_ABETTOR_uint32)((doy_j - 1) / 31);
    jd = doy_j - (31 * jm);
    jm += 1;
  } else {
    jm = (ORG_LABCRYPTO_ABETTOR_uint32)((doy_j - 187) / 30);
    jd = doy_j - 186 - (jm * 30);
    jm += 7;
  }
  jalali_date_ptr->year = jy;
  jalali_date_ptr->month = jm;
  jalali_date_ptr->day = jd;
}


ORG_LABCRYPTO_ABETTOR_uint32
ORG_LABCRYPTO_ABETTOR__date__get_gregorian_day_of_week (
  ORG_LABCRYPTO_ABETTOR__date__gregorian_date gregorian_date
) {
  static ORG_LABCRYPTO_ABETTOR_uint32 t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
  ORG_LABCRYPTO_ABETTOR_uint32 gy, gm, gd;
  gy = gregorian_date.year;
  gm = gregorian_date.month;
  gd = gregorian_date.day;
  gy -= gm < 3;
  return ((gy + gy / 4 - gy / 100 + gy / 400 + t[gm - 1] + gd) % 7) + 1;
}


ORG_LABCRYPTO_ABETTOR_uint32
ORG_LABCRYPTO_ABETTOR__date__get_jalali_day_of_week (
  ORG_LABCRYPTO_ABETTOR__date__jalali_date jalali_date
) {
  ORG_LABCRYPTO_ABETTOR__date__gregorian_date gregorian_date;
  ORG_LABCRYPTO_ABETTOR__date__convert_jalali_to_gregorian(jalali_date, &gregorian_date);
  return ORG_LABCRYPTO_ABETTOR__date__get_gregorian_day_of_week(gregorian_date);
}
                                      

ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__date__get_gregorian_month_name (
  ORG_LABCRYPTO_ABETTOR_uint32 month, 
  ORG_LABCRYPTO_ABETTOR_string_ptr month_name_ptr
) {
  // TODO
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__date__get_jalali_month_name (
  ORG_LABCRYPTO_ABETTOR_uint32 month, 
  ORG_LABCRYPTO_ABETTOR_string_ptr month_name_ptr
) {
  // TODO
}