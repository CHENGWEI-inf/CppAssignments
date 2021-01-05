#include "../head/SoftMax.h"

void softMax(float *features, int n) {
    float sum = 0;
    for (int i = 0; i < n; i++)
        sum += exp(features[i]);

    for(int i = 0; i < n; i++)
        features[i] = exp(features[i]) / sum;
}
