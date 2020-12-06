#ifndef MATRIXALGORITHMSUTIL_H
#define MATRIXALGORITHMSUTIL_H

#include "../head/Matrix.h"

Matrix add_matrix(const Matrix *m1, Matrix m2);
Matrix sub_matrix(const Matrix *m1, Matrix m2);
Matrix multiply_matrix (const Matrix *const m1, Matrix m2);
Matrix num_mul_matrix(Matrix m1, float n);

#endif //MATRIXALGORITHMSUTIL_H

