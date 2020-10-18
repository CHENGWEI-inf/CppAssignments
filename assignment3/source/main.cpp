#include <iostream>
#include <chrono>
#include "..\head\InputReader.h"
#include "..\head\plainDotProduct.h"
#include "..\head\concurrentDotProduct.h"
using namespace std;

int main() {
    try {
        InputReader reader = InputReader();

        auto t1_io = chrono::steady_clock::now();
        reader.read_file();
        float *v1 = reader.getV1();
        float *v2 = reader.getV2();
        long long size = reader.getSizeV();
        auto t2_io = chrono::steady_clock::now();
        double io_time_duration_ms = chrono::duration<double,micro>(t2_io - t1_io).count();
        cout << "the time consuming of I/O is: " << io_time_duration_ms << " ms" << endl;

        //test plain dot product time
        auto t1_p = chrono::steady_clock::now();
        cout << "the result of plain method is: " << dotProduct_plain(v1,v2,size) << endl;
        auto t2_p = chrono::steady_clock::now();
        double p_time_duration_ms = chrono::duration<double,micro>(t2_p - t1_p).count();
        cout << "the time consuming of plain method is: " << p_time_duration_ms << " ms" << endl;

        //test concurrent dot product time
        auto t1_c = chrono::steady_clock::now();
        cout << "the result of concurrent method is: " << dotProduct_concurrent(v1,v2,size) << endl;
        auto t2_c = chrono::steady_clock::now();
        double c_time_duration_ms = chrono::duration<double,micro>(t2_c - t1_c).count();
        c_time_duration_ms = c_time_duration_ms / 8; // 8 thread avg time
        cout << "the time consuming of concurrent method is: " << c_time_duration_ms << " ms" << endl;

        delete v1;
        delete v2;

    } catch (const char* msg){
        cerr << msg << endl;
    }
    return 0;
}
