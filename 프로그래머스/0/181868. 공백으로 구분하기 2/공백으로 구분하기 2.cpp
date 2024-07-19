#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> result;
    string s;
    for(int i = 0; i < my_string.length(); i++) {
        if(my_string[i] != ' ') s += my_string[i];
        else if (s != "") {
            result.push_back(s);
            s = "";
        }
    }
    
    if(s != "") result.push_back(s);
    return result;
}