#ifndef PROJECT2_CONV2D_H
#define PROJECT2_CONV2D_H

#include "../param/face_binary_cls.h"
#include "../test/test.h"
#include <iostream>
#include <string>
#include <sstream>


float convByWindow(float ** window, float ** kernel, int size);

float ** conv2D(const float * input_tensor1D, float ** kernel2D, int stride, int pad, int input_size, int kernel_size);

float * toTensor(float ** img2D, int img_size);

float ** toMatrix(const float * tensor, int size);



#endif //PROJECT2_CONV2D_H
