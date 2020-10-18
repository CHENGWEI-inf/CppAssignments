#include "calculator.h"
#include <iostream>
using namespace std;

vector<string> separateIntegerDecimal(const string& operand){
    string op_integer, op_decimal;
    bool is_decimal = false;
    for(char c : operand){
        if(c == '.'){
            is_decimal = true;
            continue;
        }

        if(!is_decimal)
            op_integer.push_back(c);
        else
            op_decimal.push_back(c);
    }

    if(op_decimal.empty())
        op_decimal = "0";

    vector<string> rtn;
    rtn.push_back(op_integer);
    rtn.push_back(op_decimal);
    return rtn;
}

//this add and sub (maybe mul and div) only support positive numbers, we should preprocess to ensure the input
string add(string opA, string opB){
    string opA_integer, opA_decimal, opB_integer, opB_decimal;
    vector<string> resA = separateIntegerDecimal(opA);
    vector<string> resB = separateIntegerDecimal(opB);
    opA_integer = resA[0];
    opA_decimal = resA[1];
    opB_integer = resB[0];
    opB_decimal = resB[1];

    int diff = opA_decimal.length() - opB_decimal.length();
    if(diff > 0){
        string zeros(diff,'0');
        opB_decimal = opB_decimal + zeros;
    }
    else if(diff < 0){
        string zeros(-diff,'0');
        opA_decimal = opA_decimal + zeros;
    }

    string ans;
    int carry = 0;
    int running_sum = 0;
    for(int i = opA_decimal.length() - 1; i >= 0; i--){
        int running_A = opA_decimal[i] - '0';
        int running_B = opB_decimal[i] - '0';
        running_sum = running_A + running_B + carry;
        if(running_sum > 9){
            carry = 1;
            ans = to_string(running_sum-10) + ans;
        } else{
            carry = 0;
            ans = to_string(running_sum) + ans;
        }
    }

    ans = "." + ans;

    diff = opA_integer.length() - opB_integer.length();
    if(diff > 0){
        string zeros(diff,'0');
        opB_integer = zeros + opB_integer;
    }
    else if(diff < 0){
        string zeros(-diff,'0');
        opA_integer = zeros + opA_integer;
    }
    //carry = carry from decimal
    for(int i = opA_integer.length() - 1; i >= 0; i--){
        int running_A = opA_integer[i] - '0';
        int running_B = opB_integer[i] - '0';
        int running_sum = running_A + running_B + carry;
        if(running_sum > 9){
            carry = 1;
            ans = to_string(running_sum-10) + ans;
        } else{
            carry = 0;
            ans = to_string(running_sum) + ans;
        }
    }

    if(carry == 1)
        ans = "1" + ans;

    if(ans[0] == '.')
        ans = "0" + ans;

    return ans;
}

