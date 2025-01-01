#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> graph[1001];
bool visited[1001];
int cnt = 0;
int result = 0;

void dfs(int cur, int dest) {
    visited[cur] = true;

    for (pair<int, int> child : graph[cur]) {
        if (child.first == dest) {
            result = cnt + child.second;
            return;
        }
        if (!visited[child.first]) {
            cnt += child.second;
            dfs(child.first, dest);
            cnt -= child.second;
        }
    }
}

int main(void) {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N - 1; i++) {
        int u, v, e;
        cin >> u >> v >> e;

        graph[u].push_back({v, e});
        graph[v].push_back({u, e});
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        fill(visited, visited + 1001, false);
        cnt = 0;
        result = 0;

        dfs(u, v);

        cout << result << endl;
    }

    return 0;
}