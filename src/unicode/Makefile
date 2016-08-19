#  The MIT License (MIT)
#
#  Copyright (c) 2015 LabCrypto Org.
#
#  Permission is hereby granted, free of charge, to any person obtaining a copy
#  of this software and associated documentation files (the "Software"), to deal
#  in the Software without restriction, including without limitation the rights
#  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
#  copies of the Software, and to permit persons to whom the Software is
#  furnished to do so, subject to the following conditions:
#  
#  The above copyright notice and this permission notice shall be included in all
#  copies or substantial portions of the Software.
#  
#  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
#  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
#  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
#  SOFTWARE.
#

PWD=$(shell pwd)
C = gcc -g -Wall -Wno-pointer-sign -Wno-comment -fPIC -I../../LabCryptoOrg-abettor-c-api/include
CC = g++ -g -Wall
CP = cp -rfv
AR = ar -cq
CFLAGS = 
LIBS =
LIB_DIR=.lib
API_LIB_DIR=../../LabCryptoOrg-abettor-c-api/lib/gcc-amd64
SYMLINK = ln -s
RM = rm -rfv

SRCS = unicode.c

TEST_SRCS = 

OBJS = $(SRCS:.c=.o)
TEST_OBJS = $(TEST_SRCS:.c=.o)

OBJECTS = $(addprefix $(LIB_DIR)/, $(OBJS))
TEST_OBJECTS = $(addprefix $(LIB_DIR)/, $(TEST_OBJS))

LIB_NAME = libabettor-unicode
MAJOR_VERSION = 1
MINOR_VERSION = 0

all: dirs $(OBJECTS) $(TEST_OBJECTS) static dynamic
static:
	$(RM) $(LIB_DIR)/$(LIB_NAME).a.$(MAJOR_VERSION).$(MINOR_VERSION)
	$(AR) $(LIB_DIR)/$(LIB_NAME).a.$(MAJOR_VERSION).$(MINOR_VERSION) $(OBJECTS)
	$(RM) $(API_LIB_DIR)/$(LIB_NAME).a.$(MAJOR_VERSION).$(MINOR_VERSION)
	$(CP) $(LIB_DIR)/$(LIB_NAME).a.$(MAJOR_VERSION).$(MINOR_VERSION) $(API_LIB_DIR)
	$(RM) $(API_LIB_DIR)/$(LIB_NAME).a.$(MAJOR_VERSION)    
	$(SYMLINK) $(PWD)/$(API_LIB_DIR)/$(LIB_NAME).a.$(MAJOR_VERSION).$(MINOR_VERSION) $(API_LIB_DIR)/$(LIB_NAME).a.$(MAJOR_VERSION)
	$(RM) $(API_LIB_DIR)/$(LIB_NAME).a
	$(SYMLINK) $(PWD)/$(API_LIB_DIR)/$(LIB_NAME).a.$(MAJOR_VERSION).$(MINOR_VERSION) $(API_LIB_DIR)/$(LIB_NAME).a
dynamic:
	$(RM) $(LIB_DIR)/$(LIB_NAME).so.$(MAJOR_VERSION).$(MINOR_VERSION)
	$(C) -shared -Wl,-soname,$(LIB_NAME).so.$(MAJOR_VERSION) -o $(LIB_DIR)/$(LIB_NAME).so.$(MAJOR_VERSION).$(MINOR_VERSION) $(OBJECTS) $(LIBS)
	$(RM) $(API_LIB_DIR)/$(LIB_NAME).so.$(MAJOR_VERSION).$(MINOR_VERSION)
	$(CP) $(LIB_DIR)/$(LIB_NAME).so.$(MAJOR_VERSION).$(MINOR_VERSION) $(API_LIB_DIR)
	$(RM) $(API_LIB_DIR)/$(LIB_NAME).so.$(MAJOR_VERSION)    
	$(SYMLINK) $(PWD)/$(API_LIB_DIR)/$(LIB_NAME).so.$(MAJOR_VERSION).$(MINOR_VERSION) $(API_LIB_DIR)/$(LIB_NAME).so.$(MAJOR_VERSION)
	$(RM) $(API_LIB_DIR)/$(LIB_NAME).so
	$(SYMLINK) $(PWD)/$(API_LIB_DIR)/$(LIB_NAME).so.$(MAJOR_VERSION).$(MINOR_VERSION) $(API_LIB_DIR)/$(LIB_NAME).so
$(LIB_DIR)/%.o: %.c
	$(C) -c $(CFLAGS) $< -o $@
dirs:
	mkdir -p $(LIB_DIR)
clean:
	$(RM) $(LIB_DIR)/*.o
	$(RM) $(READ_APP_NAME) $(ISSUE_APP_NAME) $(ENABLE_BAC_APP_NAME) $(LOCK_APP_NAME) \
	      $(STAT_APP_NAME) $(SOD_APP_NAME) $(AA_APP_NAME)
