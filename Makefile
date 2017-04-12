
CC = g++
# change this line to location of googletest root directory
GTEST_ROOT = ../googletest/googletest
MAIN_DIR = .
TESTS_DIR = $(MAIN_DIR)/tests
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

$(OBJS_DIR)/unitTest1.o: $(TESTS_DIR)/unitTest1.cpp $(HDRS)/ArrayList.h $(HDRS)/LinkedList.h $(HDRS)/Node.h $(HDRS)/List.h $(OBJS_DIR)/.dirstamp
	$(CC)  -c $< -o $@ $(CXXFLAGS)

$(BIN_DIR)/unitTest1: $(OBJS_DIR)/unitTest1.o $(BIN_DIR)/.dirstamp
	$(CC)   $< -o $@ $(CXXFLAGS)

# make sure that $(OBJS_DIR) and $(BIN_DIR) exist
$(OBJS_DIR)/.dirstamp:
	mkdir -p $(OBJS_DIR)
	touch $(OBJS_DIR)/.dirstamp

$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp

.PHONY: clean
clean:
	rm -f $(OBJS_DIR)/*.o $(BIN_DIR)/*