//
// Created by AirohpuE on 11/8.
//
#include "../head/generateRandomMatrix.h"
using namespace std;


Matrix genRandMatrix(int len, int wid, int randSeed){
    default_random_engine randE(randSeed);
    uniform_real_distribution<float> randF(0, 100);

    Matrix m = Matrix(len, wid);
    for(int i = 0; i < m.len; i++) {
        for (int j = 0; j < m.wid; j++) {
            m.matrix[i][j] = randF(randE);
        }
    }

    return m;
}




