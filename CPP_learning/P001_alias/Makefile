# Makefile_header
CXX = g++
TARGET = alias_test
CXXFLAGS = -Wall -O2 -pipe
SRCS = alias.cpp #print.cpp
OBJS := $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS)

clean:
	rm -f $(TARGET) $(OBJS)

clean_all:
	rm -f $(TARGET) $(OBJS) *~

