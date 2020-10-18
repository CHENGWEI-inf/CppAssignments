#include "..\head\concurrentDotProduct.h"
#include<thread>
#include<iostream>
using namespace std;

float dotProduct_concurrent(float *v1, float *v2, long long int size) {
    //Noticed that there are 8 threads on my CPU, the program can be divided into 8 threads concurrently running
    float ans;
    ans = sepDotP(v1,v2,size);
    return ans;
}

double threadDotProduct(float* a, float* b, long long size, double &ans){
    float* ptr1 = a;
    float* ptr2 = b;
    for(int i = 0; i < size; i++){
        ans += *ptr1 * *ptr2;
        ptr1++;
        ptr2++;
    }
    return (double)ans;
}

float sepDotP(float* a, float* b, long long size){

    int group_num = 8;
    double ans = 0;

    if(size % 8 != 0){
        double ans0 = 0;
        long long size_tmp = size;
        size = size - size%group_num;
        thread t0 = thread(
                threadDotProduct, a + size_tmp-(size_tmp%group_num), b + size_tmp-(size_tmp%group_num),
                size_tmp%group_num, ref(ans0)
                );
        ans += ans0;
        t0.join();
    }

    double ans1 = 0;
    thread t1 = thread(
            threadDotProduct,a + 0 * size/group_num, b + 0 * size/group_num, size/group_num, ref(ans1)
    );
    double ans2 = 0;
    thread t2 = thread(
            threadDotProduct,a + 1 * size/group_num, b + 1 * size/group_num, size/group_num, ref(ans2)
    );
    double ans3 = 0;
    thread t3 = thread(
            threadDotProduct,a + 2 * size/group_num, b + 2 * size/group_num, size/group_num, ref(ans3)
    );
    double ans4 = 0;
    thread t4 = thread(
            threadDotProduct,a + 3 * size/group_num, b + 3 * size/group_num, size/group_num, ref(ans4)
    );
    double ans5 = 0;
    thread t5 = thread(
            threadDotProduct,a + 4 * size/group_num, b + 4 * size/group_num, size/group_num, ref(ans5)
    );
    double ans6 = 0;
    thread t6 = thread(
            threadDotProduct,a + 5 * size/group_num, b + 5 * size/group_num, size/group_num, ref(ans6)
    );
    double ans7 = 0;
    thread t7 = thread(
            threadDotProduct,a + 6 * size/group_num, b + 6 * size/group_num, size/group_num, ref(ans7)
    );
    double ans8 = 0;
    thread t8 = thread(
            threadDotProduct,a + 7 * size/group_num, b + 7 * size/group_num, size/group_num, ref(ans8)
    );

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();

    ans += (ans1 + ans2 + ans3 + ans4 + ans5 + ans6 + ans7 + ans8);
    return (float)ans;
}