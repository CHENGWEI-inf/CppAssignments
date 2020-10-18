#include "..\head\plainDotProduct.h"
#include <iostream>

float dotProduct_plain(float* v1, float* v2, long long size) {
    float* ptr1 = v1;
    float* ptr2 = v2;
    double sum = 0;
    for(int i = 0; i < size; i++){
//        if(*ptr1 * *ptr2 > 1000000000.0)
//            std::cout << *ptr1 << " " << *ptr2 << endl;
        sum += *ptr1 * *ptr2;
        ptr1++;
        ptr2++;
    }
    return (float)sum;
}
