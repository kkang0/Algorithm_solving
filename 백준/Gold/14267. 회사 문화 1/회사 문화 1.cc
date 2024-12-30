#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[100001];
int emp[100001];
int dp[100001];
bool visited[100001];

void dfs(int n) {
    visited[n] = true;

    for(int i = 0; i < tree[n].size(); i++) {
        int next = tree[n][i];
        if(visited[next]) continue;
        dp[next] += dp[n];

        dfs(next);
    }
}

int main(void) {
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        int num;
        cin >> num;

        emp[i] = num;

        if(num != -1) {
            tree[num].push_back(i);
        }
    }

    for(int j = 0; j < m; j++) {
        int i, w;
        cin >> i >> w;
        dp[i] += w;
    }

    dfs(1);

    for(int i = 1; i <= n; i++)
        cout << dp[i] << " ";

    return 0;
}