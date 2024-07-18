#include <string>
#include <vector>

using namespace std;

string solution(string rny_string) {
    string ans;
    for(char s : rny_string) {
        if (s == 'm') ans += "rn";
        else ans += s;
    }
    
    return ans;
}