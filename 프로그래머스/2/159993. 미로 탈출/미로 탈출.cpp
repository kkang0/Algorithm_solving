#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(vector<string>& maps, int startX, int startY, char target) {
    int n = maps.size();
    int m = maps[0].size();
    int visited[101][101];
    memset(visited, -1, sizeof(visited));
    
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = 0;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if (maps[x][y] == target) {
            return visited[x][y];
        }
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || maps[nx][ny] == 'X') continue;
            if (visited[nx][ny] == -1) {
                visited[nx][ny] = visited[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    return -1;
}

int solution(vector<string> maps) {
    int startX, startY, leverX, leverY;
    
    for(int i = 0; i < maps.size(); i++) {
        for(int j = 0; j < maps[i].size(); j++) {
            if(maps[i][j] == 'S') {
                startX = i;
                startY = j;
            } else if(maps[i][j] == 'L') {
                leverX = i;
                leverY = j;
            }
        }
    }

    int distanceToLever = bfs(maps, startX, startY, 'L');
    if (distanceToLever == -1) return -1;
    
    int distanceToEnd = bfs(maps, leverX, leverY, 'E');
    if (distanceToEnd == -1) return -1;
    
    
    return distanceToLever + distanceToEnd;
}