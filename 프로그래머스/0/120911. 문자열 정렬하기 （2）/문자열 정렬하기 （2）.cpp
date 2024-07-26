#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string my_string) {
    string str;
    for(char c: my_string) {
        str += tolower(c);
    }
    sort(str.begin(), str.end());
    return str;
}