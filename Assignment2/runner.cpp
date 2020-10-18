#include "runner.h"

void check_one_stat(string stat, InputClassifier& uniqueIC){
    if(uniqueIC.isAssignmentStat(stat)){
        uniqueIC.buildUncertainMap(stat);
        cout << "done" << endl;
    }
    else{
        uniqueIC.classifyOperand(stat);
        if (SequenceChecker::balancedBracketCheck(uniqueIC)) {
            vector<string> suffix = SequenceChecker::toSuffix(uniqueIC);
//            for(string s : suffix)
//                cout << s << " ";
//            cout << endl;
            string res = SequenceChecker::sequenceCalculate(suffix,uniqueIC.getDivPrecision());
            cout << stat << " = " << res << endl;
        }
    }
}

void reminder(){
    cout << "1.If you want to set precision of division and sqrt(), input 'precision = <int_precision_you_want>';" << endl;
    cout << "2.If you want to use sqrt(), input 'sqrt(<num_to_calculate>)';" << endl;
    cout << "3.To use unknown number calculation, you should assign them first(only one letter unknown number is supported): " << endl;
    cout << "\tfor example: A = <num_to_assign> \n\tor B = sqrt(A)\n\tor B = 36 * 5 + 4 / A" << endl;
    cout << "4.Arbitrary length and precision is supported!" << endl;
    cout << "5.exit by entering 'quit()' or 'exit()' " << endl;
    cout << endl;
}

void run(){
    reminder();
    InputClassifier uniqueIC;

    while(true){
        cout << "please enter a statement, for more information, enter 'help()' " << endl;
        char s[100];
        cin.getline(s,100);
        string stat(s);
        if(stat == "exit()" || stat == "quit()")
            break;
        else if(stat == "help()")
            reminder();
        else {
          //  cout << stat << endl;
            try {
                check_one_stat(stat, uniqueIC);
            }
            catch (const char* msg) {
                cerr << msg << endl;
            }
        }
    }
}