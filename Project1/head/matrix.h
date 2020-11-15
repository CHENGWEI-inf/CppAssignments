#ifndef PROJECT1_MATRIX_H
#define PROJECT1_MATRIX_H
#include <iostream>

using namespace std;

struct Matrix{
    float ** matrix;
    int len;
    int wid;

    Matrix(int len, int wid) : len(len), wid(wid) {
        // init matrix
        matrix = new float * [len];
        for(int i = 0; i < len; i++) {
            matrix[i] = new float[wid];
            for(int j = 0; j < wid; j++){
                matrix[i][j] = 0.0f;
            }
        }
    }

    Matrix(int len, int wid, float ** matrix) : len(len), wid(wid), matrix(matrix) {}

    Matrix() {}

    float getElement(int l, int w) const{
        return matrix[l][w];
    }

    float * getLine(int l) const{
        return matrix[l];
    }

    void printMatrix(){
        for(int i = 0; i < len; i++){
            for (int j = 0; j < wid; j++){
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

#endif //PROJECT1_MATRIX_H
