#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int map[26][26];
bool visited[26][26];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<int> result;

int dfs(int x, int y) {
    int cnt = 1;
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if (visited[nx][ny] || map[nx][ny] != 1) continue;
        cnt += dfs(nx, ny);
    }
    return cnt;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j] && map[i][j] == 1) {
                int cnt = dfs(i, j);
                result.push_back(cnt);
            }
        }
    }

    sort(result.begin(), result.end());

    cout << result.size() << endl;
    for (int n : result) {
        cout << n << '\n';
    }

    return 0;
}