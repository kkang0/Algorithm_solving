#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
    int N, K;
    cin >> N >> K;

    pair<int, int> jewel[300001];
    for(int i = 0; i < N; i++) {
        cin >> jewel[i].first >> jewel[i].second;
    }
    
    int bag[300001];
    priority_queue<int, vector<int>, less<int>> pq;

    for(int i = 0; i < K; i++) {
        cin >> bag[i];
    }

    sort(jewel, jewel + N);
    sort(bag, bag + K);

    int idx = 0;
    long long sum = 0;
    for(int i = 0; i < K; i++) {
        while(idx < N && bag[i] >= jewel[idx].first) {
            pq.push(jewel[idx].second);
            idx++;
        }

        if(!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }

    cout << sum << endl;

    return 0;
}