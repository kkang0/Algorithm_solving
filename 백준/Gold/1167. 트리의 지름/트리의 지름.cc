#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V;
vector<pair<int, int>> tree[100001];
vector<bool> visited;
int result = 0;
int far_node = 0;

void dfs(int n, int d) {
    visited[n] = true;

    if (d > result) {
        result = d;
        far_node = n;
    }

    for (int i = 0; i < tree[n].size(); i++) {
        int next = tree[n][i].first;
        int distance = tree[n][i].second;

        if (!visited[next]) dfs(next, d + distance);
    }
}

int main(void) {
    cin >> V;

    for (int i = 0; i < V; i++) {
        int n;
        cin >> n;
        while (true) {
            int v, d;
            cin >> v;
            if (v == -1) break;
            cin >> d;
            tree[n].push_back({v, d});
        }
    }

    visited.resize(V + 1, false);
    dfs(1, 0);

    fill(visited.begin(), visited.end(), false);
    result = 0;
    dfs(far_node, 0);

    cout << result << endl;

    return 0;
}