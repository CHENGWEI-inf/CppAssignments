#ifndef PROJECT2_CONVLAYER_H
#define PROJECT2_CONVLAYER_H
#include <iostream>
#include <omp.h>
#include "../param/face_binary_cls.h"

class ConvLayer {
private:
    conv_param convParam{};
    int input_size; // input size only for wid==len
    float * input_tensor; // [in_channels, width, length] wid,len should be same
    float * output_tensor;

public:
    int output_size;
    ConvLayer(const conv_param &convParam, float *inputTensor, int input_shape);
    void doConvolution();
    float * getOutputTensor();
};


#endif //PROJECT2_CONVLAYER_H
