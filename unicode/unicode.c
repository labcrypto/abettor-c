#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <iconv.h>

#include <naeem/unicode.h>

#ifdef _WIN32
#define FUNCTION_MACRO __FUNCTION__
#else
#define FUNCTION_MACRO __func__
#endif

NAEEM_result
NAEEM_unicode__utf8_to_utf16(NAEEM_string utf8,
                             NAEEM_string_ptr utf16,
                             NAEEM_length_ptr utf16_len) {
    iconv_t cd;
    char *inbuf, *outbuf;
    size_t inbytesleft, outbytesleft, nchars, utf16_buf_len;

    cd = iconv_open("UTF16LE", "UTF8");
    if (cd == (iconv_t)-1) {
	printf("!%s: iconv_open failed: %d\n", FUNCTION_MACRO, errno);
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
    NAEEM_uint32 i = 0;
    for (; i < *utf16_len; i += 2) {
      char temp = (*utf16)[i];
      (*utf16)[i] = (*utf16)[i + 1];
      (*utf16)[i + 1] = temp;
    }
    return 0;
}
