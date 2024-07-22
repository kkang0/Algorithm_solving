#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numLog) {
    string str;
    for(int i = 0; i < numLog.size() - 1; i++) {
        int n = numLog[i + 1] - numLog[i];
        switch(n) {
            case 1: str += "w";
                break;
            case -1: str += "s"; 
                break;
            case 10: str += "d"; 
                break;
            case -10: str += "a"; 
                break;       
        }
    }
    return str;
}