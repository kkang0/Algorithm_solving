#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, S, E;
vector<pair<int, int>> bridge[100001];

bool bfs(int start, int end, int m) {
    queue<int> q;
    vector<bool> visited(N + 1, false);
    visited[start] = true;
    q.push(start);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        if(cur == end) return true;

        for(int i = 0; i < bridge[cur].size(); i++) {
            int next = bridge[cur][i].first;
            int weight = bridge[cur][i].second;

            if(!visited[next] && weight >= m) {
                visited[next] = true;
                q.push(next);
            }
        }
    }

    return false;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    int max_weight = 0;
    for(int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        bridge[A].push_back({B, C});
        bridge[B].push_back({A, C});

        max_weight = max(max_weight, C);
    }

    cin >> S >> E;
    int start = 0;
    int end = max_weight;

    while(start <= end) {
        int mid = (start + end) / 2;

        if(bfs(S, E, mid)) start = mid + 1;
        else end = mid - 1;
    }

    cout << end << '\n';

    return 0;
}