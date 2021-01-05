#include "../head/ActivateFunction.h"

void ReLU(float *tensor, int size) {
    for(int i = 0; i < size; i++){
        if(tensor[i] < 0) tensor[i] = 0;
    }
}
