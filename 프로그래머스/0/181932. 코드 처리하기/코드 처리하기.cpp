#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string ret;
    int mode = 0;
    for(int i = 0; i < code.size(); i++) {
        if(mode == 0) {
            if(code[i] != '1' && i % 2 == 0) ret += code[i];
            if(code[i] == '1') mode = 1;
        } else {
            if(code[i] != '1' && i % 2 != 0) ret += code[i];
            if(code[i] == '1') mode = 0;
        }
    }
    
    if(ret.empty()) return "EMPTY";
    return ret;
}