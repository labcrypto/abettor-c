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
 
#ifndef _ORG_LABCRYPTO_ABETTOR__C__DATE_TIME_H_
#define _ORG_LABCRYPTO_ABETTOR__C__DATE_TIME_H_

#include <org/labcrypto/abettor/types.h>

#ifdef __cplusplus
extern "C" {
#endif


typedef struct {
  ORG_LABCRYPTO_ABETTOR_uint32       hour;
  ORG_LABCRYPTO_ABETTOR_uint32       minute;
  ORG_LABCRYPTO_ABETTOR_uint32       second;
  ORG_LABCRYPTO_ABETTOR_uint32       millisecond;
} ORG_LABCRYPTO_ABETTOR__date__time;
typedef ORG_LABCRYPTO_ABETTOR__date__time PTR ORG_LABCRYPTO_ABETTOR__date__time_ptr;


typedef struct {
  ORG_LABCRYPTO_ABETTOR__date__date         date;
  ORG_LABCRYPTO_ABETTOR__date__time         time;
} ORG_LABCRYPTO_ABETTOR__date__datetime;
typedef ORG_LABCRYPTO_ABETTOR__date__datetime PTR ORG_LABCRYPTO_ABETTOR__date__datetime_ptr;


#ifdef __cplusplus
}
#endif

#endif