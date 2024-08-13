#include <iostream>
#include <queue>
using namespace std;

int N, M, K;
int trash[101][101] = {0};
bool visited[101][101] = {false};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(int x, int y) {
    int count = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(visited[nx][ny] || !trash[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push(make_pair(nx, ny));
            count++;
        }
    }

    return count;
}

int main(void) {
    cin >> N >> M >> K;
    int max_count = 0;

    for(int i = 0; i < K; i++) {
        int r, c;
        cin >> r >> c;
        trash[r-1][c-1] = 1;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(!visited[i][j] && trash[i][j]) {
                int result = bfs(i, j);
                if(result > max_count) max_count = result;
            }
        }
    }

    cout << max_count << endl;

    return 0;
}
