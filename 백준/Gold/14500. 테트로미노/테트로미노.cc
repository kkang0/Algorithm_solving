#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int>> board;
vector<vector<bool>> visited;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int result;

void dfs(int y, int x, int cnt, int sum) {
    if(cnt == 4) {
        result = max(result, sum);
        return;
    }

    visited[y][x] = true;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
        if(visited[ny][nx]) continue;
        
        visited[ny][nx] = true;
        dfs(ny, nx, cnt + 1, sum + board[ny][nx]);
        visited[ny][nx] = false;
    }

    visited[y][x] = false;
}

void T(int y, int x) {
    if(x >= 1 && y >= 1 && x + 1 < M) {
        result = max(result, board[y][x] + board[y - 1][x] + board[y][x - 1] + board[y][x + 1]);
    }
    if(y + 1 < N && x >= 1 && x + 1 < M) {
        result = max(result, board[y][x] + board[y][x - 1] + board[y][x + 1] + board[y + 1][x]);
    }
    if(y >= 1 && y + 1 < N && x + 1 < M) {
        result = max(result, board[y][x] + board[y - 1][x] + board[y][x + 1] + board[y + 1][x]);
    }
    if(x >= 1 && y + 1 < N && y >= 1) {
        result = max(result, board[y][x] + board[y - 1][x] + board[y][x - 1] + board[y + 1][x]);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    board.resize(N, vector<int>(M));
    visited.resize(N, vector<bool>(M));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            dfs(i, j, 1, board[i][j]);
            T(i, j);
        }
    }

    cout << result << '\n';

    return 0;
}