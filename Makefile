
CC = g++
# change this line to location of googletest root directory
GTEST_ROOT = ../googletest/googletest
MAIN_DIR = .
TESTS_DIR = $(MAIN_DIR)/tests
# TODO create bin and build directory if it doesn't exist
OBJS_DIR = $(MAIN_DIR)/build
BIN_DIR = $(MAIN_DIR)/bin
SRCS = $(TESTS_DIR)
HDRS = $(MAIN_DIR)/headers
LIBS = -L$(GTEST_ROOT)/make -lgtest -pthread
INCLUDES = -I$(GTEST_ROOT)/include \
			  -I$(HDRS)
CXXFLAGS = -std=c++11 -g -Wall $(LIBS) $(INCLUDES)

all: tests

tests: $(BIN_DIR)/unitTest1

$(OBJS_DIR)/unitTest1.o: $(TESTS_DIR)/unitTest1.cpp $(HDRS)/ArrayList.h
	$(CC)  -c $< -o $@ $(CXXFLAGS)

$(BIN_DIR)/unitTest1: $(OBJS_DIR)/unitTest1.o
	$(CC)   $< -o $@ $(CXXFLAGS)

# TODO probably add a phony rule for creating those directories
.PHONY: clean
clean:
	rm -f $(OBJS_DIR)/*.o $(BIN_DIR)/*