#include <string>
#include <vector>
#include <sstream>
using namespace std;

string solution(string polynomial) {
    stringstream ss(polynomial);
    string str;
    int xCoeff = 0;
    int constant = 0;
    
    while (ss >> str) {
        if (str == "+") continue;
        
        if (str.find('x') != string::npos) {
            if (str == "x") {
                xCoeff += 1;
            } else {
                int coef = stoi(str.substr(0, str.find('x')));
                xCoeff += coef;
            }
        } else {
            constant += stoi(str);
        }
    }
    
    string result;
    if (xCoeff != 0) {
        if (xCoeff == 1) result += "x";
        else result += to_string(xCoeff) + "x";
    }
    
    if (constant != 0) {
        if (!result.empty()) {
            result += " + ";
        }
        result += to_string(constant);
    }
    
    return result;
}
