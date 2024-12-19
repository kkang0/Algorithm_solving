#include <iostream>
#include <stack>
using namespace std;

int main(void) {
    int T;
    cin >> T;

    for(int i = 0; i < T; i++) {
        string input;
        cin >> input;

        stack<char> s;
        bool flag = true;
        for(char c: input) {
            if(c == '(') s.push(c);
            else if(c == ')') {
                if(!s.empty() && s.top() == '(') {
                    s.pop();
                } else {
                    flag = false;
                    break;
                }
            }
        }

        if(!s.empty()) flag = false;

        string result = flag ? "YES" : "NO";
        cout << result << endl;
    }

    return 0;
}