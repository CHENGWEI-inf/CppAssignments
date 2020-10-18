#include "InputClassifier.h"
#include "calculator.h"
#include "SequenceChecker.h"
#include <iostream>
#include <sstream>

using namespace std;

void InputClassifier::classifyOperand(string input) {
    string this_part;
    bool isFloat = false;
    for(int i = 0; i < input.length(); i++){
//        for(string s : operands)
//            cout << s << " ";
//        cout << endl;

        char cur_char = input[i];
   //     cout << cur_char << endl;
        //function
        if(cur_char == 's'){
            if(!this_part.empty())
                throw "InputValueException";
            if(i+5 < input.length() && input.substr(i,5) == "sqrt("){
                string param;
                bool is_uncertain_case = false;
                for(int j = i+5; j < input.length(); j++){
                    if(input[j] <= '9' && input[j] >= '0')
                        param += input[j];
                    else if(input[j] == '.' || input[j] == '-')
                        param += input[j];
                    else if(input[j] == ')') {
                        i = j;
                        break;
                    }
                    else if(j == i+5 && ((input[j] >= 'A' && input[j] <= 'Z') || (input[j] >= 'a' && input[j] <= 'z'))){
                        if(input[j+1] != ')') {
                            throw "InputFormatException";
                        }
                        string certain_value(1,input[j]);
                        certain_value = lookUpUncertain(certain_value);
                        if(certain_value.empty())
                            throw "EmptyAssignmentException";
                        this_part = calculate_sqrt(certain_value,div_precision);
                        isFloat = true;
                        is_uncertain_case = true;
                        i = j+1;
                        break;
                    }
                    else{
                        throw "InputFormatException";
                    }
                }
                if(!is_uncertain_case) {
                    this_part = calculate_sqrt(param, div_precision);
                    isFloat = true;// default float
                }
            }
            else{
                throw "InputFormatException";
            }

            if(i + 1 == input.length()){
                addOperand(this_part,operand_type[1]);
            }
            continue;
        }

        if(cur_char == ' ')
            continue;
        //number
        else if(cur_char - '0' >= 0 && cur_char - '0' < 10){
            this_part.push_back(cur_char);
            if(i + 1 == input.length()){
                if(isFloat)
                    addOperand(this_part,operand_type[1]);
                else
                    addOperand(this_part,operand_type[0]);
            }
            continue;
        }
        //considering float
        else if(cur_char == '.'){
            if(isFloat){
                throw "InputValueException";
            }
            isFloat = true;
            this_part.push_back(cur_char);
        }
        //considering uncertain
        else if(cur_char - 'a' <= 26 && cur_char - 'a' >= 0){
            if(!this_part.empty())
                throw "InputValueException";  //Not supporting "-x" as a negative number
            string str_cur_char(1,cur_char);
            operands.emplace_back(str_cur_char);
            operand_classes.emplace_back(operand_type[8]); // UNCERTAIN NUMBER (X)

        }
        else if(cur_char - 'A' <= 26 && cur_char - 'A' >= 0){
            if(!this_part.empty())
                throw "InputValueException";
            string str_cur_char(1,cur_char);
            operands.emplace_back(str_cur_char);
            operand_classes.emplace_back(operand_type[8]); // UNCERTAIN NUMBER (X)
        }
        // other operands
        else if(cur_char == '+' || cur_char == '-' || cur_char == '*' || cur_char == '/'
            || cur_char == '(' || cur_char == ')'){

            //notice if a " + - * / " has anything except number in front, the input is invalid
            //update: maybe has uncertain number in front
            if(this_part.empty() && (operands.empty() ||
                    operand_classes[operand_classes.size()-1] != operand_type[8])){
                if(cur_char == '+' || cur_char == '*' || cur_char == '/'){
                    if(operands[operands.size()-1] != ")")
                        throw "InputFormatException";
                }
                else if(cur_char == '-'){
                    this_part.push_back('-');
                    continue;
                }
            }
            if(this_part == "-")
                throw "InputFormatException";


            if(!this_part.empty()) {
                operands.push_back(this_part);
                if (isFloat)
                    operand_classes.emplace_back(operand_type[1]); // "FLOAT" TODO: maybe better implement by enum
                else
                    operand_classes.emplace_back(operand_type[0]);// "INTEGER"
                this_part = "";
                isFloat = false;
            }

            string str_cur_char(1,cur_char);
            operands.emplace_back(str_cur_char); //
            switch (cur_char) {
                case '+':
                    operand_classes.emplace_back(operand_type[2]); // "ADD"
                    break;
                case '-':
                    operand_classes.emplace_back(operand_type[3]); //"SUBTRACT"
                    break;
                case '*':
                    operand_classes.emplace_back(operand_type[4]); //"MULTIPLY"
                    break;
                case '/':
                    operand_classes.emplace_back(operand_type[5]); //"DIVIDE"
                    break;
                case '(':
                case ')':
                    operand_classes.emplace_back(operand_type[6]); //"BRACKET"
                    break;
                default:
                    break;
            }
        }
        else{
            throw "InputValueException";
        }

    }
}

