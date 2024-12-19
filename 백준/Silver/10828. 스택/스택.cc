#include <iostream>
#include <stack>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    stack<int> s;
    for(int i = 0; i < N; i++) {
        string command;
        cin >> command;

        if(command == "push") {
            int X;
            cin >> X;
            s.push(X);
        } else if(command == "pop") {
            if(s.empty()) cout << -1 << endl;
            else {
                cout << s.top() << endl;
                s.pop();
            }
        } else if(command == "size") {
            cout << s.size() << endl;
        } else if(command == "empty") {
            int result = s.empty() ? 1 : 0;
            cout << result << endl;
        } else if(command == "top") {
            if(s.empty()) cout << -1 << endl;
            else cout << s.top() << endl;
        }
    }

    return 0;
}