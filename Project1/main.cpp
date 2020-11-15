#include <iostream>
#include <chrono>
//#include "head/matrix.h"
#include "head/generateRandomMatrix.h"
#include "head/plainMatrixProduct.h"
# include "head/advancedMatrixProduct.h"
#include "head/strassen.h"

using namespace std;

// returns L1,W1,L2,W2, returns -1 for invalid input
void getInput(int& L1, int& W1, int& L2, int& W2, bool& err);

int main() {
//    // Result Valid Proper ------------------------------
//
//    cout << "compile success" << endl;
//    cout << "Check Proper Result: " << endl;
//    cout << "-----------------------------" << endl;
//    Matrix m1 = genRandMatrix(4,4, 0);
//    Matrix m2 = genRandMatrix(4,4, 1);
//
//    cout << "Random generated m1: " << endl;
//    m1.printMatrix();
//    cout << "-----------------------------" << endl;
//    cout << "Random generated m2: " << endl;
//    m2.printMatrix();
//    cout << "-----------------------------" << endl;
//
//    Matrix res = plainMatrixProduct(m1, m2);
//    cout << "Result for plain method: " << endl;
//    res.printMatrix();
//    cout << "-----------------------------" << endl;
//
//    res = optimizedMatrixProduct(m1, m2);
//    cout << "Result for better memory caching method: " << endl;
//    res.printMatrix();
//    cout << "-----------------------------" << endl;
//
//    res = strassen(m1,m2);
//    cout << "Result for Strassen method: " << endl;
//    res.printMatrix();
//    cout << "-----------------------------" << endl;
//
//    res = concurrentMatrixProduct(m1,m2);
//    cout << "Result for Concurrent method: " << endl;
//    res.printMatrix();
//    cout << "-----------------------------" << endl;
//
//    //  end Result Valid Proper ------------------------------


// METRIC FOR PERFORMANCE -----------------------------------------

    int L1, L2, W1, W2;
    bool err;
    getInput(L1, W1, L2, W2, err);
    if(err)
        return -1;

    Matrix m1 = genRandMatrix(L1,W1,0);
    Matrix m2 = genRandMatrix(L2,W2,1);

    cout << "-----------------------------" << endl;
    auto t1_p = chrono::steady_clock::now();
    Matrix res = plainMatrixProduct(m1, m2);
    auto t2_p = chrono::steady_clock::now();
    double p_time_duration_ms = chrono::duration<double,milli>(t2_p - t1_p).count();
    cout << "the time consuming of plain method is: " << p_time_duration_ms << " ms" << endl;

    cout << "-----------------------------" << endl;
    auto t1_c = chrono::steady_clock::now();
    Matrix res2 = optimizedMatrixProduct(m1, m2);
    auto t2_c = chrono::steady_clock::now();
    double c_time_duration_ms = chrono::duration<double,milli>(t2_c - t1_c).count();
    cout << "the time consuming of caching method is: " << c_time_duration_ms << " ms" << endl;

    cout << "-----------------------------" << endl;
    auto t1_s = chrono::steady_clock::now();
    Matrix res3 = strassen(m1, m2);
    auto t2_s = chrono::steady_clock::now();
    double s_time_duration_ms = chrono::duration<double,milli>(t2_s - t1_s).count();
    cout << "the time consuming of strassen method is: " << s_time_duration_ms << " ms" << endl;

    cout << "-----------------------------" << endl;
    auto t1_o = chrono::steady_clock::now();
    Matrix res4 = concurrentMatrixProduct(m1, m2);
    auto t2_o = chrono::steady_clock::now();
    double o_time_duration_ms = chrono::duration<double,milli>(t2_o - t1_o).count();
    cout << "the time consuming of optimized method is: " << o_time_duration_ms << " ms" << endl;

    cout << "-----------------------------" << endl;

// END METRIC ------------------------------------------------------

    return 0;
}

void getInput(int& L1, int& W1, int& L2, int& W2, bool& err){
    cout << "The function support matrix product of 2 matrix, Please ensure your input is valid" << endl;

    cout << "Please input the length of the first matrix" << endl;
    cin >> L1;
    if(cin.fail()) {
        cout << "Invalid input: please input an integer" << endl;
        err = true;
        return;
    }
    if(L1 <= 0){
        cout << "Invalid input: the input integer must be positive" << endl;
        err = true;
        return;
    }

    cout << "Please input the width of the first matrix" << endl;
    cin >> W1;
    if(cin.fail()) {
        cout << "Invalid input: please input an integer" << endl;
        err = true;
        return;
    }
    if(W1 <= 0){
        cout << "Invalid input: the input integer must be positive" << endl;
        err = true;
        return;
    }

    cout << "Please input the length of the second matrix" << endl;
    cin >> L2;
    if(cin.fail()) {
        cout << "Invalid input: please input an integer" << endl;
        err = true;
        return;
    }
    if(L2 <= 0){
        cout << "Invalid input: the input integer must be positive" << endl;
        err = true;
        return;
    }

    cout << "Please input the width of the second matrix" << endl;
    cin >> W2;
    if(cin.fail()) {
        cout << "Invalid input: please input an integer" << endl;
        err = true;
        return;
    }
    if(W2 <= 0){
        cout << "Invalid input: the input integer must be positive" << endl;
        err = true;
        return;
    }

    if(W1 != L2){
        cout << "Invalid input: the width of matrix 1 is not equal to height of matrix 2" << endl;
        err = true;
        return;
    }

    err = false;
}

