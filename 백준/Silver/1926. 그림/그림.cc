#include <iostream>
#include <queue>
using namespace std;

int n, m, total;
int pic[501][501];
bool visited[501][501] = {false};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;

int bfs(int x, int y) {
    int count = 1;
    q.push(make_pair(x, y));
    visited[x][y] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(visited[nx][ny] || !pic[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push(make_pair(nx, ny));
            count++;
        }
    }

    total++;
    return count;
}

int main(void) {
    cin >> n >> m;
    int max_count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> pic[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!visited[i][j] && pic[i][j]) {
                int count = bfs(i, j);
                if(count > max_count) max_count = count;
            }
        }
    }

    cout << total << endl;
    cout << max_count << endl;

    return 0;
}