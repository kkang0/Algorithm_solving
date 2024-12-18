#include <iostream>
#include <stack>
using namespace std;

int main(void) {
    string s;
    cin >> s;

    stack<char> stk;
    int result = 0;
    for(int i = 0; i < s.size(); i++) {
        char c = s[i];

        if(c == '(') {
            stk.push(c);
        } else if(c == ')' && s[i - 1] == '(') {
            stk.pop();
            result += stk.size();
        } else {
            result++;
            stk.pop();
        }
    }

    cout << result << endl;

    return 0;
}