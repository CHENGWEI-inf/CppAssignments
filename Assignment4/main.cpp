#include <iostream>
#include "head/Matrix.h"


using namespace std;

Matrix genTestMatrix(int len, int wid);
void testBasicOperands();
void testFunctionalOperands();
void testMultiplyOperands();

int main(){
    testBasicOperands();
    testFunctionalOperands();
    testMultiplyOperands();
    return 0;
}

void testBasicOperands(){
    cout << endl;
    cout << "Basic Tests" << endl;
    Matrix m1 = genTestMatrix(3,3);
    Matrix m2 = genTestMatrix(3,3);
    cout << "this is m1: " << endl;
    cout << m1 << endl;
    cout << "this is m2: " << endl;
    cout << m2 << endl;
    cout << "m3 = m1 + m2: " << endl;
    Matrix m3 = m1 + m2;
    cout << m3 << endl;
    cout << "m4 = m1 - m2: " << endl;
    Matrix m4 = m1 - m2;
    cout << m4 << endl;
}

void testFunctionalOperands(){
    cout << endl;
    cout << "Equal, Assignment and Ostream Tests" << endl;
    Matrix m1 = genTestMatrix(3,3);
    Matrix m2 = Matrix(3, 3);
    cout << "this is m1(cout << m1): " << endl;
    cout << m1 << endl;
    cout << "this is m2: " << endl;
    cout << m2 << endl;
    cout << "test copy : m3 = m1 " << endl;
    Matrix m3 = m1;
    cout << m3 << endl;
    cout << "test equal : m1 == m3 " << endl;
    cout << (m1 == m3) << endl;
    cout << "test equal : m1 == m2 " << endl;
    cout << (m1 == m2) << endl;
}

void testMultiplyOperands() {
    cout << endl;
    cout << "Multiply Tests" << endl;
    Matrix m1 = genTestMatrix(3, 3);
    Matrix m2 = genTestMatrix(3, 3);
    cout << "this is m1: " << endl;
    cout << m1 << endl;
    cout << "this is m2: " << endl;
    cout << m2 << endl;
    cout << "m3 = m1 * m2: " << endl;
    Matrix m3 = m1 * m2;
    cout << m3 << endl;
    cout << "m4 = m1 * 2: " << endl;
    Matrix m4 = m1 * 2;
    cout << m4 << endl;
    cout << "m5 = 2.01 * m2: " << endl;
    Matrix m5 = 2.01 * m2;
    cout << m5 << endl;
}

Matrix genTestMatrix(int len, int wid){
    float ** m = new float * [len];
    float tag = 1;
    for(int i = 0; i < len; i++){
        m[i] = new float[wid];
        for(int j = 0; j < wid; j++){
            m[i][j] = tag;
            tag++;
        }
    }

    return Matrix(len, wid, m);
}