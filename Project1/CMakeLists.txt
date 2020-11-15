cmake_minimum_required(VERSION 3.17)
project(Project1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project1 main.cpp head/matrix.h src/generateRandomMatrix.cpp head/generateRandomMatrix.h
        head/plainMatrixProduct.h head/advancedMatrixProduct.h src/advancedMatrixProduct.cpp src/plainMatrixProduct.cpp head/strassen.h src/strassen.cpp)

# for open mp
FIND_PACKAGE(OpenMP REQUIRED)
if (OPENMP_FOUND)
    message("OPENMP FOUND")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif ()