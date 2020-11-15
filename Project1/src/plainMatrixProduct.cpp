#include "../head/plainMatrixProduct.h"

Matrix plainMatrixProduct(Matrix m1, Matrix m2){
    Matrix result = Matrix(m1.len, m2.wid);
    for(int i = 0; i < m1.len; i++){
        for(int j = 0; j < m2.wid; j++){
            for(int k = 0; k < m2.len; k++){
                result.matrix[i][j] += m1.matrix[i][k] * m2.matrix[k][j];
            }
        }
    }
    return result;
}