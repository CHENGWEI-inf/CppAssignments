#include "../head/FullConnection.h"

float *fullConnection(float *input_tensor, fc_param fcParam) {
    int output_size = fcParam.out_features;
    float * out_features = new float[output_size];
    for(int i = 0; i < output_size; i++){
        out_features[i] = tensorMul(input_tensor, fcParam.p_weight + i * fcParam.in_features, fcParam.in_features);
        out_features[i] += fcParam.p_bias[i];
    }
    return out_features;
}

float tensorMul(const float *tensor1, const float *tensor2, int size) {
    float sum = 0;
    for(int i = 0; i < size; i++){
        sum += tensor1[i] * tensor2[i];
    }
    return sum;
}
