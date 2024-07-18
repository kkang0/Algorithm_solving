#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strArr) {
    vector<string> result;
    for(int i = 0; i < strArr.size(); i++) {
        if(i % 2 != 0) {
            string s = strArr[i];
            transform(s.begin(), s.end(), s.begin(), ::toupper);
            result.push_back(s);
        } else {
            string s = strArr[i];
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            result.push_back(s);
        }
    }
    
    return result;
}