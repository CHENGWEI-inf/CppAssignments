#include "../head/matrixAlgorithmsUtil.h"

Matrix add_matrix(const Matrix *m1, Matrix m2) {
    Matrix m3 = Matrix(m1->getLen(), m1->getWid());

    for(int i = 0; i < m3.getLen(); i++){
        for(int j = 0; j < m3.getWid(); j++){
            m3.getMatrix()[i][j] = m1->getMatrix()[i][j] + m2.getMatrix()[i][j];
        }
    }
    return m3;
}

Matrix sub_matrix(const Matrix *m1, Matrix m2) {
    Matrix m3 = Matrix(m1->getLen(), m1->getWid());

    for(int i = 0; i < m3.getLen(); i++){
        for(int j = 0; j < m3.getWid(); j++){
            m3.getMatrix()[i][j] = m1->getMatrix()[i][j] - m2.getMatrix()[i][j];
        }
    }
    return m3;
}


Matrix multiply_matrix (const Matrix* m1, Matrix m2){

    Matrix res = Matrix(m1->getLen(), m2.getWid());
    for(int i = 0; i < m1->getLen(); i++){
        for(int j = 0; j < m1->getWid(); j++){
            float s = m1->getMatrix()[i][j];
            for(int k = 0; k < m2.getWid(); k++){
                res.getMatrix()[i][k] += s * m2.getMatrix()[j][k];
            }
        }
    }
    return res;
}


Matrix num_mul_matrix(Matrix m1, float n){
    for(int i = 0; i < m1.getLen(); i++){
        for(int j = 0; j < m1.getWid(); j++){
            m1.getMatrix()[i][j] *= n;
        }
    }
    return m1;
}