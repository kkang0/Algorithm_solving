#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int n, m;
int s, e;
vector<pair<int, int>> graph[1001];
vector<int> dist;
vector<int> pre;

void dijkstra() {
    priority_queue<pair<int, int>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost) continue;

        for (auto [next, ncost] : graph[cur]) {
            if (dist[next] > cost + ncost) {
                dist[next] = cost + ncost;
                pre[next] = cur;
                pq.push({-dist[next], next});
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    cin >> m;

    dist.resize(n + 1, INF);
    pre.resize(n + 1, -1);
    for(int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({to, cost});
    }

    cin >> s >> e;
    dijkstra();

    cout << dist[e] << '\n';

    vector<int> path;
    for(int i = e; i != -1; i = pre[i]) {
        path.push_back(i);
    }
    reverse(path.begin(), path.end());

    cout << path.size() << '\n';
    for(int p: path) cout << p << ' ';
    cout << '\n';

    return 0;
}