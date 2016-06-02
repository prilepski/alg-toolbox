CXXFLAGS =	-pipe -O2 -std=c++11
test: CXXFLAGS += -g -Wall

OBJS = 
TEST_OBJS = APlusB_test.o
EXEC = APlusB.o

LIBS = /opt/gtest/lib/gtest_main.a -lpthread
INCLUDES = -I/opt/gtest/include

TARGET = APlusB

RELEASE_DIR = ./Release
TEST_DIR = ./Test

RM = rm -rf
MKDIR = mkdir -p

OUT_DIR = 
all: OUT_DIR := $(RELEASE_DIR)
all: $(shell $(MKDIR) $(RELEASE_DIR))

test: OUT_DIR := $(TEST_DIR)
test: $(shell $(MKDIR) $(TEST_DIR))

#$TARGET = $(CXX) -o $(OUT_DIR)/$(TARGET) $(OUT_DIR)/$(OBJS) $(LIBS) $(INCLUDES)

all: $(EXEC) 
	$(CXX) -o $(OUT_DIR)/$(TARGET) $(OUT_DIR)/$(EXEC)

test: $(OBJS) $(TEST_OBJS)
	$(CXX) -o $(OUT_DIR)/$(TARGET) $(OUT_DIR)/$(TEST_OBJS) $(LIBS)
	@$(OUT_DIR)/$(TARGET)


clean:
	$(RM) $(RELEASE_DIR) $(TEST_DIR)
	
APlusB.o: APlusB.cpp
	$(CXX) $(CXXFLAGS) -c APlusB.cpp -o $(OUT_DIR)/APlusB.o

APlusB_test.o: ./tests/APlusB_test.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c ./tests/APlusB_test.cpp -o $(OUT_DIR)/APlusB_test.o
