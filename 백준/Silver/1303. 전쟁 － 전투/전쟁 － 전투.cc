#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
char board[101][101];
int dx[4] = {1, -1, 0 , 0};
int dy[4] = {0, 0, 1, -1};

int bfs(int n, int m, char team) {
    bool visited[101][101] = {false};
    int sum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == team && !visited[i][j]) {
                queue<pair<int, int>> q;
                int count = 0;

                q.push(make_pair(i, j));
                visited[i][j] = true;

                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    count++;

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (visited[nx][ny] || board[nx][ny] != team) continue;

                        q.push(make_pair(nx, ny));
                        visited[nx][ny] = true;
                    }
                }
                sum += (count * count);
            }
        }
    }
    return sum;
}

int main() {
    int ally, enemy;
    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            board[i][j] = s[j];
        }
    }

    ally = bfs(N, M, 'W');
    enemy = bfs(N, M, 'B');

    cout << ally << ' ' << enemy << endl;
    return 0;
}
