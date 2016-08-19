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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <iconv.h>

#include <org/labcrypto/abettor/unicode.h>

#ifdef _WIN32
#define FUNCTION_MACRO __FUNCTION__
#else
#define FUNCTION_MACRO __func__
#endif

ORG_LABCRYPTO_ABETTOR_result
ORG_LABCRYPTO_ABETTOR__unicode__utf8_to_utf16(
  ORG_LABCRYPTO_ABETTOR_string utf8,
  ORG_LABCRYPTO_ABETTOR_string_ptr utf16,
  ORG_LABCRYPTO_ABETTOR_length_ptr utf16_len
) {
  ORG_LABCRYPTO_ABETTOR_uint32 i = 0;
  iconv_t cd;
  char *inbuf, *outbuf;
  size_t inbytesleft, outbytesleft, nchars, utf16_buf_len;

#if _WIN32
  cd = iconv_open("UTF-16LE", "UTF-8");
#else
	cd = iconv_open("UTF16LE", "UTF8");
#endif
  if (cd == (iconv_t) - 1) {
    printf("iconv_open failed: %d\n", errno);
    return -1;
  }
  inbytesleft = strlen(utf8);
  if (inbytesleft == 0) {
	  printf("!%s: empty string\n", FUNCTION_MACRO);
    iconv_close(cd);
    return -1;
  }
  inbuf = utf8;
  utf16_buf_len = 2 * inbytesleft; 
  *utf16 = malloc(utf16_buf_len);
  if (!*utf16) {
	  printf("!%s: malloc failed\n", FUNCTION_MACRO);
    iconv_close(cd);
    return -1;
  }
  outbytesleft = utf16_buf_len;
  outbuf = *utf16;    
  nchars = iconv(cd, &inbuf, &inbytesleft, &outbuf, &outbytesleft);
  while (nchars == (size_t)-1 && errno == E2BIG) {
      char *ptr;
      size_t increase = 10;                   // increase length a bit
      size_t len;
      utf16_buf_len += increase;
      outbytesleft += increase;
      ptr = realloc(*utf16, utf16_buf_len);
      if (!ptr) {
        printf("!%s: realloc failed\n", FUNCTION_MACRO);
        free(*utf16);
        iconv_close(cd);
        return -1;
      }
      len = outbuf - *utf16;
      *utf16 = ptr;
      outbuf = *utf16 + len;
      nchars = iconv(cd, &inbuf, &inbytesleft, &outbuf, &outbytesleft);
  }
  if (nchars == (size_t)-1) {
	  printf("!%s: iconv failed: %d\n", FUNCTION_MACRO, errno);
    free(*utf16);
    iconv_close(cd);
    return -1;
  }
  iconv_close(cd);
  *utf16_len = utf16_buf_len - outbytesleft;
  for (; i < *utf16_len; i += 2) {
    char temp = (*utf16)[i];
    (*utf16)[i] = (*utf16)[i + 1];
    (*utf16)[i + 1] = temp;
  }
  return 0;
}
