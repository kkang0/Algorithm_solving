#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(string s) {
    map<char, int> m;
    for(char c: s) {
        m[c]++;
    }
    
    string str;
    for(auto i = m.begin(); i != m.end(); i++) {
        if(i->second == 1) str += i->first;
    }
    
    return str;
}