string sub(string opA, string opB){
    string opA_integer, opA_decimal, opB_integer, opB_decimal;
    vector<string> resA = separateIntegerDecimal(opA);
    vector<string> resB = separateIntegerDecimal(opB);
    opA_integer = resA[0];
    opA_decimal = resA[1];
    opB_integer = resB[0];
    opB_decimal = resB[1];

    int diff = opA_decimal.length() - opB_decimal.length();
    if(diff > 0){
        string zeros(diff,'0');
        opB_decimal = opB_decimal + zeros;
    }
    else if(diff < 0){
        string zeros(-diff,'0');
        opA_decimal = opA_decimal + zeros;
    }

    bool positive = (is_larger_integer(opA_integer,opB_integer) > 0) ||
                    (is_larger_integer(opA_integer,opB_integer) == 0 && is_larger_integer(opA_decimal,opB_decimal) > 0);
    if(!positive){
        string tmp_integer = opA_integer;
        opA_integer = opB_integer;
        opB_integer = tmp_integer;
        string tmp_decimal = opA_decimal;
        opA_decimal = opB_decimal;
        opB_decimal = tmp_decimal;
    }


    string ans;
    int running_sum = 0;
    int carry = 0;
    for(int i = opA_decimal.length() - 1; i >= 0; i--){
        int running_A = opA_decimal[i] - '0';
        int running_B = opB_decimal[i] - '0';
        running_sum = running_A - running_B + carry;
        if(running_sum < 0){
            carry = -1;
            ans = to_string(running_sum+10) + ans;
        } else{
            carry = 0;
            ans = to_string(running_sum) + ans;
        }
    }
    //cout << ans <<endl;

    if(ans == "0")
        ans = "";
    else
        ans = "." + ans;

    diff = opA_integer.length() - opB_integer.length();
    if(diff > 0){
        string zeros(diff,'0');
        opB_integer = zeros + opB_integer;
    }
    else if(diff < 0){
        string zeros(-diff,'0');
        opA_integer = zeros + opA_integer;
    }
    //carry = carry from decimal
    for(int i = opA_integer.length() - 1; i >= 0; i--){
        int running_A = opA_integer[i] - '0';
        int running_B = opB_integer[i] - '0';
        int running_sum = running_A - running_B + carry;
        if(running_sum < 0){
            carry = -1;
            ans = to_string(running_sum+10) + ans;
        } else{
            carry = 0;
            ans = to_string(running_sum) + ans;
        }
    }


    while(ans[0] == '0'){
        ans.erase(0,1);
        if(ans.length() == 0){
            ans = "0";
            break;
        }
        if(ans[0] == '.'){
            ans = "0" + ans;
            break;
        }
    }

    //remove tail zeros
    bool is_float = false;
    for(char c : ans){
        if(c == '.'){
            is_float = true;
            break;
        }
    }
    if(is_float){
        while(ans[ans.length()-1] == '0'){
            ans.erase(ans.length()-1,1);
        }
        if(ans[ans.length()-1] == '.'){
            ans.erase(ans.length()-1,1);
        }
    }

    if(!positive && ans != "0")
        ans = "-" + ans;
    else if(!positive && ans == "")
        ans = "0";

    return ans;
}

string mul(string opA, string opB){
    if(opA == "0" || opB == "0")
        return "0";

    bool isNegative = opA[0] == '-' ^ opB[0] == '-';
    string strA = opA;
    string strB = opB;
    if(opA[0] == '-')
        strA = strA.erase(0,1);
    if(opB[0] == '-')
        strB = strB.erase(0,1);

    //check float;
    int f_num_a = 0;
    int f_num_b = 0;
    for(char c : strA){
        if(f_num_a > 0 || c == '.')
            f_num_a++;
    }
    for(char c : strB){
        if(f_num_b > 0 || c == '.')
            f_num_b++;
    }
    if(f_num_a > 1){
        f_num_a --;
        strA.erase(strA.length() - f_num_a - 1, 1);
    }
    if(f_num_b > 1){
        f_num_b --;
        strB.erase(strB.length() - f_num_b - 1, 1);
    }

    int aLen = strA.length();
    int bLen = strB.length();
    vector<int> res(aLen + bLen,0);
    for(int i = 0; i < aLen; i++){
        for(int j = 0; j < bLen; j++){
            // combine 2. 3.
            int tmpA = strA[aLen - i - 1] - '0';
            int tmpB = strB[bLen - j - 1] - '0';
            res[i + j] += tmpA * tmpB;
        }
    }

    for(int i = 1; i < res.size(); i++){
        if(res[i-1] > 9){
            res[i] += res[i-1] / 10;
            res[i-1] %= 10;
        }
    }

    string ans;
    bool firstNonZero = false;
    for(int i = res.size()-1; i >= 0; i--){
        if(!firstNonZero){
            if(res[i] == 0)
                continue;
            else
                firstNonZero = true;
        }
        ans += std::to_string(res[i]);
    }

    int f_num = f_num_a + f_num_b;
    if(f_num > 1){
        ans = ans.substr(0,ans.length() - f_num) + "." + ans.substr(ans.length() - f_num, f_num);
    }

    if(isNegative){
        ans = '-' + ans;
    }

    return ans;
}

