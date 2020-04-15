#
# 20200101
# BurgessKzg
#
# make tool=x86_gcc
# make tool=x86_g++
# make tool=arm_gcc
# make tool=arm_g++
#

TARGET := App

LOCAL_LDFLAGS := -lpthread
LOCAL_LDFLAGS += -W

MAP_FILE_NAME := $(TARGET)
LOCAL_LDFLAGS += -Wl,-Map=./$(MAP_FILE_NAME).map

# x86_gcc ###################################################
ifeq ($(tool),x86_gcc)
SRCS := $(shell ls *.c)
OBJS := $(patsubst %.c,%.o,$(SRCS))

CC := gcc

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^ $(LOCAL_LDFLAGS)

%.o:%.c
	$(CC) -c -o $@ $< $(LOCAL_LDFLAGS)

# x86_g++ ###################################################
else ifeq ($(tool),x86_g++)

SRCS := $(shell ls *.cpp)
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

CC := g++

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^ $(LOCAL_LDFLAGS)

%.o:%.cpp
	$(CC) -c -o $@ $< $(LOCAL_LDFLAGS)

# arm_gcc ###################################################
else ifeq ($(tool),arm_gcc)

SRCS := $(shell ls *.c)
OBJS := $(patsubst %.c,%.o,$(SRCS))

CC := /usr/local/gcc-3.4.6-glibc-2.3.3/bin/aarch32-linux-gnu-gcc

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^ $(LOCAL_LDFLAGS)

%.o:%.c
	$(CC) -c -o $@ $< $(LOCAL_LDFLAGS)

# arm_g++ ###################################################
else ifeq ($(tool),arm_g++)

SRCS := $(shell ls *.cpp)
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

CC := /usr/local/gcc-3.4.6-glibc-2.3.3/bin/aarch32-linux-gnu-g++ 

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^ $(LOCAL_LDFLAGS)

%.o:%.cpp
	$(CC) -c -o $@ $< $(LOCAL_LDFLAGS)
endif
############################################################

ifneq ($(tool),)
.PHONY : PARAERROR
PARAERROR :
	@echo "Error : Parameters error."
	@exit
endif

ifeq ($(1),)
.PHONY : PARAEMPTY
PARAEMPTY :
	@echo "Error : Please enter parameters."
	@exit
endif

.PHONY : clean
clean :
	-rm -f $(TARGET) $(MAP_FILE_NAME).map *.o

