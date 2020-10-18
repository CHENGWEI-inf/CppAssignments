#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "..\head\InputReader.h"

void InputReader::read_vector_from_cmd(int vector_order) {
    string order;
    static float *v;

    if(vector_order == 1) {
        order = "first";
        v = v1;
    }
    else if(vector_order == 2) {
        order = "second";
        v = v2;
    }
    else {
        cerr << "the vector_order should be 1 or 2" << endl;
        throw "RuntimeError";
    }

    cout << "please input your " << order << " vector of float:" << endl;
    for(int i = 0; i < size_v; i++){
        float tmp;
        cin >> tmp;
        *v = tmp;
        v++;
    }
}

void InputReader::read_cmd() {
    read_vector_from_cmd(1);
    read_vector_from_cmd(2);
}

void InputReader::read_file() {
    string file_name_v1 = "files/v1.dat";
    string file_name_v2 = "files/v2.dat";

    ifstream in_v1(file_name_v1,ios::binary);
    float * tmp = v1;
    long long cnt = size_v;
    if(in_v1.is_open()){
        while (in_v1.peek() != EOF && cnt > 0){
            in_v1.read((char*)tmp,sizeof(*tmp));
//            cout << tmp - v1 << " : " << *tmp << endl;
            if(*(tmp) < 0 || *(tmp) > 1000000)
                cout << *(tmp)<< endl;
            tmp++;
            cnt--;

            if((size_v - cnt) % 1000000 == 0){
                cout <<"reading: " <<  (size_v - cnt) / 1000000 << " 000 000 data in"<< endl;
            }
        }
        in_v1.close();
    }
    else{
        throw "FileNotFoundException";
    }

    ifstream in_v2(file_name_v2,ios::binary);
    tmp = v2;
    cnt = size_v;
    if(in_v2.is_open()){
        while (in_v2.peek() != EOF && cnt > 0){
            in_v2.read((char*)tmp,sizeof(*tmp));
         //   cout << *tmp << endl;
            tmp++;
            cnt--;

            if((size_v - cnt) % 1000000 == 0){
                cout <<"reading: " <<  200 + (size_v - cnt) / 1000000 << " 000 000 data in"<< endl;
            }
        }
        in_v2.close();
    }
    else{
        throw "FileNotFoundException";
    }
}


InputReader::InputReader() {
    string input;
    cout <<  "please input your size of both vector:" << endl;
    cin >> input;
    stringstream ss(input);
    for(char c : input){
        if(c - '0' < 0 || c - '0' > 9)
            throw "InvalidInput: the input size should be Integer";
    }
    ss >> size_v;

    try {
        v1 = new float[size_v];
        v2 = new float[size_v];
        if(v1 == nullptr || v2 == nullptr)
            throw "Memory Alloc Failure";
    } catch (const bad_alloc& e) {
        throw "Memory Alloc Failure";
    }


//    cout << v1 << " " << v2 << endl;
   // cout << _msize(v1) << endl;
}

long long InputReader::getSizeV() const {
    return size_v;
}

float *InputReader::getV1() const {
    return v1;
}

float *InputReader::getV2() const {
    return v2;
}

