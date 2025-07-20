#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;
int n, m, s, t;
vector<pair<int, int>> graph[5001];
int dist[5001];

void dikjstra(int start) {
    for(int i = 1; i <= n; i++) dist[i] = INF;
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
                pq.push({dist[next], next});
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    cin >> s >> t;

    dikjstra(s);
    cout << dist[t] << '\n';

    return 0;
}