#include "../head/ConvLayer.h"
#include "../head/Conv2D.h"

#include "../test/test.h"

ConvLayer::ConvLayer(const conv_param &convParam, float *inputTensor, int input_size){
    this->input_size = input_size;
    this->input_tensor = inputTensor;
    this->convParam = convParam;

    this->output_size = (input_size - convParam.kernel_size + 2 * convParam.pad) / convParam.stride + 1;
    //output  size reference: https://blog.csdn.net/program_developer/article/details/80943707

    this->output_tensor = new float[convParam.out_channels * output_size * output_size];
    for(int i = 0; i < convParam.out_channels * output_size * output_size; i++)
        output_tensor[i] = 0;
}

float *ConvLayer::getOutputTensor() {
    return this->output_tensor;
}

void ConvLayer::doConvolution() {
    int kernel_size = this->convParam.kernel_size;

//    #pragma omp parallel for
    for(int i = 0; i < convParam.out_channels; i++){
        // pointer offset, to get each output channel kernel
        const float * this_output_ch_kernel = this->convParam.p_weight +
                i * this->convParam.in_channels * kernel_size * kernel_size;

        for(int j = 0; j < convParam.in_channels; j++){
            //pointer offset, this channel of input
            float * this_in_ch = input_tensor + j * input_size * input_size;

            //pointer offset, get each 3 * 3 kernel by input channels
            const float * this_kernel_tensor = this_output_ch_kernel +
                    j * kernel_size * kernel_size;
            //cast kernel tensor to kernel matrix
            float ** kernel = toMatrix(this_kernel_tensor, kernel_size);

            //conv
            float ** this_output_matrix =
                    conv2D(this_in_ch, kernel, convParam.stride, convParam.pad, this->input_size, kernel_size);

            //sum input channels, separate output channels
            for(int x = 0; x < output_size; x++){
                for(int y = 0; y < output_size; y++){
                    output_tensor[i * output_size * output_size
                    + x * output_size + y] += this_output_matrix[x][y];
                }
            }
        }

        // add bias
        int channel_size = output_size * output_size;
        float this_channel_bias = convParam.p_bias[i];
        for(int idx = 0; idx < channel_size; idx++){
            output_tensor[i * channel_size + idx] += this_channel_bias;
        }
    }
}
