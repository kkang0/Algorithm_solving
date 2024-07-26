#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(int age) {
    map<char, char> m;
    m['0'] = 'a';
    m['1'] = 'b';
    m['2'] = 'c';
    m['3'] = 'd';
    m['4'] = 'e';
    m['5'] = 'f';
    m['6'] = 'g';
    m['7'] = 'h';
    m['8'] = 'i';
    m['9'] = 'j';
    
    string str = to_string(age);
    string result;
    for(char c: str) {
        result += m[c];
    }
    
    return result;
}