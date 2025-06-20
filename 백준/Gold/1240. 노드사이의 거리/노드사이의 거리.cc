#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<pair<int, int>> graph[1001];
bool visited[1001];
int result;

void dfs(int cur, int end, int dist) {
    if (cur == end) {
        result = dist;
        return;
    }

    visited[cur] = true;

    for (auto [w, next] : graph[cur]) {
        if (!visited[next]) {
            dfs(next, end, dist + w);
            if (result != -1) return;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N - 1; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        graph[u].emplace_back(d, v);
        graph[v].emplace_back(d, u);
    }

    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        fill(visited, visited + N + 1, false);
        result = -1;

        dfs(s, e, 0);
        cout << result << '\n';
    }

    return 0;
}