#include <iostream>
#include "InputClassifier.h"
#include "SequenceChecker.h"
#include "calculator.h"
#include "runner.h"
using namespace std;

int main() {
    run();
    return 0;
}

//        InputClassifier uniqueIC;
//        uniqueIC.buildUncertainMap("A = 4");
////        uniqueIC.buildUncertainMap("A = 3");
////        uniqueIC.buildUncertainMap("C = (A+B)/4");
////        string stat = "sqrt(C)";
//        string stat = "A";
////        uniqueIC.classifyOperand(stat);
//        check_one_stat(stat,uniqueIC);
//        cout << uniqueIC.lookUpUncertain("A") << endl;