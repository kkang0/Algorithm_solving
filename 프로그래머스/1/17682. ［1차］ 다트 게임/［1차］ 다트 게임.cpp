#include <string>
#include <vector>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> result;
    string num = "";
    int idx = 0;
    
    for(int i = 0; i < dartResult.size(); i++) {
        char c = dartResult[i];
        
        if(isdigit(c)) {
            num += c;
        }
        else if(c == 'S') {
            result.push_back(stoi(num));
            num = "";
            idx++;
        } else if(c == 'D') {
            result.push_back(stoi(num) * stoi(num));
            num = "";
            idx++;
        } else if(c == 'T') {
            result.push_back(stoi(num) * stoi(num) * stoi(num));
            num = "";
            idx++;
        }
        else if(c == '*') {
            if(idx == 1) {
                result[idx - 1] *= 2;
            } else {
                result[idx - 1] *= 2;
                result[idx - 2] *= 2;
            }
        }
        else if(c == '#') {
            result[idx - 1] = -result[idx - 1];
        }
    }
    
    for(int i = 0; i < result.size(); i++) {
        answer += result[i];
    }
    
    return answer;
}
