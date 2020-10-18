#ifndef INPUTREADER_H
#define INPUTREADER_H

#include <vector>

using namespace std;

class InputReader{

private:
    long long size_v;
    float* v1;
    float* v2;
public:
    void read_vector_from_cmd(int vector_order);
    void read_cmd();
    void read_file();
    InputReader();
    long long getSizeV() const;
    float *getV1() const;
    float *getV2() const;
};



#endif //INPUTREADER_H
