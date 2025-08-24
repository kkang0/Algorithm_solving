#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int mp[105][105];
bool visited[105][105];
int cnt;

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (visited[nx][ny] || mp[nx][ny] == 1) continue;
        dfs(nx, ny);
    }
}

void melting() {
    vector<pair<int,int>> meltList;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == 1) {
                int airTouch = 0;
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (visited[nx][ny]) airTouch++;
                }
                if (airTouch >= 2) {
                    meltList.push_back({i, j});
                }
            }
        }
    }
    for (auto &p : meltList) {
        mp[p.first][p.second] = 0;
        cnt--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == 1) cnt++;
        }
    }

    int time = 0;
    while (cnt > 0) {
        time++;
        memset(visited, 0, sizeof(visited));
        dfs(0, 0);
        melting();
    }

    cout << time << "\n";
    return 0;
}