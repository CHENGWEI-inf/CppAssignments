#ifndef PROJECT1_ADVANCEDMATRIXPRODUCT_H
#define PROJECT1_ADVANCEDMATRIXPRODUCT_H
#include "matrix.h"

Matrix productOnDiffStrategy(Matrix m1, Matrix m2);

Matrix optimizedMatrixProduct(Matrix m1, Matrix m2);

Matrix concurrentMatrixProduct(Matrix m1, Matrix m2);

void blockOfMatrix(Matrix m, Matrix * subs);

float ** blockOfMatrixV2(Matrix m);


#endif //PROJECT1_ADVANCEDMATRIXPRODUCT_H
