#include <fstream>
#include <cstdlib>
#include <iostream>

using namespace std;

void gen_rand_and_write(string file_name, long long size){
    ofstream f_out(file_name, ios::binary);
    for(long long i = 0; i < size; i++){

        if(i % 1000000 == 0){
            cout << i / 1000000 + 1<< endl;
        }

        int rand_int = rand()%1000;
        float rand_float = rand() / float(RAND_MAX);

        if(rand_float == 0)
            rand_float = 0.1;

        float rand_num = rand_int / rand_float;

        if(rand_num > 100000)
            rand_num /= 100.0;

        f_out.write((char *)(&rand_num), sizeof(rand_num));
    }
   // f_out << 0;
    f_out.close();
}

int main(){
    string file_path = "files/";
    long long size = 300 * 1000 * 1000;
    //long long size = 3;
    string file_v1 = file_path + "v1" + ".dat";
    string file_v2 = file_path + "v2" + ".dat";
    gen_rand_and_write(file_v1,size);
    gen_rand_and_write(file_v2,size);


 // for test
//    ifstream in(file_v1, ios::binary);
//    for(int i = 0; i < 3; i++){
//        float f;
//        in.read((char*)(&f),sizeof(f));
//        cout << f << endl;
//    }

    return 0;
}