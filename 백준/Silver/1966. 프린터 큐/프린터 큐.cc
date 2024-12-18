#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N, M;
        cin >> N >> M;

        queue<pair<int, int>> q;
        priority_queue<int> pq;

        for (int j = 0; j < N; j++) {
            int priority;
            cin >> priority;
            q.push({priority, j});
            pq.push(priority);
        }

        int printOrder = 0;
        while (!q.empty()) {
            int curPriority = q.front().first;
            int curIndex = q.front().second;
            q.pop();

            if (curPriority == pq.top()) {
                pq.pop();
                printOrder++;
                if (curIndex == M) {
                    cout << printOrder << endl;
                    break;
                }
            } else {
                q.push({curPriority, curIndex});
            }
        }
    }

    return 0;
}