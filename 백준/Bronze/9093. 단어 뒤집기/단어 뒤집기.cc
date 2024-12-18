#include <iostream>
#include <stack>
using namespace std;

int main(void) {
    string T_str;
    getline(cin, T_str);
    int T = stoi(T_str);

    for(int i = 0; i < T; i++) {
        string s;
        getline(cin, s);

        stack<char> stk;
        for(char c: s) {
            if(c != ' ') {
                stk.push(c);
            } else {
                while(!stk.empty()) {
                    cout << stk.top();
                    stk.pop();
                }
                cout << c;
            }
        }

        while(!stk.empty()) {
            cout << stk.top();
            stk.pop();
        }
        cout << endl;
    }

    return 0;
}