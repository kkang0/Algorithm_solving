#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> tree[1000001];
int dp[1000001][2];
bool visited[1000001];

void dfs(int n) {
    visited[n] = true;
    dp[n][0] = 1;
    dp[n][1] = 0;

    for (int child : tree[n]) {
        if (!visited[child]) {
            dfs(child);

            dp[n][1] += dp[child][0];
            dp[n][0] += min(dp[child][0], dp[child][1]);
        }
    }
}

int main(void) {
    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    fill(visited, visited + N + 1, false);
    dfs(1);

    cout << min(dp[1][0], dp[1][1]) << endl;

    return 0;
}