#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    for(string s: quiz) {
        stringstream ss(s);
        string str;
        vector<string> v;
        while(ss >> str) {
            v.push_back(str);
        }
        
        int a = stoi(v[0]);
        string op = v[1];
        int b = stoi(v[2]);
        int result = stoi(v[4]);
        int n;
        if(op == "+") a + b == result ? answer.push_back("O") : answer.push_back("X");
        else if (op == "-") a - b == result ? answer.push_back("O") : answer.push_back("X");
    }
    
    return answer;
}