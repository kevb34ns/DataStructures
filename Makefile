
CC = g++
# change this line to location of googletest root directory
GTEST_ROOT = ../googletest
MAIN_DIR = .
TESTS_DIR = $(MAIN_DIR)/tests
# TODO create bin and build directory if it doesn't exist
OBJS_DIR = $(MAIN_DIR)/build
BIN_DIR = $(MAIN_DIR)/bin
SRCS = $(TESTS_DIR)
LIBS = -L$(GTEST_ROOT)/make -lgtest
INCLUDES = -I$(GTEST_ROOT)/include \
           -I$(MAIN_DIR)/headers
CXXFLAGS = -g -Wall $(LIBS) $(INCLUDES)

all: tests

tests: unitTest1

$(OBJS_DIR)/unitTest1.o: $(TESTS_DIR)/unitTest1.cpp ArrayList.h
   $(CC) $(CXXFLAGS) -c $(TESTS_DIR)/unitTest1 -o $@

$(BIN_DIR)/unitTest1: $(OBJS_DIR)/unitTest1.o
   $(CC) $(CXXFLAGS)  $(OBJS_DIR)/unitTest1.o -o $@

# TODO probably add a phony rule for creating those directories
.PHONY: clean
clean:
   rm -f $(OBJS_DIR)/*.o $(BIN_DIR)/*