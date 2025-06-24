#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;
vector<pair<int, int>> rooms;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    rooms.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> rooms[i].first >> rooms[i].second;
    }

    sort(rooms.begin(), rooms.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(rooms[0].second);

    for(int i = 1; i < N; i++) {
        if(pq.top() <= rooms[i].first) pq.pop();
        pq.push(rooms[i].second);
    }

    cout << pq.size() << '\n';

    return 0;
}