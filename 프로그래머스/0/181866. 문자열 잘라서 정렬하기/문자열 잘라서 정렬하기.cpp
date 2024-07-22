#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> solution(string myString) {
    vector<string> s;
    string cur;
    for(int i = 0; i < myString.size(); i++) {
        if(myString[i] != 'x') cur += myString[i];
        else if(myString[i] == 'x' && cur != "") {
            s.push_back(cur);
            cur = "";
        }
    }
    if(cur != "") s.push_back(cur);
    sort(s.begin(), s.end());
    
    return s;
}