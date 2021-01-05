#include <iostream>
#include <iomanip>

#include "head/ImageReader.h"
#include "head/model.h"
#include "test/test.h"

#include "head/Conv2D.h"

using namespace std;


float ** create_pseudo_img(int size = 5){
    srand(0);

    float ** res = new float* [size];
    for(int i = 0; i < size; i++){
        res[i] = new float[size];
        for(int j = 0; j < size; j++){
            res[i][j] = rand()%20;
        }
    }
    return res;
}

float  ** create_pseudo_kernel(){
    int size = 3;

    float ** res = new float* [size];
    for(int i = 0; i < size; i++){
        res[i] = new float[size];
        for(int j = 0; j < size; j++){
            res[i][j] = 1;
        }
    }
    return res;
}



int main() {

    // opencv compile reference: https://blog.csdn.net/adelagirl/article/details/89503715
    string file_path = "E:\\cppWork\\Assignments\\Project2\\files\\szw.jpg";
    ImageReader imageReader(file_path);
    float * rgbTensor = imageReader.toRGBTensor();

    float *features = run_model(rgbTensor, 128);
    cout << fixed << setprecision(5);
    cout << "background :" << features[0] * 100 << "%" << std::endl;
    cout << "human :" << features[1] * 100 << "%" << std::endl;

    return 0;
}

