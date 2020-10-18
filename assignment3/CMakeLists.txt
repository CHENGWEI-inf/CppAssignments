cmake_minimum_required(VERSION 3.17)
project(assignment3)

set(CMAKE_CXX_STANDARD 14)

#set(INC_DIR lib/pthreads-w32-2-9-1-release/Pre-built.2/include)
#set(LINK_DIR lib/pthreads-w32-2-9-1-release/Pre-built.2/lib)

add_executable(assignment3 source/main.cpp source/plainDotProduct.cpp head/plainDotProduct.h head/InputReader.h source/InputReader.cpp head/concurrentDotProduct.h source/concurrentDotProduct.cpp)
#add_executable(assignment3  script/binary_file_write_script.cpp)
#add_executable(assignment3 test/tst.cpp)
#add_executable(assignment3 test/testMultiThreading.cpp)

#include_directories(${INC_DIR})
#link_directories(${LINK_DIR})
