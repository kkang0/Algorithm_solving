#include <iostream>
#include <algorithm>
using namespace std;

int N, M, result;
int arr[501][501];
bool visited[501][501];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int y, int x, int d, int sum) {
    if(d == 3) {
        result = max(result, sum + arr[y][x]);
        return;
    }

    visited[y][x] = true;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
        if(!visited[ny][nx]) {
            visited[ny][nx] = true;
            dfs(ny, nx, d + 1, sum + arr[y][x]);
            visited[ny][nx] = false;
        }
    }
    visited[y][x] = false;
}

void T(int y, int x) {
    if(y >= 1 && x >= 1 && x + 1 < M)
        result = max(result, arr[y][x] + arr[y - 1][x] + arr[y][x - 1] + arr[y][x + 1]);
    if(y + 1 < N && x >= 1 && x + 1 < M)
        result = max(result, arr[y][x] + arr[y + 1][x] + arr[y][x - 1] + arr[y][x + 1]);
    if(y >= 1 && y + 1 < N && x + 1 < M)
        result = max(result, arr[y][x] + arr[y - 1][x] + arr[y + 1][x] + arr[y][x + 1]);
    if(y >= 1 && y + 1 < N && x >= 1)
        result = max(result, arr[y][x] + arr[y - 1][x] + arr[y + 1][x] + arr[y][x - 1]);
}

int main(void) {
    cin >> N >> M;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> arr[i][j];

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++) {
            dfs(i, j, 0, 0);
            T(i, j);
        }

    cout << result << endl;
    return 0;
}