cmake_minimum_required(VERSION 2.8.3)

project(cmake_test)

add_definitions(-DWITH_SOMELIB)

add_executable(cmake_test cmake_test.cpp)

find_package(OpenCV REQUIRED)

##if(OpenCV_FOUND)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(cmake_test ${OpenCV_LIBS})
##endif(OpenCV_FOUND)

##add_dependencies(cmake_test)
