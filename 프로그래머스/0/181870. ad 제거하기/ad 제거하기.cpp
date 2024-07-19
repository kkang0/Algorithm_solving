#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
    vector<string> s;
    for(int i = 0; i < strArr.size(); i++) {
        if(strArr[i].find("ad") == string::npos) s.push_back(strArr[i]);
    }
    
    return s;
}