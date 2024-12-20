#include <iostream>
#include <deque>
using namespace std;

int main(void) {
    int N;
    cin >> N;

    deque<int> dq;
    for(int i = 1; i <= N; i++) dq.push_back(i);


    while(dq.size() != 1) {
        dq.pop_front();
        int front = dq.front();
        dq.pop_front();
        dq.push_back(front);
    }

    cout << dq.front() << endl;

    return 0;
}