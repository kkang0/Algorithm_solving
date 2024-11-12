#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int visited[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int solution(vector<vector<int>> maps) {
    queue<pair<int, int>> q;
    int n = maps.size();
    int m = maps[0].size();
    memset(visited, 0, sizeof(visited));
    
    q.push({0, 0});
    visited[0][0] = 1;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if (x == n - 1 && y == m - 1) return visited[x][y];
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (!visited[nx][ny] && maps[nx][ny] == 1) {
                q.push({nx, ny});
                visited[nx][ny] = visited[x][y] + 1;
            }
        }
    }
    
    return visited[n - 1][m - 1] == 0 ? -1 : visited[n - 1][m - 1];
}