void InputClassifier::buildUncertainMap(const string& input){
    bool isUnc = true;
    string unc;
    string num;
    for(int i = 0; i < input.length(); i++) {
        char c = input[i];
        //cout << i << endl;
        if(c == ' '){
            continue;
        }

        if(c == 'p'){
            if(input.substr(i,9) == "precision"){
                string pre;
                for(int j = i+9; j < input.length(); j++){
                    if(input[j] >= '0' && input[j] <= '9')
                        pre += input[j];
                }
                stringstream stream;
                stream << pre;
                int pre_int;
                stream >> pre_int;
                stream.clear();
                div_precision = pre_int;
                return;
            }
        }

        if(isUnc){
            if(c == '=')
                isUnc = false;
            else if(c- 'A' > 26 && c - 'A' < 0 &&  c- 'a' > 26 && c - 'a' < 0)
                throw "InputUnknownSymbolException";
            else{
                string u(1, c);
                unc = u;
            }
        } else{
            num.push_back(c);
        }
    }

    if(unc.empty())
        throw "InputUnknownSymbolException";

    for(int i = 0; i < num.length(); i++){
        if((num[i] > '9' || num[i] < '0' ) && num[i] != '.'){
            InputClassifier tmpIC;
            tmpIC.classifyOperand(num);
            tmpIC.setUncertainNumberMap(this->getUncertainNumberMap());
        //    cout << num << endl;
            if (SequenceChecker::balancedBracketCheck(tmpIC)) {
                vector<string> suffix = SequenceChecker::toSuffix(tmpIC);
                //cout << suffix[0] << endl;
                string res = SequenceChecker::sequenceCalculate(suffix,tmpIC.getDivPrecision());
                num = res;
            }
            else{
                throw "InputFormatException";
            }
        }
    }
    uncertain_number_map[unc] = num;
   // cout << uncertain_number_map["A"] << endl;
    //TODO: support multiple char to be one symbol, notice differ from function
}

bool InputClassifier::isAssignmentStat(const string& input){
    for(char i : input) {
        if (i == '=')
            return true;
    }
    return false;
}

string InputClassifier::lookUpUncertain(const string &key) {
//    cout << uncertain_number_map["A"] << endl;
    return uncertain_number_map[key];
}

void InputClassifier::addOperand(string op, string type) {
    operands.push_back(op);
    operand_classes.push_back(type);
}

vector<string> &InputClassifier::getOperands() {
    return operands;
}

vector<string> &InputClassifier::getOperandClasses() {
    return operand_classes;
}

int InputClassifier::getDivPrecision() const {
    return div_precision;
}

void InputClassifier::setDivPrecision(int divPrecision) {
    div_precision = divPrecision;
}

const unordered_map<string, string> &InputClassifier::getUncertainNumberMap() const {
    return uncertain_number_map;
}

void InputClassifier::setUncertainNumberMap(const unordered_map<string, string> &uncertainNumberMap) {
    uncertain_number_map = uncertainNumberMap;
}

InputClassifier::InputClassifier() = default;


