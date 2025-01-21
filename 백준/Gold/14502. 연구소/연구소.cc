#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[9][9];
int tmp[9][9];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int result = 0;

void bfs() {
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            tmp[i][j] = arr[i][j];
            if (tmp[i][j] == 2) q.push({i, j});
        }
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (tmp[nx][ny] == 0) {
                tmp[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tmp[i][j] == 0) cnt++;
        }
    }
    result = max(result, cnt);
}

void dfs(int count) {
    if (count == 3) {
        bfs();
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0) {
                arr[i][j] = 1;
                dfs(count + 1);
                arr[i][j] = 0;
            }
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    dfs(0);
    cout << result << endl;

    return 0;
}