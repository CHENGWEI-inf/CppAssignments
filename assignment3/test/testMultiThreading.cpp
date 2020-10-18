#include <iostream>
#include <windows.h>
#include <thread>
using namespace std;

int dotProduct(int* a, int* b, int size){
    int* ptr1 = a;
    int* ptr2 = b;
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum += *ptr1 * *ptr2;
        ptr1++;
        ptr2++;
    }
    return sum;
}

void threadDotProduct(int* a, int* b, int size, int &ans){
    ans = dotProduct(a,b,size);
//    cout << ans <<  endl;
}

int sepDotP(int* a, int* b, int size){

    int group_num = 8;

    int ans1 = 0;
    thread t1 = thread(
        threadDotProduct,a + 0 * size/group_num, b + 0 * size/group_num, size/group_num, ref(ans1)
    );
    int ans2 = 0;
    thread t2 = thread(
            threadDotProduct,a + 1 * size/group_num, b + 1 * size/group_num, size/group_num, ref(ans2)
    );
    int ans3 = 0;
    thread t3 = thread(
            threadDotProduct,a + 2 * size/group_num, b + 2 * size/group_num, size/group_num, ref(ans3)
    );
    int ans4 = 0;
    thread t4 = thread(
            threadDotProduct,a + 3 * size/group_num, b + 3 * size/group_num, size/group_num, ref(ans4)
    );
    int ans5 = 0;
    thread t5 = thread(
            threadDotProduct,a + 4 * size/group_num, b + 4 * size/group_num, size/group_num, ref(ans5)
    );
    int ans6 = 0;
    thread t6 = thread(
            threadDotProduct,a + 5 * size/group_num, b + 5 * size/group_num, size/group_num, ref(ans6)
    );
    int ans7 = 0;
    thread t7 = thread(
            threadDotProduct,a + 6 * size/group_num, b + 6 * size/group_num, size/group_num, ref(ans7)
    );
    int ans8 = 0;
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

    return ans1 + ans2 + ans3 + ans4 + ans5 + ans6 + ans7 + ans8;
}


int main()
{

    int a[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int b[16] = {16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    int res = sepDotP(a,b,16);
    cout << res << endl;
    res = dotProduct(a,b,16);
    cout << res << endl;

//    HANDLE hThread = CreateThread(NULL, 0, Fun, NULL, 0, NULL);
//    hMutex = CreateMutex(NULL, FALSE,"cs");
//    CloseHandle(hThread);
//    for (int i = 0; i < 10; i++) {
//        WaitForSingleObject(hMutex,INFINITE);
//        cout << "Main Thread Display!" << endl;
//        Sleep(100);
//        //释放互斥量锁
//        ReleaseMutex(hMutex);
//    }
    return 0;
}