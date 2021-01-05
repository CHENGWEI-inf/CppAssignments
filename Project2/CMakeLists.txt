cmake_minimum_required(VERSION 3.17)
project(Project2)

set(CMAKE_CXX_STANDARD 14)

set(OpenCV_DIR E://openCV//opencv//build)

add_executable(Project2 main.cpp source/Conv2D.cpp head/Conv2D.h
        param/face_binary_cls.cpp param/face_binary_cls.h
        source/ConvLayer.cpp head/ConvLayer.h
        source/ImageReader.cpp head/ImageReader.h
        source/model.cpp head/model.h
        test/test.cpp test/test.h
        source/MaxPool.cpp head/MaxPool.h
        source/FullConnection.cpp head/FullConnection.h
        source/ActivateFunction.cpp head/ActivateFunction.h source/SoftMax.cpp head/SoftMax.h)

# for opencv
find_package(OpenCV REQUIRED)
target_link_libraries(Project2 ${OpenCV_LIBS})

# for open mp
FIND_PACKAGE(OpenMP REQUIRED)
if (OPENMP_FOUND)
    message("OPENMP FOUND")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif ()