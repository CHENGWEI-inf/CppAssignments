#include "../head/Conv2D.h"

using namespace std;

float convByWindow(float ** window, float ** kernel, int size){
    float res = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            res += window[i][j] * kernel[i][j];
        }
    }
    return res;
}

float ** conv2D(const float *input_tensor2D, float **kernel2D, int stride, int pad, const int input_size, const int kernel_size) {
//    if(stride > kernel_size / 2){
//        stringstream err_msg_ss;
//        err_msg_ss << "invalid stride = " << stride << " for kernel size " << kernel_size;
//        cerr << err_msg_ss.str() << endl;
//        return nullptr;
//    }

    // kernel size should be odd and symmetric
    int half_size = kernel_size / 2;

    int output_size = (input_size - kernel_size + 2 * pad) / stride + 1;
    float ** result = new float * [output_size];
    int output_line_cnt = -1;

    for(int i = half_size - pad; i < input_size; i += stride){

        output_line_cnt++;
        result[output_line_cnt] = new float[output_size];
        int output_row_cnt = -1;

        for(int j = half_size - pad; j < input_size; j += stride){
            int left_edge = j - half_size;
            int top_edge = i - half_size;

            if (left_edge + pad < 0 || left_edge + kernel_size - pad > input_size) // unavailable range, not enough padded
                continue;
            if (top_edge + pad < 0 || top_edge + kernel_size - pad > input_size) // unavailable range, not enough padded
                continue;

            float ** window = new float * [kernel_size];
            for(int x = 0; x < kernel_size; x++){
                window[x] = new float[kernel_size];
                for (int y = 0; y < kernel_size; y++) {
                    if(top_edge + x < 0 || left_edge + y < 0)
                        window[x][y] = 0;
                    else if(top_edge + x >= input_size || left_edge + y >= input_size)
                        window[x][y] = 0;
                    else
                        window[x][y] = input_tensor2D[(top_edge + x) * input_size + (left_edge + y)];
                }
            }

            output_row_cnt++;
            result[output_line_cnt][output_row_cnt] = convByWindow(window, kernel2D, kernel_size);
        }

        if(output_row_cnt == -1)  // this line is empty
            output_line_cnt--;
    }

    return result;
}

float * toTensor(float ** img2D, int size){
    float * tensor = new float[size * size];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            tensor[i * size + j] = img2D[i][j];
        }
    }
    return tensor;
}

float ** toMatrix(const float * tensor, int size){
    float ** img2D = new float * [size];
    for(int i = 0; i < size; i++){
        img2D[i] = new float [size];
        for(int j = 0; j < size; j++){
            img2D[i][j] = tensor[i * size + j];
        }
    }
    return img2D;
}