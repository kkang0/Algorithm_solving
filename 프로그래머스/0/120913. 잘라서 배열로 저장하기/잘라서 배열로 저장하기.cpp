#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    int sum = 0;
    string s;
    vector<string> result;
    for(char c: my_str) {
        if(sum < n) {
            s += c;
            sum++;
        } else {
            result.push_back(s);
            s = c;
            sum = 1;
        }
    }
    
    if (!s.empty()) {
        result.push_back(s);
    }
    
    return result;
}
