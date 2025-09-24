#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
vector<int> friends[101];

int bfs(int s) {
    vector<int> dist(N + 1, -1);
    queue<int> q;
    q.push(s);
    dist[s] = 0;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int next: friends[cur]) {
            if(dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }

    int sum = 0;
    for(int i = 1; i <= N; i++) sum += dist[i];

    return sum;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    vector<pair<int, int>> result;
    for(int i = 1; i <= N; i++) {
        result.push_back({bfs(i), i});
    }

    sort(result.begin(), result.end());

    cout << result[0].second << '\n';

    return 0;
}