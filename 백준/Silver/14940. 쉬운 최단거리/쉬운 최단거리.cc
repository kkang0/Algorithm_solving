#include <iostream>
#include <queue>
using namespace std;

int n, m;
int arr[1001][1001];
int visited[1001][1001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int sx, sy;

void bfs(int sx, int sy) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = 1;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(!visited[nx][ny] && arr[nx][ny] != 0) {
                visited[nx][ny] = visited[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

}

int main(void) {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 2) {
                sx = i;
                sy = j;
            }
        }
    }

    bfs(sx, sy);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 0) cout << 0 << " ";
            else cout << visited[i][j] - 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}