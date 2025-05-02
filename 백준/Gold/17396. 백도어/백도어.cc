#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const long long INF = 1e13;
vector<pair<long long, long long>> path[100001];
long long dist[100001];

void dijkstra(int start) {
    priority_queue<pair<long long, long long>> pq;

    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()) {
        long long cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(dist[cur] < cost) continue;

        for(int i = 0; i < path[cur].size(); i++) {
            long long ncost = cost + path[cur][i].first;

            if(ncost < dist[path[cur][i].second]) {
                dist[path[cur][i].second] = ncost;
                pq.push({-ncost, path[cur][i].second});
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> sight(N);
    for(int i = 0; i < N; i++) {
        cin >> sight[i];
        dist[i] = INF;
    }
    
    for(int i = 0; i < M; i++) {
        int u, v, d;
        cin >> u >> v >> d;

        if (sight[u] == 1 && u != N - 1) continue;
        if (sight[v] == 1 && v != N - 1) continue;

        path[u].push_back({d, v});
        path[v].push_back({d, u});
    }

    dijkstra(0);

    if (dist[N - 1] == INF) cout << -1 << '\n';
    else cout << dist[N - 1] << '\n';

    return 0;
}