#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
    string s;
    cin >> s;

    int N;
    cin >> N;

    stack<char> ls, rs;
    for(char c: s) ls.push(c);

    for(int i = 0; i < N; i++) {
        char command;
        cin >> command;

        if(command == 'L') {
            if(!ls.empty()) {
                rs.push(ls.top());
                ls.pop();
            }
        } else if(command == 'D') {
            if(!rs.empty()) {
                ls.push(rs.top());
                rs.pop();
            }
        } else if(command == 'P') {
            char to_insert;
            cin >> to_insert;

            ls.push(to_insert);
        } else if(command == 'B') {
            if(!ls.empty()) {
                ls.pop();
            }
        }
    }
    
    string result;
    while(!ls.empty()) {
        result.push_back(ls.top());
        ls.pop();
    }

    reverse(result.begin(), result.end());

    while(!rs.empty()) {
        result.push_back(rs.top());
        rs.pop();
    }

    cout << result << endl;

    return 0;
}