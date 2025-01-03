#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<string> v;
int d[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int n, int m) {
    queue<pair<int, int>> q;
    q.push({n, m});
    d[n][m] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 1 || ny < 1 || nx > N || ny > M) continue;
            if (v[nx - 1][ny - 1] == '0') continue;
            if (d[nx][ny] != 0) continue;

            d[nx][ny] = d[x][y] + 1;
            q.push({nx, ny});
        }
    }
}

int main(void) {
    cin >> N >> M;
    v.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    bfs(1, 1);

    cout << d[N][M] << endl;

    return 0;
}