#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int n, m, x;
vector<int> dist[2];
vector<pair<int, int>> graph[2][1001];

void dijkstra(int k) {
    dist[k][x] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, x});

    while (!pq.empty()) {
        int d = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (d > dist[k][now]) continue;

        for (auto& edge : graph[k][now]) {
            int next_d = d + edge.first;
            int next = edge.second;

            if (next_d < dist[k][next]) {
                dist[k][next] = next_d;
                pq.push({next_d, next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> x;

    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        graph[0][a].push_back({t, b});
        graph[1][b].push_back({t, a});
    }

    dist[0].resize(n + 1, INF);
    dist[1].resize(n + 1, INF);

    dijkstra(0);
    dijkstra(1);

    int result = 0;
    for (int i = 1; i <= n; i++) {
        result = max(result, dist[0][i] + dist[1][i]);
    }

    cout << result << '\n';
    return 0;
}