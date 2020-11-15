# include "../head/advancedMatrixProduct.h"
# include "../head/plainMatrixProduct.h"
#include "../head/strassen.h"
# include <omp.h>

void blockOfMatrix(Matrix m, Matrix subs[]){
    // always separate block in middle, if odd, always divide to [n/2, n/2 + 1]
    subs[0] = Matrix(m.len/2, m.wid/2, m.matrix);  // left up

    subs[1] = Matrix((m.len - m.len/2), m.wid/2); // left down
    for(int i = 0; i < subs[1].len; i++){
        subs[1].matrix[i] = m.matrix[i + m.len/2];
    }

    subs[2] = Matrix(m.len/2, (m.wid - m.wid/2)); // right up
    for(int i = 0; i < subs[2].len; i++){
        subs[2].matrix[i] = m.matrix[i] + m.wid/2;
    }

    subs[3] = Matrix((m.len - m.len/2),(m.wid - m.wid/2));
    for(int i = 0; i < subs[3].len; i++){
        subs[3].matrix[i] = m.matrix[i + m.len/2] + m.wid/2;
    }

//    Matrix sub_block_ptrs[] = {m1, m2, m3, m4};
//    subs = sub_block_ptrs;
}

float ** blockOfMatrixV2(Matrix m){
    static float ** right_half = new float * [m.len];
    for(int i = 0; i < m.len; i++){
        right_half[i] = m.matrix[i] + m.wid/2;
    }
    return right_half;
}


/*
  ---------------------------
  =            =            =
  =      A     =     B      =
  =            =            =
  ----------------------------
  =            =            =
  =      C     =     D      =
  =            =            =
  ----------------------------
  case 0: A1B1 * A2C2, case 1: A1B1 * B2D2, case 2: C1D1 * A2C2, case 3: C1D1 * B2D2
 */

Matrix concurrentMatrixProduct(Matrix m1, Matrix m2){
    Matrix res = Matrix(m1.len, m2.wid);

    #pragma omp parallel for
    for(int i = 0; i < 4; i++){
        // init sub_m1
        Matrix sub_m1 = Matrix(0,0);
        Matrix sub_m2 = Matrix(0,0);
        Matrix tmp = Matrix(0,0);

        switch (i) {
            case 0:
                sub_m1 = Matrix(m1.len/2, m1.wid, m1.matrix);
                sub_m2 = Matrix(m2.len,m2.wid/2, m2.matrix);

                tmp = productOnDiffStrategy(sub_m1,sub_m2);
                for(int line = 0; line < tmp.len; line++){
                    for(int col = 0; col < tmp.wid; col++){
                        res.matrix[line][col] = tmp.matrix[line][col];
                    }
                }
                delete tmp.matrix;

                break;
            case 1:
                sub_m1 = Matrix(m1.len/2, m1.wid, m1.matrix);
                sub_m2 = Matrix(m2.len, m2.wid - m2.wid/2, blockOfMatrixV2(m2));

                tmp = productOnDiffStrategy(sub_m1,sub_m2);
                for(int line = 0; line < tmp.len; line++){
                    for(int col = 0; col < tmp.wid; col++){
                        res.matrix[line][col + m2.wid/2] = tmp.matrix[line][col];
                    }
                }
                delete tmp.matrix;

                break;
            case 2:
                sub_m1 = Matrix(m1.len - m1.len/2, m1.wid, m1.matrix + m1.len/2);
                sub_m2 = Matrix(m2.len,m2.wid/2, m2.matrix);

                tmp = productOnDiffStrategy(sub_m1,sub_m2);
                for(int line = 0; line < tmp.len; line++){
                    for(int col = 0; col < tmp.wid; col++){
                        res.matrix[line + m1.len/2][col] = tmp.matrix[line][col];
                    }
                }
                delete tmp.matrix;

                break;
            case 3:
                sub_m1 = Matrix(m1.len - m1.len/2, m1.wid, m1.matrix + m1.len/2);
                sub_m2 = Matrix(m2.len, m2.wid - m2.wid/2, blockOfMatrixV2(m2));

                tmp = productOnDiffStrategy(sub_m1,sub_m2);
                for(int line = 0; line < tmp.len; line++){
                    for(int col = 0; col < tmp.wid; col++){
                        res.matrix[line + m1.len/2][col + m2.wid/2] = tmp.matrix[line][col];
                    }
                }
                delete tmp.matrix;

                break;
            default:
                break;
        }
    }

    return res;
}

Matrix optimizedMatrixProduct(Matrix m1, Matrix m2){

    Matrix res = Matrix(m1.len, m2.wid);
    for(int i = 0; i < m1.len; i++){
        for(int j = 0; j < m1.wid; j++){
            float s = m1.matrix[i][j];
            for(int k = 0; k < m2.wid; k++){
                res.matrix[i][k] += s * m2.matrix[j][k];
            }
        }
    }
    return res;
}

Matrix productOnDiffStrategy(Matrix m1, Matrix m2){
    if(m1.len == m1.wid && m2.len == m2.wid){
        return strassen(m1, m2);
    } else
        return optimizedMatrixProduct(m1, m2);
}

//Matrix separateLineProduct(Matrix m1){
//    //Notice My CPU (intel i7-6700HQ) has L1 cache 64KB, L2 cache 256KB, L3 cache 6MB
//}