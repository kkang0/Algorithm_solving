#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int N, E, v1, v2;
vector<pair<int, int>> graph[801];
int dist[801];
int result;

void dikjstra(int start) {
    for(int i = 1; i <= N; i++) dist[i] = INF;

    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(dist[cur] < cost) continue;

        for(int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int nCost = graph[cur][i].second;

            if(dist[next] > dist[cur] + nCost) {
                dist[next] = dist[cur] + nCost;
                pq.push({-dist[next], next});
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> E;
    for(int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    cin >> v1 >> v2;

    dikjstra(1);
    int s_v1 = dist[v1];
    int s_v2 = dist[v2];

    dikjstra(v1);
    int v1_v2 = dist[v2];
    int v1_n = dist[N];

    dikjstra(v2);
    int v2_v1 = dist[v1];
    int v2_n = dist[N];

    int dist1 = s_v1 + v1_v2 + v2_n;
    int dist2 = s_v2 + v2_v1 + v1_n;

    if (s_v1 >= INF || v1_v2 >= INF || v2_n >= INF) dist1 = INF;
    if (s_v2 >= INF || v2_v1 >= INF || v1_n >= INF) dist2 = INF;

    result = min(dist1, dist2);

    if(result >= INF) cout << -1 << '\n';
    else cout << result << '\n';

    return 0;
}