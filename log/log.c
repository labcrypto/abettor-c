#include <stdio.h>
#include <stdlib.h>

#include <naeem/log.h>


NAEEM_void
__NAEEM_log__ (NAEEM_string severity,
               NAEEM_string title,
               NAEEM_string message) {
  printf("[%s]  %s:        %s\n", severity, title, message);
}


NAEEM_void
NAEEM_log__trace (NAEEM_string title,
                  NAEEM_string message) {
  __NAEEM_log__("TRACE", title, message);
}


NAEEM_void
NAEEM_log__debug (NAEEM_string title,
                  NAEEM_string message) {
  __NAEEM_log__("DEBUG", title, message);
}


NAEEM_void
NAEEM_log__info (NAEEM_string title,
                 NAEEM_string message) {
  __NAEEM_log__("INFO", title, message);
}


NAEEM_void
NAEEM_log__warning (NAEEM_string title,
                    NAEEM_string message) {
  __NAEEM_log__("WARNING", title, message);
}


NAEEM_void
NAEEM_log__error (NAEEM_string title,
                  NAEEM_string message) {
  __NAEEM_log__("ERROR", title, message);
}


NAEEM_void
NAEEM_log__fatal (NAEEM_string title,
                  NAEEM_string message) {
  __NAEEM_log__("FATAL", title, message);
}
