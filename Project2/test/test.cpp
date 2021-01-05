#include "test.h"
using namespace std;

void print_matrix(float ** matrix, int size){
    cout << endl;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}