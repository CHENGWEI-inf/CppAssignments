#ifndef PROJECT2_MAXPOOL_H
#define PROJECT2_MAXPOOL_H

#include <iostream>

float * maxPooling(float * input_tensor, int input_size, int kernel_size, int stride, int channels, int& output_size);

float getMax(const float * left_top_corner, int kernel_size, int input_size);



#endif //PROJECT2_MAXPOOL_H
