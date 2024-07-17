#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> s;
    for(int i = 0; i < my_string.length(); i++) {
        s.push_back(my_string.substr(i));
    }
    
    sort(s.begin(), s.end());
    
    return s;
}