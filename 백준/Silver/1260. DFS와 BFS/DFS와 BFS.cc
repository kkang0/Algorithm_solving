#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, V;
vector<int> graph[1001];
bool visited[1001];

void dfs(int start) {
    cout << start << " ";
    visited[start] = true;

    for(int next: graph[start]) {
        if(!visited[next]) {
            dfs(next);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int cur = q.front();
        cout << cur << " ";
        q.pop();

        for(int next: graph[cur]) {
            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> V;
    for(int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;

        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    for(int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(V);
    fill(visited, visited + 1001, 0);
    cout << "\n";
    bfs(V);
    cout << "\n";

    return 0;
}