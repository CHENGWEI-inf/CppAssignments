#ifndef PROJECT2_FULLCONNECTION_H
#define PROJECT2_FULLCONNECTION_H
#include "../param/face_binary_cls.h"

float * fullConnection(float * input_tensor, fc_param fcParam);

float tensorMul(const float * tensor1, const float * tensor2, int size);


#endif //PROJECT2_FULLCONNECTION_H
