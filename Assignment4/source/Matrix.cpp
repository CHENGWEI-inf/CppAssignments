#include "../head/Matrix.h"
#include "../head/matrixAlgorithmsUtil.h"

Matrix::Matrix(int len, int wid) {
    // init matrix
    this->len = len;
    this->wid = wid;
    matrix = new float * [len];
    for(int i = 0; i < len; i++) {
        matrix[i] = new float[wid];
        for(int j = 0; j < wid; j++){
            matrix[i][j] = 0.0f;
        }
    }
}

Matrix::Matrix(int len, int wid, float **matrix) {
    this->len = len;
    this->wid = wid;
    this->matrix = matrix;
}

void Matrix::printMatrix(){
    for(int i = 0; i < len; i++){
        for (int j = 0; j < wid; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

float **Matrix::getMatrix() const {
    return matrix;
}

int Matrix::getLen() const {
    return len;
}

int Matrix::getWid() const {
    return wid;
}

Matrix Matrix::operator+(const Matrix &other) const {
    return add_matrix(this, other);
}

Matrix Matrix::operator-(const Matrix &other) const {
    return sub_matrix(this, other);
}

Matrix &Matrix::operator=(const Matrix &other) {
    if(&other == this)
        return *this;

    this->len = other.getLen();
    this->wid = other.getWid();
    this->matrix = other.getMatrix();

    return *this;
}

bool Matrix::operator==(const Matrix &other) const {
    if(this->len != other.getLen() || this->wid != other.getWid())
        return false;
    if(this->matrix == other.getMatrix())
        return true;

    for(int i = 0; i < this->len; i++){
        for(int j = 0; j < this->wid; j++){
            if(this->matrix[i][j] != other.getMatrix()[i][j])
                return false;
        }
    }
    return true;
}

Matrix Matrix::operator*(const Matrix &other) const {
    return multiply_matrix(this, other);
}

Matrix Matrix::operator*(const float &num) const {
    return num_mul_matrix(*this, num);
}

Matrix operator*(float num, const Matrix &other) {
    return num_mul_matrix(other, num);
}

void Matrix::setLen(int len) {
    Matrix::len = len;
}



ostream & operator<<(ostream & os, const Matrix & m){
    os << "len: " << m.getLen() << endl;
    os << "wid: " << m.getWid() << endl;

    for(int i = 0; i < m.getLen(); i++){
        for (int j = 0; j < m.getWid() ; j++){
            os << m.getMatrix()[i][j] << " ";
        }
        os << endl;
    }

    return os;
}


