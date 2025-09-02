#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int,int>> problems(N);
    for(int i = 0; i < N; i++) {
        cin >> problems[i].first >> problems[i].second;
    }

    sort(problems.begin(), problems.end());

    priority_queue<int, vector<int>, greater<int>> pq;

    for(auto &p : problems) {
        int deadline = p.first;
        int ramen = p.second;

        pq.push(ramen);
        if((int)pq.size() > deadline) {
            pq.pop();
        }
    }

    long long result = 0;
    while(!pq.empty()) {
        result += pq.top();
        pq.pop();
    }

    cout << result << "\n";
    return 0;
}