#include "../head/strassen.h"

Matrix add_matrix(Matrix m1, Matrix m2) {
    Matrix m3 = Matrix(m1.len, m1.wid);

    for(int i = 0; i < m3.len; i++){
        for(int j = 0; j < m3.wid; j++){
            m3.matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
        }
    }
    return m3;
}

Matrix sub_matrix(Matrix m1, Matrix m2) {
    Matrix m3 = Matrix(m1.len, m1.wid);

    for(int i = 0; i < m3.len; i++){
        for(int j = 0; j < m3.wid; j++){
            m3.matrix[i][j] = m1.matrix[i][j] - m2.matrix[i][j];
        }
    }
    return m3;
}

Matrix strassen(Matrix mA, Matrix mB) {
    // A, B, ms reference from : https://www.jianshu.com/p/dc67e4a3c841
    if(mA.len < 200)
        return optimizedMatrixProduct(mA, mB);

    Matrix sub_As[4];
    blockOfMatrix(mA, sub_As);
    Matrix sub_Bs[4];
    blockOfMatrix(mB, sub_Bs);

    Matrix m1 = strassen(add_matrix(sub_As[0],sub_As[3]), add_matrix(sub_Bs[0],sub_Bs[3]));
    Matrix m2 = strassen(add_matrix(sub_As[1],sub_As[3]), sub_Bs[0]);
    Matrix m3 = strassen(sub_As[0], sub_matrix(sub_Bs[2],sub_Bs[3]));
    Matrix m4 = strassen(sub_As[3], sub_matrix(sub_Bs[1],sub_Bs[0]));
    Matrix m5 = strassen(add_matrix(sub_As[0],sub_As[2]), sub_Bs[3]);
    Matrix m6 = strassen(sub_matrix(sub_As[1],sub_As[0]), add_matrix(sub_Bs[0],sub_Bs[2]));
    Matrix m7 = strassen(sub_matrix(sub_As[2],sub_As[3]), add_matrix(sub_Bs[1],sub_Bs[3]));

//    m1.printMatrix();
//    m2.printMatrix();
//    m3.printMatrix();
//    m4.printMatrix();
//    m5.printMatrix();
//    m6.printMatrix();
//    m7.printMatrix();


    Matrix c_1_1 = sub_matrix(add_matrix(m1, m4), sub_matrix(m5, m7));
    Matrix c_1_2 = add_matrix(m3, m5);
    Matrix c_2_1 = add_matrix(m2, m4);
    Matrix c_2_2 = add_matrix(sub_matrix(m1, m2), add_matrix(m3, m6));

    Matrix res = Matrix(mA.len, mA.wid);

    for(int line = 0; line < c_1_1.len; line++){
        for(int col = 0; col < c_1_1.wid; col++){
            res.matrix[line][col] = c_1_1.matrix[line][col];
        }
    }

    for(int line = 0; line < c_1_2.len; line++){
        for(int col = 0; col < c_1_2.wid; col++){
            res.matrix[line][col + res.wid/2] = c_1_2.matrix[line][col];
        }
    }

    for(int line = 0; line < c_2_1.len; line++){
        for(int col = 0; col < c_2_1.wid; col++){
            res.matrix[line + res.len/2][col] = c_2_1.matrix[line][col];
        }
    }

    for(int line = 0; line < c_2_2.len; line++){
        for(int col = 0; col < c_2_2.wid; col++){
            res.matrix[line + res.len/2][col + res.wid/2] = c_2_2.matrix[line][col];
        }
    }

    return res;
}
