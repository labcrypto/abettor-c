cmake_minimum_required(VERSION 2.8) 

project(LabCryptoOrg-abettor-c)

if (APPLE)
  set(CMAKE_MACOSX_RPATH 1)
endif()

set(BIN_INSTALL_DIR "/usr/bin/" CACHE PATH "")
set(HEADERS_INSTALL_DIR "/usr/include")
set(LIB_INSTALL_DIR "/usr/lib")

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(PROJECT_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

link_directories("/usr/local/lib")
if (APPLE)
  link_directories("/opt/local/lib/")
endif()

include_directories(${PROJECT_INCLUDE_DIR})

if (APPLE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-writable-strings -Wno-deprecated-register -Wno-unused-function")
elseif (UNIX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-write-strings -Wno-unused-but-set-variable -Wno-sign-compare -Wno-unused-function")
endif()

add_library(abettor-c-bio SHARED 
  ${PROJECT_SOURCE_DIR}/bio/cbeff.c
  ${PROJECT_SOURCE_DIR}/bio/face.c
  ${PROJECT_SOURCE_DIR}/bio/finger.c
)
target_link_libraries(abettor-c-bio abettor-c-test)

add_library(abettor-c-test SHARED 
  ${PROJECT_SOURCE_DIR}/test/test.c
)
target_link_libraries(abettor-c-test abettor-c-util)

add_library(abettor-c-util SHARED 
  ${PROJECT_SOURCE_DIR}/util/util.c
)

install(DIRECTORY 
  ${PROJECT_INCLUDE_DIR}/org 
  DESTINATION 
  ${HEADERS_INSTALL_DIR} 
  FILES_MATCHING 
  PATTERN "*.h"
)

install(TARGETS
  abettor-c-bio
  DESTINATION
  ${LIB_INSTALL_DIR}
)

add_custom_target(uninstall
  COMMAND rm -rfv ${LIB_INSTALL_DIR}/libabettor-c*
  COMMAND rm -rfv ${HEADERS_INSTALL_DIR}/org/labcrypto/abettor
)
