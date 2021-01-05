#include "../head/MaxPool.h"

float *maxPooling(float *input_tensor, int input_size, int kernel_size, int stride, int channels, int& output_size) {
    output_size = (input_size - kernel_size) / stride + 1;
    float * output_tensor = new float[channels * output_size * output_size];

    for(int ch = 0; ch < channels; ch++) {
        int idx = 0;
        float * this_input_channel = input_tensor + ch * input_size * input_size;
        for (int i = 0; i + kernel_size <= input_size; i += stride) {
            for (int j = 0; j + kernel_size <= input_size; j += stride) {
                float max = getMax(this_input_channel + i * input_size + j, kernel_size, input_size);
                output_tensor[ch * output_size * output_size + idx] = max;
                idx++;
            }
        }
    }

    return output_tensor;
}

float getMax(const float *left_top_corner, int kernel_size, int input_size) {
    float max = * left_top_corner;
    for(int i = 0; i < kernel_size; i++){
        for(int j = 0; j < kernel_size; j++){
            float tmp = left_top_corner[i * input_size + j];
            if(tmp > max)
                max = tmp;
        }
    }
    return max;
}
