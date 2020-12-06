cmake_minimum_required(VERSION 3.17)
project(Assignment4)

set(CMAKE_CXX_STANDARD 14)

add_executable(Assignment4 main.cpp source/Matrix.cpp head/Matrix.h source/matrixAlgorithmsUtil.cpp head/matrixAlgorithmsUtil.h)