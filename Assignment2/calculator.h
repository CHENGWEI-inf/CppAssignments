#ifndef ASSIGNMENT2_CALCULATOR_H
#define ASSIGNMENT2_CALCULATOR_H

#include<string>
#include<vector>
#include<sstream>

using namespace std;
vector<string> separateIntegerDecimal(const string& operand);
string add(string opA, string opB);
string sub(string opA, string opB);
string mul(string opA, string opB);
string div(string opA, string opB, int precision);
string calculate_sqrt(string op, int precision);
int is_larger_integer(string num_a, string num_b);

#endif //ASSIGNMENT2_CALCULATOR_H
