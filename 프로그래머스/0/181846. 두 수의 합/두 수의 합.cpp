#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string a, string b) {
    int carry = 0;
    string result;
    
    while (a.size() < b.size()) {
        a = '0' + a;
    }
    while (a.size() > b.size()) {
        b = '0' + b;
    }
    
    for(int i = a.size() - 1; i >= 0; --i) {
        int sum = (a[i] - '0') + (b[i] -'0') + carry;
        carry = sum / 10;
        result += (sum % 10) + '0';
    }
    
    if(carry) {
        result += carry + '0';
    }
    
    reverse(result.begin(), result.end());
    
    return result;
}