#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string my_string, int s, int e) {
    string substr = my_string.substr(s, e - s + 1);
    string str = my_string.erase(s, e - s + 1);
    reverse(substr.begin(), substr.end());
    string result = my_string.insert(s, substr);
    
    return result;
}