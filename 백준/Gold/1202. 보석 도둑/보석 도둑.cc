#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> jewel(N);
    for(int i = 0; i < N; i++) {
        cin >> jewel[i].first >> jewel[i].second;
    }

    sort(jewel.begin(), jewel.end());

    vector<int> bag(K);
    for(int i = 0; i < K; i++) {
        cin >> bag[i];
    }

    sort(bag.begin(), bag.end());

    priority_queue<int, vector<int>, less<int>> pq;
    long long result = 0;
    int idx = 0;
    for(int i = 0; i < K; i++) {
        while(idx < N && bag[i] >= jewel[idx].first) {
            pq.push(jewel[idx].second);
            idx++;
        }

        if(!pq.empty()) {
            result += pq.top();
            pq.pop();
        }
    }

    cout << result << "\n";

    return 0;
}