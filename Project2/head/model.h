#ifndef PROJECT2_MODEL_H
#define PROJECT2_MODEL_H

#include "../param/face_binary_cls.h"
#include "../head/ConvLayer.h"
#include "../head/MaxPool.h"
#include "../head/FullConnection.h"
#include "../head/ActivateFunction.h"
#include "../head/SoftMax.h"

#include <iostream>

float * run_model(float * rgbTensor, int img_size);


#endif //PROJECT2_MODEL_H