string div(string opA, string opB, int precision) {
    if (opB == "0")
        throw "DivideZeroException";

    //the first step is to align them in to integers
    //update: to check if they are already integers
    int a_decimal_cnt = -1, b_decimal_cnt = -1;
    for (char c : opA) {
        if(a_decimal_cnt >= 0)
            a_decimal_cnt++;
        if (c == '.')
            a_decimal_cnt = 0;
    }
    for (char c : opB) {
        if(b_decimal_cnt >= 0)
            b_decimal_cnt++;
        if (c == '.')
            b_decimal_cnt = 0;
    }
    if(a_decimal_cnt == -1) a_decimal_cnt = 0;
    else opA.erase(opA.length()-a_decimal_cnt-1,1);
    if(b_decimal_cnt == -1) b_decimal_cnt = 0;
    else opB.erase(opB.length()-b_decimal_cnt-1,1);
    if(a_decimal_cnt > b_decimal_cnt){
        string zeros_b(a_decimal_cnt-b_decimal_cnt,'0');
        opB += zeros_b;
    }
    else if(a_decimal_cnt < b_decimal_cnt){
        string zeros_a(b_decimal_cnt-a_decimal_cnt,'0');
        opA += zeros_a;
    }
    // cout << opA << " " << opB << endl;
    while(opA[opA.length()-1] == opB[opB.length() - 1] && opA[opA.length()-1] == '0'){
        opA.erase(opA.length()-1,1);
        opB.erase(opB.length()-1,1);
    }
    while(opA[0] == '0')
        opA.erase(0,1);
    while(opB[0] == '0')
        opB.erase(0,1);
    // cout << opA << " " << opB << endl;

    //the second step is to fix precision.
    string zeros(precision,'0');
    if(opA.length() + precision < opB.length()){
        if(precision > 0)
            return "0." + zeros;
        else
            return "0";
    }
    opA += zeros;

    // cout << opA << " " << opB << endl;
    //division by circular minus
    string quotient, reminder;
    int diff_in_bit = opA.length() - opB.length();
    string zeros_sup(diff_in_bit,'0');
    opB += zeros_sup;
    for(int j = diff_in_bit; j >= 0; j--){
        //      cout << quotient << " " << opA << " " << opB << endl;
        int cnt = 0;
        while(is_larger_integer(opA,opB) >= 0){
            opA = sub(opA,opB);
//            cout << opA << " " << opB << " " << is_larger_integer(opA,opB) << " ";
            cnt++;
        }
        if(cnt > 0)
            quotient += to_string(cnt);
        else if(cnt == 0 && !quotient.empty())
            quotient += "0";

        opB.erase(opB.length()-1,1);
    }
    if(precision > 0){
        quotient = quotient.substr(0,quotient.length() - precision)
                   + "." + quotient.substr(quotient.length() - precision, precision);
    }
    if(quotient[0] == '.')
        quotient = "0" + quotient;

    return quotient;
}

string calculate_sqrt(string op, int precision){
    if(op[0] == '-')
        throw "NegativeSquareRootException";
    //Non sense to implement sqrt, takes too long
    istringstream ss(op);
    bool is_float = false;
    for(char c : op){
        if(c == '.') {
            is_float = true;
            break;
        }
    }

    string res;
    if(is_float){
        double num;
        ss >> num;
        res = to_string(sqrt(num));
    }
    else{
        int num;
        ss >> num;
        res = to_string(sqrt(num));
    }

    bool is_decimal = false;
    for(int i = 0; i < res.length();i++ ){
        if(res[i] == '.'){
            is_decimal = true;
            continue;
        }
        if(is_decimal && precision > 0){
            precision--;
            if(i == res.length() - 1){
                string zeros(precision,'0');
                res += zeros;
                break;
            }
        }
        else if(is_decimal && precision == 0){
            res.erase(i,res.length() - i);
            break;
        }
    }

    if(!is_decimal){
        string zeros(precision,'0');
        res += ".";
        res += zeros;
        return res;
    }
    else{
        return res;
    }

}

int is_larger_integer(string num_a, string num_b){
    if(num_a[0] == '-' && num_b[0] == '-'){
        num_a.erase(0,1);
        num_b.erase(0,1);
        return -is_larger_integer(num_a,num_b);
    }
    else if(num_a[0] == '-' && num_b[0] != '-'){
        return -1;
    }
    else if(num_a[0] != '-' && num_b[0] == '-'){
        return 1;
    }

    if(num_a.length() > num_b.length())
        return 1;
    else if(num_a.length() < num_b.length())
        return -1;
    else{
        for(int i = 0; i < num_a.length(); i++){
            if(num_a[i] - num_b[i] > 0)
                return 1;
            else if(num_a[i] - num_b[i] == 0)
                continue;
            else
                return -1;
        }
        return 0;
    }
}


