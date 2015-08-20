#ifndef _NAEEM_CORELIBS__LOG_LOG_H_
#define _NAEEM_CORELIBS__LOG_LOG_H_

#include <naeem/types.h>

#ifdef __cplusplus
extern "C" {
#endif


NAEEM_void
NAEEM_log__trace (NAEEM_string     /* Title */,
                  NAEEM_string     /* Message */);


NAEEM_void
NAEEM_log__debug (NAEEM_string     /* Title */,
                  NAEEM_string     /* Message */);


NAEEM_void
NAEEM_log__info (NAEEM_string     /* Title */,
                 NAEEM_string     /* Message */);


NAEEM_void
NAEEM_log__warning (NAEEM_string     /* Title */,
                    NAEEM_string     /* Message */);


NAEEM_void
NAEEM_log__error (NAEEM_string     /* Title */,
                  NAEEM_string     /* Message */);


NAEEM_void
NAEEM_log__fatal (NAEEM_string     /* Title */,
                  NAEEM_string     /* Message */);


#ifdef __cplusplus
}
#endif

#endif
