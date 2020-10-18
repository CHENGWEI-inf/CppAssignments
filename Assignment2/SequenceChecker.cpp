#include "SequenceChecker.h"
#include "InputClassifier.h"
#include "calculator.h"
using namespace std;

vector<string> SequenceChecker::toSuffix(InputClassifier uniqueIC) {
    stack<string> operator_stack;
    vector<string> suffix_formula;

    vector<string> standard_form = uniqueIC.getOperands();
    vector<string> classifier = uniqueIC.getOperandClasses();

    for(int i = 0; i < standard_form.size(); i++){
       // cout << classifier[i] << " " << standard_form[i] << endl;
        if(classifier[i] == "INTEGER" || classifier[i] == "FLOAT"){
           suffix_formula.push_back(standard_form[i]);
        }
        else if(classifier[i] == "UNCERTAIN"){
            string certain_value = uniqueIC.lookUpUncertain(standard_form[i]);
          //  cout << standard_form[i] << endl;
            if(certain_value.empty())
                throw "EmptyAssignmentException";
            suffix_formula.push_back(certain_value);
        }
        else if(classifier[i] == "ADD" || classifier[i] == "SUBTRACT" || classifier[i] == "MULTIPLY" || classifier[i] == "DIVIDE"){
            while (true){
                if(operator_stack.empty() || operator_stack.top() == "("){
                    operator_stack.push(standard_form[i]);
                    break;
                }
                else if(higherPriority(standard_form[i],operator_stack.top())){
                    operator_stack.push(standard_form[i]);
                    break;
                }
                else if(!higherPriority(standard_form[i],operator_stack.top())){
                    suffix_formula.push_back(operator_stack.top());
                    operator_stack.pop();
                }
            }
        }else if(classifier[i] == "BRACKET"){
            if(standard_form[i] == "(")
                operator_stack.push(standard_form[i]);
            else{
                while (operator_stack.top() != "("){
                    suffix_formula.push_back(operator_stack.top());
                    operator_stack.pop();
                }
                operator_stack.pop();
            }
        }
        else if(classifier[i] == "FUNCTION"){
            //TODO implement function
        }
    }

    while (!operator_stack.empty()){
        suffix_formula.push_back(operator_stack.top());
        operator_stack.pop();
    }

    return suffix_formula;
}

bool SequenceChecker::higherPriority(string &cur_op, string &compared_op) {
    if(cur_op == "+" || cur_op == "-")
        return false;
    if(compared_op == "*" || compared_op == "/")
        return false;
    return true;
}

bool SequenceChecker::balancedBracketCheck(InputClassifier uniqueIC) {
    int cnt = 0;
    for(int i = 0; i < uniqueIC.getOperandClasses().size(); i++){
        if(uniqueIC.getOperandClasses()[i] == "BRACKET"){
            if(uniqueIC.getOperands()[i] == "(")
                cnt++;
            else
                cnt--;
        }
    }
    return cnt == 0;
}

string SequenceChecker::sequenceCalculate(vector<string> suffix, int div_precision){
    stack<string> operand_stack;
    for(const auto& tmp : suffix){
        if(tmp == "+" || tmp == "-" || tmp == "*" || tmp == "/"){
            if(operand_stack.size() < 2)
                throw "InvalidInputSequence";

            string o2 = operand_stack.top();
            operand_stack.pop();
            string o1 = operand_stack.top();
            operand_stack.pop();
           // cout << o1 << " " << tmp << " " << o2 << endl;

            if(tmp == "+"){
                if(o1[0] == '-' && o2[0] == '-'){
                    o1.erase(0,1);
                    o2.erase(0,1);
                    string res = "-";
                    res += add(o1,o2);
                    operand_stack.push(res);
                }
                else if(o1[0] == '-'){
                    o1.erase(0,1);
                    string res = sub(o2,o1);
                    operand_stack.push(res);
                }
                else if(o2[0] == '-'){
                    o2.erase(0,1);
                    string res = sub(o1,o2);
                    operand_stack.push(res);
                  //  cout << operand_stack.top() << endl;
                }
                else{
                    string res = add(o1,o2);
                    operand_stack.push(res);
                }
            }
            else if(tmp == "-"){
                if(o1[0] == '-' && o2[0] == '-'){
                    o1.erase(0,1);
                    o2.erase(0,1);
                    string res = sub(o2,o1);
                    operand_stack.push(res);
                }
                else if(o1[0] == '-'){
                    o1.erase(0,1);
                    string res = "-";
                    res += add(o1,o2);
                    operand_stack.push(res);
                }
                else if(o2[0] == '-'){
                    o2.erase(0,1);
                    string res = add(o1,o2);
                    operand_stack.push(res);
                }
                else{
                    string res = sub(o1,o2);
                    operand_stack.push(res);
                }
            }
            else if(tmp == "*"){
                string res = mul(o1,o2);
                operand_stack.push(res);
            }
            else if(tmp == "/"){
//                cout << o1 << " " << o2 << endl;
                if(o1[0] == '-' && o2[0] == '-'){
                    o1.erase(0,1);
                    o2.erase(0,1);
                    string res = div(o2,o1,div_precision);
                    operand_stack.push(res);
                }
                else if(o1[0] == '-'){
                    o1.erase(0,1);
                    string res = "-";
                    res += div(o1,o2,div_precision);
                    operand_stack.push(res);
                }
                else if(o2[0] == '-'){
                    o2.erase(0,1);
                    string res = "-";
                    res += div(o1,o2,div_precision);
                    operand_stack.push(res);
                }
                else{
                    string res = div(o1,o2,div_precision);
                    operand_stack.push(res);
                }
            }
        }
        else{
            operand_stack.push(tmp);
        }
    }

    return operand_stack.top();
}