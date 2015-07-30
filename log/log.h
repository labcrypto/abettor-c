#ifndef _NAEEM_LOG_H_
#define _NAEEM_LOG_H_

#include <naeem/types.h>

#ifdef __cplusplus
extern "C" {
#endif


NAEEM_void
NAEEM_log_trace (NAEEM_string     /* Title */,
                 NAEEM_string     /* Message */);


NAEEM_void
NAEEM_log_debug (NAEEM_string     /* Title */,
                 NAEEM_string     /* Message */);


NAEEM_void
NAEEM_log_info (NAEEM_string     /* Title */,
                NAEEM_string     /* Message */);


NAEEM_void
NAEEM_log_warning (NAEEM_string     /* Title */,
                   NAEEM_string     /* Message */);


NAEEM_void
NAEEM_log_error (NAEEM_string     /* Title */,
                 NAEEM_string     /* Message */);


NAEEM_void
NAEEM_log_fatal (NAEEM_string     /* Title */,
                 NAEEM_string     /* Message */);


#ifdef __cplusplus
}
#endif

#endif