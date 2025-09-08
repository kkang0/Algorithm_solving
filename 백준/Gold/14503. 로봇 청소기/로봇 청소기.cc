#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> board;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    board.resize(N, vector<int>(M));

    int r, c, d;
    cin >> r >> c >> d;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    int cnt = 0;
    while (true) {
        if (board[r][c] == 0) {
            board[r][c] = 2;
            cnt++;
        }

        bool cleanable = false;
        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
                if (board[nr][nc] == 0) {
                    cleanable = true;
                    break;
                }
            }
        }

        if (cleanable) {
            d = (d + 3) % 4;
            int nr = r + dx[d];
            int nc = c + dy[d];
            if (board[nr][nc] == 0) {
                r = nr;
                c = nc;
            }
        } else {
            int backDir = (d + 2) % 4;
            int nr = r + dx[backDir];
            int nc = c + dy[backDir];
            if (board[nr][nc] == 1) {
                break;
            } else {
                r = nr;
                c = nc;
            }
        }
    }

    cout << cnt << '\n';
    return 0;
}