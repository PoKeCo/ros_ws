# Makefile_header
CXX = g++
#CXX = gcc
TARGET = alias_test
CXXFLAGS = -Wall -O2 -pipe
#CXXFLAGS = -Wall -O3
#CXXFLAGS = -O3
SRCS = alias.cpp #print.cpp
OBJS := $(SRCS:.cpp=.o)
#LIB = -L/lib -lopencv_contrib -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_highgui -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_objdetect -lopencv_ocl -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_ts -lopencv_video -lopencv_videostab

LIB = -lopencv_core -lopencv_highgui
#LIB = `pkg-config opencv --libs`
INC = -I/usr/local/include/opencv -I/usr/include
#INC = `pkg-config opencv --cflags`

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(INC) $(LIB)

clean:
	rm -f $(TARGET) $(OBJS)

clean_all:
	rm -f $(TARGET) $(OBJS) *~

