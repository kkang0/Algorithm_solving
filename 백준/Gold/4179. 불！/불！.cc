#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int R, C;
string maze[1001];
int fire[1001][1001];
int jihun[1001][1001];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;

    for(int i = 0; i < R; i++) {
        cin >> maze[i];
    }

    for(int i = 0; i < R; i++) {
        fill(fire[i], fire[i] + C, -1);
        fill(jihun[i], jihun[i] + C, -1);
    }

    queue<pair<int, int>> fq;
    queue<pair<int, int>> jq;

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(maze[i][j] == 'F') {
                fq.push({i, j});
                fire[i][j] = 0;
            }

            if(maze[i][j] == 'J') {
                jq.push({i, j});
                jihun[i][j] = 0;
            }
        }
    }

    while(!fq.empty()) {
        pair<int, int> cur = fq.front();
        fq.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if(fire[nx][ny] >= 0 || maze[nx][ny] == '#') continue;
            fire[nx][ny] = fire[cur.first][cur.second] + 1;
            fq.push({nx, ny});
        }
    }

    while(!jq.empty()) {
        pair<int, int> cur = jq.front();
        jq.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || ny < 0 || nx >= R || ny >= C) {
                cout << jihun[cur.first][cur.second] + 1 << endl;
                return 0;
            }
            if(jihun[nx][ny] >= 0 || maze[nx][ny] == '#') continue;
            if(fire[nx][ny] != -1 && fire[nx][ny] <= jihun[cur.first][cur.second] + 1) continue;
            jihun[nx][ny] = jihun[cur.first][cur.second] + 1;
            jq.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}