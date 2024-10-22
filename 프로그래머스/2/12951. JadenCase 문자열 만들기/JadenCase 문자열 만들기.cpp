#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    for(int i = 0; i < s.size(); i++) {
        if(i > 0 && isdigit(s[i - 1]) && !isdigit(s[i])) s[i] = tolower(s[i]);
        if(i == 0) s[i] = toupper(s[i]);
        else if(i > 0 && s[i - 1] == ' ') s[i] = toupper(s[i]);
        else s[i] = tolower(s[i]);
    }
    
    return s;
}