#include <iostream>
#include <cstring>
using namespace std;

int T, M, N, K;
int arr[51][51];
bool visited[51][51];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if (visited[nx][ny] || arr[nx][ny] == 0) continue;
        visited[nx][ny] = true;
        dfs(nx, ny);
    }
}

int main(void) {
    cin >> T;

    for (int i = 0; i < T; i++) {
        memset(arr, 0, sizeof(arr));
        memset(visited, false, sizeof(visited));

        cin >> M >> N >> K;

        for (int j = 0; j < K; j++) {
            int x, y;
            cin >> x >> y;
            arr[y][x] = 1;
        }

        int result = 0;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (!visited[j][k] && arr[j][k] == 1) {
                    visited[j][k] = true;
                    dfs(j, k);
                    result++;
                }
            }
        }

        cout << result << endl;
    }

    return 0;
}