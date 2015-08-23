C = gcc -g -Wall -Wno-pointer-sign -Wno-comment -fPIC
CC = g++ -g -Wall
AR = ar -cq
CFLAGS = 
LIBS = -lssl -lcrypto
LIB_DIR=.lib
SYMLINK = ln -s
RM = rm -rfv

SRCS = log.c

TEST_SRCS = 

OBJS = $(SRCS:.c=.o)
TEST_OBJS = $(TEST_SRCS:.c=.o)

OBJECTS = $(addprefix $(LIB_DIR)/, $(OBJS))
TEST_OBJECTS = $(addprefix $(LIB_DIR)/, $(TEST_OBJS))

LIB_NAME = libnaeem-log
MAJOR_VERSION = 1
MINOR_VERSION = 1

all: dirs $(OBJECTS) $(TEST_OBJECTS) static dynamic
static:
	$(RM) $(LIB_DIR)/$(LIB_NAME).a.$(MAJOR_VERSION).$(MINOR_VERSION)
	$(AR) $(LIB_DIR)/$(LIB_NAME).a.$(MAJOR_VERSION).$(MINOR_VERSION) $(OBJECTS)
	$(RM) $(LIB_DIR)/$(LIB_NAME).a.$(MAJOR_VERSION)    
	$(SYMLINK) $(LIB_NAME).a.$(MAJOR_VERSION).$(MINOR_VERSION) $(LIB_DIR)/$(LIB_NAME).a.$(MAJOR_VERSION)
	$(RM) $(LIB_DIR)/$(LIB_NAME).a
	$(SYMLINK) $(LIB_NAME).a.$(MAJOR_VERSION) $(LIB_DIR)/$(LIB_NAME).a
dynamic:
	$(C) -shared -Wl,-soname,$(LIB_NAME).so.$(MAJOR_VERSION) -o $(LIB_DIR)/$(LIB_NAME).so.$(MAJOR_VERSION).$(MINOR_VERSION) $(OBJECTS) $(LIBS)
	$(RM) $(LIB_DIR)/$(LIB_NAME).so.$(MAJOR_VERSION)
	$(SYMLINK) $(LIB_NAME).so.$(MAJOR_VERSION).$(MINOR_VERSION) $(LIB_DIR)/$(LIB_NAME).so.$(MAJOR_VERSION)
	$(RM) $(LIB_DIR)/$(LIB_NAME).so
	$(SYMLINK) $(LIB_NAME).so.$(MAJOR_VERSION) $(LIB_DIR)/$(LIB_NAME).so
$(LIB_DIR)/%.o: %.c
	$(C) -c $(CFLAGS) $< -o $@
dirs:
	mkdir -p $(LIB_DIR)
clean:
	$(RM) $(LIB_DIR)/*.o
	$(RM) $(READ_APP_NAME) $(ISSUE_APP_NAME) $(ENABLE_BAC_APP_NAME) $(LOCK_APP_NAME) \
	      $(STAT_APP_NAME) $(SOD_APP_NAME) $(AA_APP_NAME)
