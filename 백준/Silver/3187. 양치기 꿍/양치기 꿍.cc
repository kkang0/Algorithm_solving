#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C, total_sheep, total_wolf;
vector<vector<char>> ground;
vector<vector<bool>> visited;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0}; 

void bfs(int x, int y) {
    int sheep = 0;
    int wolf = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = true;

    if(ground[x][y] == 'k') sheep++;
    if(ground[x][y] == 'v') wolf++;

    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if(visited[nx][ny] || ground[nx][ny] == '#') continue;
            
            visited[nx][ny] = true;
            q.push(make_pair(nx, ny));

            if(ground[nx][ny] == 'k') sheep++;
            if(ground[nx][ny] == 'v') wolf++;
        }
    }

    if(sheep > wolf) total_sheep += sheep;
    else total_wolf += wolf;
}

int main(void) {
    cin >> R >> C;
    
    ground.resize(R, vector<char>(C));
    visited.resize(R, vector<bool>(C, false));

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> ground[i][j];
        }
    }

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(!visited[i][j] && ground[i][j] != '#') {
                bfs(i, j);
            }
        }
    }

    cout << total_sheep << " " << total_wolf << endl;

    return 0;
}
