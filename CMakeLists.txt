cmake_minimum_required(VERSION 2.8) 

project(abettor-c)

if (UNIX)
  add_definitions(-D__UNIX__)
  set(BIN_INSTALL_DIR "/usr/bin/" CACHE PATH "")
  set(HEADERS_INSTALL_DIR "/usr/local/include")
  set(LIB_INSTALL_DIR "/usr/local/lib")
  include_directories("/usr/include/PCSC")
  if (APPLE)
    set(CMAKE_MACOSX_RPATH 1)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-writable-strings -Wno-deprecated-register -Wno-unused-function")
    add_defnitions(-D__MACOS__)
    link_directories("/opt/local/lib/")
  else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-attributes -Wno-write-strings -Wno-unused-but-set-variable -Wno-sign-compare -Wno-unused-function")
    add_definitions(-D__LINUX__)
    link_directories("/usr/local/lib")
  endif()
endif()

if (WIN32)
  # Change these paths to whatever that is valid for your system
  include_directories("../ir.ntnaeem.kawthar.lib.external/openssl/include")
  include_directories("../ir.ntnaeem.kawthar.lib.external/iconv/include")
  add_definitions(-D_CRT_SECURE_NO_DEPRECATE)
  add_definitions(-DUNICODE -D_UNICODE)
  add_definitions(-D__WIN32__)
endif()

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(PROJECT_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

include_directories(${PROJECT_INCLUDE_DIR})

add_library(abettor-c-bio STATIC 
  ${PROJECT_SOURCE_DIR}/bio/cbeff.c
  ${PROJECT_SOURCE_DIR}/bio/face.c
  ${PROJECT_SOURCE_DIR}/bio/finger.c
)

# if (UNIX)
#   add_library(abettor-c-bio-shared SHARED 
#     ${PROJECT_SOURCE_DIR}/bio/cbeff.c
#     ${PROJECT_SOURCE_DIR}/bio/face.c
#     ${PROJECT_SOURCE_DIR}/bio/finger.c
#     )
#   set_target_properties(abettor-c-bio-shared PROPERTIES OUTPUT_NAME abettor-c-bio)
# endif()

add_library(abettor-c-crypto STATIC 
  ${PROJECT_SOURCE_DIR}/crypto/base64.c
  ${PROJECT_SOURCE_DIR}/crypto/crypto.c
)

add_library(abettor-c-date STATIC 
  ${PROJECT_SOURCE_DIR}/date/date.c
)

add_library(abettor-c-fs STATIC 
  ${PROJECT_SOURCE_DIR}/fs/fs.c
)

add_library(abettor-c-log STATIC 
  ${PROJECT_SOURCE_DIR}/log/log.c
)

add_library(abettor-c-net STATIC 
  ${PROJECT_SOURCE_DIR}/net/udp.c
)

add_library(abettor-c-pkcs11 STATIC 
  ${PROJECT_SOURCE_DIR}/pkcs11/pkcs11.c
  ${PROJECT_SOURCE_DIR}/pkcs11/pkcs11_errors.c
)

add_library(abettor-c-rand STATIC 
  ${PROJECT_SOURCE_DIR}/rand/rand.c
)

if (WIN32)
  add_library(abettor-c-scard STATIC 
    ${PROJECT_SOURCE_DIR}/scard/scard.c
  )
endif()

add_library(abettor-c-test STATIC 
  ${PROJECT_SOURCE_DIR}/test/test.c
)

add_library(abettor-c-unicode STATIC 
  ${PROJECT_SOURCE_DIR}/unicode/unicode.c
)

add_library(abettor-c-util STATIC 
  ${PROJECT_SOURCE_DIR}/util/util.c
)

install(DIRECTORY 
  ${PROJECT_INCLUDE_DIR}/org 
  DESTINATION 
  ${HEADERS_INSTALL_DIR} 
  FILES_MATCHING 
  PATTERN "*.h"
)

if (UNIX) 
  install(TARGETS
    abettor-c-bio
    abettor-c-crypto
    abettor-c-date
    abettor-c-fs
    abettor-c-log
    abettor-c-net
    abettor-c-pkcs11
    abettor-c-rand
    abettor-c-test
    abettor-c-unicode
    abettor-c-util
    DESTINATION
    ${LIB_INSTALL_DIR}
  )
else()  
  install(TARGETS
    abettor-c-bio
    abettor-c-crypto
    abettor-c-date
    abettor-c-fs
    abettor-c-log
    abettor-c-net
    abettor-c-pkcs11
    abettor-c-rand
    abettor-c-scard
    abettor-c-test
    abettor-c-unicode
    abettor-c-util
    DESTINATION
    ${LIB_INSTALL_DIR}
  )
endif()

# add_custom_target(uninstall
#   COMMAND rm -rfv ${LIB_INSTALL_DIR}/libabettor-c*
#   COMMAND rm -rfv ${HEADERS_INSTALL_DIR}/org/labcrypto/abettor
# )
