#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, N;
vector<vector<int>> banner;
vector<vector<bool>> visited;
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = true;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            if (visited[nx][ny]) continue;
            if (banner[nx][ny] == 0) continue;

            visited[nx][ny] = true;
            q.push(make_pair(nx, ny));
        }
    }
}

int main(void) {
    int total = 0;
    cin >> M >> N;

    banner.resize(M, vector<int>(N));
    visited.resize(M, vector<bool>(N, false));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> banner[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j] && banner[i][j] == 1) {
                bfs(i, j);
                total++;
            }
        }
    }

    cout << total << endl;

    return 0;
}
