#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> tree[10001];
bool visited[10001];
int max_num = 0;
int max_node = 0;

void dfs(int n, int d) {
    visited[n] = true;

    if(max_num < d) {
        max_num = d;
        max_node = n;
    }

    for(int i = 0; i < tree[n].size(); i++) {
        int next = tree[n][i].first;
        int weight = tree[n][i].second;

        if(!visited[next]) {
            dfs(next, d + weight);
        }
    }
}

int main(void) {
    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        int u, v, d;
        cin >> u >> v >> d;

        tree[u].push_back({v, d});
        tree[v].push_back({u, d});
    }

    dfs(1, 0);
    fill(visited, visited + n + 1, false);
    max_num = 0;
    dfs(max_node, max_num);

    cout << max_num << endl;

    return 0;
}