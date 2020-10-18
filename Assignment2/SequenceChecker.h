#ifndef SEQUENCECHECKER_H
#define SEQUENCECHECKER_H
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include "InputClassifier.h"
#include "calculator.h"
using namespace std;

class SequenceChecker {
private:
    stack<string> cal_stack;
public:
    static vector<string> toSuffix(InputClassifier uniqueIC);
    static bool higherPriority(string &cur_op, string &compared_op);
    static bool balancedBracketCheck(InputClassifier uniqueIC);

    static string sequenceCalculate(vector<string> suffix, int div_precision);
};


#endif //SEQUENCECHECKER_H
