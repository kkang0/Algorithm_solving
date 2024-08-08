#include <iostream>
using namespace std;

int R, C, K;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int graph[5][5];
int visited[5][5];

int dfs(int y, int x, int dist) {
    if(y == 0 && x == C - 1) {
        return dist == K ? 1 : 0;
    }
    
    visited[y][x] = 1;
    int result = 0;

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
        if(!visited[ny][nx] && graph[ny][nx] == 0)
            result += dfs(ny, nx, dist + 1);
    }
    
    visited[y][x] = 0;

    return result;
}

int main() {
    cin >> R >> C >> K;

    for(int i = 0; i < R; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < C; j++) {
            if(s[j] == 'T') graph[i][j] = 1;
            else graph[i][j] = 0;
        }
    }
    
    int result = dfs(R - 1, 0, 1);

    cout << result << endl;

    return 0;
}