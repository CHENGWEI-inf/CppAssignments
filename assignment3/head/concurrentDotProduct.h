#ifndef CONCURRENTDOTPRODUCT_H
#define CONCURRENTDOTPRODUCT_H

float dotProduct_concurrent(float* v1, float* v2, long long size);

double threadDotProduct(float* a, float* b, long long size, double &ans);

float sepDotP(float* a, float* b, long long size);


#endif //CONCURRENTDOTPRODUCT_H
