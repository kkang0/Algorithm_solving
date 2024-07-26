#include <string>
#include <vector>

using namespace std;

string solution(string rsp) {
    string result;
    for(char c: rsp) {
        if(c == '2') result += "0";
        if(c == '0') result += "5";
        if(c == '5') result += "2";
    }
    return result;
}