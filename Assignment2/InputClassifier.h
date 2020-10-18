#ifndef INPUTCLASSIFIER_H
#define INPUTCLASSIFIER_H
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
#include "calculator.h"
using namespace std;

class InputClassifier {
    private:
        //TODO arrange this length
        string operand_type[10] = {"INTEGER", "FLOAT", "ADD", "SUBTRACT", "MULTIPLY",
                                  "DIVIDE", "BRACKET", "FUNCTION", "UNCERTAIN", "ASSIGNMENT"};
        vector<string> operands;
        vector<string> operand_classes;
        unordered_map<string, string> uncertain_number_map;
        int div_precision = 2;

    public:
        InputClassifier();
        vector<string> &getOperands();
        vector<string> &getOperandClasses();
        int getDivPrecision() const;
        void setDivPrecision(int divPrecision);
        const unordered_map<string, string> &getUncertainNumberMap() const;
        void setUncertainNumberMap(const unordered_map<string, string> &uncertainNumberMap);
        void addOperand(string op, string type);
        void classifyOperand(string input);
        static bool isAssignmentStat(const string& input);
        void buildUncertainMap(const string& input);
        string lookUpUncertain(const string& key);
};


#endif //INPUTCLASSIFIER_H
