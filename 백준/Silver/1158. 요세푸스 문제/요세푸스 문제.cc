#include <iostream>
#include <deque>
using namespace std;

int main(void) {
    int N, K;
    cin >> N >> K;

    int cnt = 1;
    deque<int> dq;

    for(int i = 1; i <= N; i++) dq.push_back(i);

    cout << "<";
    while(!dq.empty()) {
        if(cnt == K) {
            cout << dq.front();
            dq.pop_front();
            cnt = 1;

            if(!dq.empty()) cout << ", ";
        } else {
            dq.push_back(dq.front());
            dq.pop_front();
            cnt++;
        }
    }

    cout << ">" << endl;

    return 0;
}