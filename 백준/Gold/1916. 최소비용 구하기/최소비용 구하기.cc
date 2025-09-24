#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;
int N, M, S, E;
vector<pair<int, int>> v[1001];
vector<int> dist;

void dikjstra() {
    priority_queue<pair<int, int>> pq;
    pq.push({0, S});
    dist[S] = 0;

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(dist[cur] < cost) continue;

        for(int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            int nCost = v[cur][i].second;

            if(dist[next] > cost + nCost) {
                dist[next] = cost + nCost;
                pq.push({-dist[next], next});
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    dist.resize(N + 1, INF);
    for(int i = 0; i < M; i++) {
        int s, e, d;
        cin >> s >> e >> d;
        v[s].push_back({e, d});
    }

    cin >> S >> E;
    dikjstra();

    cout << dist[E] << '\n';

    return 0;
}