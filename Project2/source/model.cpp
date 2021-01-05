#include "../head/model.h"
using namespace std;

float * run_model(float *rgbTensor, int img_size) {
    ConvLayer conv0(conv_params[0], rgbTensor, img_size);
    conv0.doConvolution();
    float * out0 = conv0.getOutputTensor();
    int out0_size = conv0.output_size;

    int pool0_size = 0;
    float * pool0 = maxPooling(out0, out0_size, 2, 2, conv_params[0].out_channels, pool0_size);
    ReLU(pool0, pool0_size * pool0_size * conv_params[0].out_channels);

    // out0 is useless
    delete [] out0;

    ConvLayer conv1(conv_params[1], pool0, pool0_size);
    conv1.doConvolution();
    float * out1 = conv1.getOutputTensor();
    int out1_size = conv1.output_size;

    // pool0 is useless
    delete [] pool0;

    int pool1_size = 0;
    float * pool1 = maxPooling(out1, out1_size, 2, 2, conv_params[1].out_channels, pool1_size);
    ReLU(pool1, pool1_size * pool1_size * conv_params[1].out_channels);

    // out1 is useless
    delete [] out1;

    ConvLayer conv2(conv_params[2], pool1, pool1_size);
    conv2.doConvolution();
    float * out2 = conv2.getOutputTensor();
    int out2_size = conv2.output_size;

    // pool1 is useless
    delete [] pool1;

    ReLU(out2, out2_size * out2_size * conv_params[2].out_channels);

    float * features = fullConnection(out2, fc_params[0]);
    // softmax
    softMax(features, fc_params[0].out_features);

    // out2 is useless
    delete [] out2;

    return features;
}
