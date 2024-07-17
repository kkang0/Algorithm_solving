#include <string>
#include <vector>

using namespace std;

string solution(vector<string> arr) {
    string s;
    for(string str: arr) {
        s += str;
    }
    
    return s;
}