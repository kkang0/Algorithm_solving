#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool visited[103][103];
vector<int> answer;

void bfs(int x, int y, int size, vector<string>& maps) {
    int result = 0;
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    result += maps[x][y] - '0';

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || ny < 0 || nx >= size || ny >= maps[nx].size()) continue;
            if (maps[nx][ny] == 'X') continue;
            if (!visited[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
                result += maps[nx][ny] - '0';
            }
        }
    }

    answer.push_back(result);
}

vector<int> solution(vector<string> maps) {
    int size = maps.size();
    
    for (int i = 0; i < size; i++) {
        fill(visited[i], visited[i] + maps[i].size(), false);
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < maps[i].size(); j++) {
            if (!visited[i][j] && maps[i][j] != 'X') {
                bfs(i, j, size, maps);
            }
        }
    }

    if (answer.empty()) return {-1};
    
    sort(answer.begin(), answer.end());
    return answer;
}