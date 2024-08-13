#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C, total_sheep, total_wolf;
vector<vector<char>> ground;
vector<vector<bool>> visited;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int x, int y) {
    int sheep = 0;
    int wolf = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = true;

    if(ground[x][y] == 'v') wolf++;
    if(ground[x][y] == 'o') sheep++;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if(visited[nx][ny] || ground[nx][ny] == '#') continue;

            visited[nx][ny] = true;
            q.push(make_pair(nx, ny));

            if(ground[nx][ny] == 'v') wolf++;
            if(ground[nx][ny] == 'o') sheep++;
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
        string s;
        cin >> s;
        for(int j = 0; j < C; j++) {
            ground[i][j] = s[j];
        }
    }

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(ground[i][j] != '#' && !visited[i][j]) bfs(i, j);
        }
    }

    cout << total_sheep << " " << total_wolf << endl;

    return 0;
}