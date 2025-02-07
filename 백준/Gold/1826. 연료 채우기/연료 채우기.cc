#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int N, L, P;
pair<int, int> gas[10001];

int main(void) {
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> gas[i].first >> gas[i].second;
    }

    cin >> L >> P;

    sort(gas, gas + N);

    priority_queue<int> pq;
    int idx = 0;
    int cnt = 0;
    
    while (P < L) {
        while (idx < N && gas[idx].first <= P) {
            pq.push(gas[idx].second);
            idx++;
        }

        if (!pq.empty()) {
            P += pq.top();
            pq.pop();
            cnt++;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << cnt << endl;

    return 0;
}