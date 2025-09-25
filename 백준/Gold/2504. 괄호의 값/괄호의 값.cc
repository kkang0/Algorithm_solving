#include <iostream>
#include <stack>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string x;
    cin >> x;

    stack<int> s;
    for(char c: x) {
        if(c == '(') s.push(-1);
        else if(c == '[') s.push(-2);
        else if(c == ')') {
            int num = 0;
            while(true) {
                if(s.empty()) {
                    cout << 0 << '\n';
                    return 0;
                }

                if(s.top() == -1) break;
                if(s.top() == -2) {
                    cout << 0 << '\n';
                    return 0;
                }

                num += s.top();
                s.pop();
            }

            s.pop();
            if(num == 0) num = 1;
            s.push(num * 2);

        } else if(c == ']') {
            int num = 0;
            while(true) {
                if(s.empty()) {
                    cout << 0 << '\n';
                    return 0;
                }

                if(s.top() == -2) break;
                if(s.top() == -1) {
                    cout << 0 << '\n';
                    return 0;
                }

                num += s.top();
                s.pop();
            }

            s.pop();
            if(num == 0) num = 1;
            s.push(num * 3);
        }
    }

    int result = 0;
    while(!s.empty()) {
        if(s.top() < 0) {
            cout << 0 << '\n';
            return 0;
        }
        result += s.top();
        s.pop();
    }

    cout << result << '\n';

    return 0;
}