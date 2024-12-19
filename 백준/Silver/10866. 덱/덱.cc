#include <iostream>
#include <deque>
using namespace std;

int main(void) {
    int N;
    cin >> N;
    
    deque<int> dq;
    for(int i = 0; i < N; i++) {
        string command;
        cin >> command;

        if(command == "push_front") {
            int num;
            cin >> num;
            dq.push_front(num);
        } else if(command == "push_back") {
            int num;
            cin >> num;
            dq.push_back(num);
        } else if(command == "pop_front") {
            if(dq.empty()) cout << -1 << endl;
            else {
                cout << dq.front() << endl;
                dq.pop_front();
            }
        } else if(command == "pop_back") {
            if(dq.empty()) cout << -1 << endl;
            else {
                cout << dq.back() << endl;
                dq.pop_back();
            }
        } else if(command == "size") {
            cout << dq.size() << endl;
        } else if(command == "empty") {
            if(dq.empty()) cout << 1 << endl;
            else cout << 0 << endl;
        } else if(command == "front") {
            if(dq.empty()) cout << -1 << endl;
            else cout << dq.front() << endl;
        } else if(command == "back") {
            if(dq.empty()) cout << -1 << endl;
            else cout << dq.back() << endl;
        }
    }

    return 0;
}