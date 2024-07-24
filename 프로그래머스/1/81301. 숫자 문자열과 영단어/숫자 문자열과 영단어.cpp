#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    map<string, char> m;
    m["zero"] = '0';
    m["one"] = '1';
    m["two"] = '2';
    m["three"] = '3';
    m["four"] = '4';
    m["five"] = '5';
    m["six"] = '6';
    m["seven"] = '7';
    m["eight"] = '8';
    m["nine"] = '9';
    
    string result;
    string word;
    
    for (char c : s) {
        if (isdigit(c)) {
            result += c;
        } else {
            word += c;
            if (m.find(word) != m.end()) {
                result += m[word];
                word.clear();
            }
        }
    }
    
    return stoi(result);
}
