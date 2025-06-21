#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> w;
vector<bool> visited;
int result = 1e9;

void dfs(int start, int cur, int cnt, int cost) {
    if(cnt == N && w[cur][start] > 0) {
        result = min(result, cost + w[cur][start]);
        return;
    }

    for(int i = 0; i < N; i++) {
        if(!visited[i] && w[cur][i] > 0) {
            visited[i] = true;
            dfs(start, i, cnt + 1, cost + w[cur][i]);
            visited[i] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    w.resize(N, vector<int>(N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> w[i][j];
        }
    }

    visited.resize(N, false);
    for(int i = 0; i < N; i++) {
        fill(visited.begin(), visited.end(), false);
        visited[i] = true;
        dfs(i, i, 1, 0);
    }

    cout << result << '\n';

    return 0;
}