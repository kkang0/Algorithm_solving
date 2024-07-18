#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    string s;
    for(char c: myString) {
        if(c == 'A') s += 'B';
        else if (c == 'B') s += 'A';
    }
    
    return s.find(pat) != string::npos ? 1 : 0;
}