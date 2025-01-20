#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
char board[11][11];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool visited[11][11][11][11];

struct state {
    int rx, ry, bx, by, cnt;
};

queue<state> q;

void move(int &x, int &y, int &c, int &i) {
    while (true) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx < 0 || nx >= N || ny < 0 || ny >= M || board[nx][ny] == '#') {
            break;
        }

        x = nx;
        y = ny;
        c++;
        
        if (board[x][y] == 'O') {
            break;
        }
    }
}

void bfs() {
    while (!q.empty()) {
        int rx = q.front().rx;
        int ry = q.front().ry;
        int bx = q.front().bx;
        int by = q.front().by;
        int cnt = q.front().cnt;
        q.pop();

        if (cnt >= 10) break;

        for (int i = 0; i < 4; i++) {
            int n_rx = rx;
            int n_ry = ry;
            int n_bx = bx;
            int n_by = by;

            int rc = 0;
            int bc = 0;
            int n_cnt = cnt + 1;

            move(n_rx, n_ry, rc, i);
            move(n_bx, n_by, bc, i);

            if (board[n_bx][n_by] == 'O') continue;
            if (board[n_rx][n_ry] == 'O') {
                cout << n_cnt << endl;
                return;
            }

            if (n_rx == n_bx && n_ry == n_by) {
                if (rc > bc) {
                    n_rx -= dx[i];
                    n_ry -= dy[i];
                } else {
                    n_bx -= dx[i];
                    n_by -= dy[i];
                }
            }

            if (visited[n_rx][n_ry][n_bx][n_by]) continue;

            visited[n_rx][n_ry][n_bx][n_by] = true;
            q.push({n_rx, n_ry, n_bx, n_by, n_cnt});
        }
    }

    cout << -1 << endl;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    int rx = 0, ry = 0, bx = 0, by = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 'R') {
                rx = i, ry = j;
            } else if (board[i][j] == 'B') {
                bx = i, by = j;
            }
        }
    }

    q.push({rx, ry, bx, by, 0});
    visited[rx][ry][bx][by] = true;
    bfs();

    return 0;
}