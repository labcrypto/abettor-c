#include <stdio.h>
#include <stdlib.h>

#include <org/labcrypto/abettor/log.h>


ORG_LABCRYPTO_ABETTOR_void
__ORG_LABCRYPTO_ABETTOR__log__ (
  ORG_LABCRYPTO_ABETTOR_string severity,
  ORG_LABCRYPTO_ABETTOR_string title,
  ORG_LABCRYPTO_ABETTOR_string message
) {
  printf("[%s]  %s:        %s\n", severity, title, message);
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__log__trace (
  ORG_LABCRYPTO_ABETTOR_string title,
  ORG_LABCRYPTO_ABETTOR_string message
) {
  __ORG_LABCRYPTO_ABETTOR__log__("TRACE", title, message);
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__log__debug (
  ORG_LABCRYPTO_ABETTOR_string title,
  ORG_LABCRYPTO_ABETTOR_string message
) {
  __ORG_LABCRYPTO_ABETTOR__log__("DEBUG", title, message);
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__log__info (
  ORG_LABCRYPTO_ABETTOR_string title,
  ORG_LABCRYPTO_ABETTOR_string message
) {
  __ORG_LABCRYPTO_ABETTOR__log__("INFO", title, message);
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__log__warning (
  ORG_LABCRYPTO_ABETTOR_string title,
  ORG_LABCRYPTO_ABETTOR_string message
) {
  __ORG_LABCRYPTO_ABETTOR__log__("WARNING", title, message);
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__log__error (
  ORG_LABCRYPTO_ABETTOR_string title,
  ORG_LABCRYPTO_ABETTOR_string message
) {
  __ORG_LABCRYPTO_ABETTOR__log__("ERROR", title, message);
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__log__fatal (
  ORG_LABCRYPTO_ABETTOR_string title,
  ORG_LABCRYPTO_ABETTOR_string message
) {
  __ORG_LABCRYPTO_ABETTOR__log__("FATAL", title, message);
}
