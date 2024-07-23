#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
    string s;
    vector<int> v;
    for(int i = l; i <= r; i++) {
        bool flag = true;
        s = to_string(i);
        for(char c: s) {
            if(c != '0' && c != '5') flag = false;
        }
        
        if(flag) {
            v.push_back(i);
        }
    }
    
    if(v.empty()) v.push_back(-1);
    return v;
}