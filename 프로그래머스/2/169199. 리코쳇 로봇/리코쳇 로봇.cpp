#include <string>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int visited[101][101];

int solution(vector<string> board) {
    queue<pair<int, int>> q;
    memset(visited, -1, sizeof(visited));
    
    int n = board.size();
    int m = board[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'R') {
                q.push({i, j});
                visited[i][j] = 0;
                break;
            }
        }
    }

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = p.first;
            int ny = p.second;
            
            while (true) {
                nx += dx[i];
                ny += dy[i];
                
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || board[nx][ny] == 'D') {
                    nx -= dx[i];
                    ny -= dy[i];
                    break;
                }
            }
            
            if (board[nx][ny] == 'G') {
                return visited[p.first][p.second] + 1;
            }

            if (visited[nx][ny] == -1 || visited[nx][ny] > visited[p.first][p.second] + 1) {
                visited[nx][ny] = visited[p.first][p.second] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    return -1;
}