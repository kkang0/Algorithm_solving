#include <iostream>
#include <stack>
using namespace std;

int main(void) {
    string s;
    getline(cin, s);

    stack<char> stk;
    bool tag = false;

    for (char c : s) {
        if (c == '<') {
            while (!stk.empty()) {
                cout << stk.top();
                stk.pop();
            }
            cout << c;
            tag = true;
        } else if (c == '>') {
            cout << c;
            tag = false;
        } else if (tag) {
            cout << c;
        } else {
            if (c == ' ') {
                while (!stk.empty()) {
                    cout << stk.top();
                    stk.pop();
                }
                cout << c;
            } else {
                stk.push(c);
            }
        }
    }

    while (!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }

    cout << endl;
    return 0;
}