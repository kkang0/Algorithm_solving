#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(string my_string) {
    string s;
    vector<string> result;
    for(int i = 0; i < my_string.length(); i++) {
        if(my_string[i] != ' ') s += my_string[i];
        else {
            result.push_back(s);
            s = "";
        }
    }
    
    result.push_back(s);
    
    return result;
}