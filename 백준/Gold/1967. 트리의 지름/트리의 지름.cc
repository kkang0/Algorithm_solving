#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> tree[10001];
bool visited[10001];
int max_cost = 0;
int max_node = 0;

void dfs(int node, int cost) {
    visited[node] = true;

    if(max_cost < cost) {
        max_cost = cost;
        max_node = node;
    }

    for(int i = 0; i < tree[node].size(); i++) {
        int next = tree[node][i].first;
        int nextCost = tree[node][i].second;

        if(!visited[next]) {
            dfs(next, cost + nextCost);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        int from ,to, cost;
        cin >> from >> to >> cost;

        tree[from].push_back({to, cost});
        tree[to].push_back({from, cost});
    }

    dfs(1, 0);
    fill(visited, visited + n + 1, false);
    dfs(max_node, 0);

    cout << max_cost << "\n";

    return 0;
}