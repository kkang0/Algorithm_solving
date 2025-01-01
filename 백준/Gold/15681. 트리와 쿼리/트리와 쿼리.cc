#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[100001];
int dp[100001];
bool visited[100001];

int dfs(int node) {
    visited[node] = true;
    dp[node] = 1;

    for (int child : graph[node]) {
        if (!visited[child]) {
            dp[node] += dfs(child);
        }
    }

    return dp[node];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, R, Q;
    cin >> N >> R >> Q;

    for(int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(R);

    for(int i = 0; i < Q; i++) {
        int U;
        cin >> U;
        
        cout << dp[U] << '\n';
    }

    return 0;
}