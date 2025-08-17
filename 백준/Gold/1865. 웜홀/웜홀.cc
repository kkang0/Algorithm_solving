#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;
vector<pair<pair<int, int>, int>> edges;
int dist[501];

bool bellmanFord(int n) {
    for (int i = 1; i <= n; i++) dist[i] = 0;

    for (int i = 1; i <= n-1; i++) {
        for (auto &e : edges) {
            int from = e.first.first;
            int to = e.first.second;
            int cost = e.second;

            if (dist[from] != INF && dist[to] > dist[from] + cost) {
                dist[to] = dist[from] + cost;
            }
        }
    }

    for (auto &e : edges) {
        int from = e.first.first;
        int to = e.first.second;
        int cost = e.second;
        if (dist[from] != INF && dist[to] > dist[from] + cost) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        edges.clear();
        int n, m, w; cin >> n >> m >> w;

        for (int i = 0; i < m; i++) {
            int s, e, t; cin >> s >> e >> t;
            edges.push_back({{s, e}, t});
            edges.push_back({{e, s}, t});
        }

        for (int i = 0; i < w; i++) {
            int s, e, t; cin >> s >> e >> t;
            edges.push_back({{s, e}, -t});
        }

        if (bellmanFord(n)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}