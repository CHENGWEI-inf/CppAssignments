#ifndef ASSIGNMENT4_MATRIX_H
#define ASSIGNMENT4_MATRIX_H

#include <iostream>

using namespace std;

class Matrix {

private:
    float ** matrix;
    int len;
    int wid;

public:
    Matrix(int len, int wid);

    Matrix(int len, int wid, float ** matrix);

    Matrix() {}

    float **getMatrix() const;

    int getLen() const;
    int getWid() const;

    Matrix operator +(const Matrix & other) const;
    Matrix operator -(const Matrix & other) const;

    Matrix & operator =(const Matrix & other);
    bool operator ==(const Matrix & other) const;
    void printMatrix();

    Matrix operator *(const Matrix & other) const;
    Matrix operator *(const float & num) const;
    friend Matrix operator*(float num, const Matrix& other);

    void setLen(int len);
};

ostream & operator<<(ostream & os, const Matrix & m);

#endif //ASSIGNMENT4_MATRIX_H
