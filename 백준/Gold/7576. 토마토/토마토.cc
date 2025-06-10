#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int M, N;
vector<vector<int>> tomato;
vector<vector<int>> day;
queue<pair<int, int>> q;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs() {
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(tomato[nx][ny] == 0 && day[nx][ny] == -1) {
                day[nx][ny] = day[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N;
    tomato.resize(N, vector<int>(M));
    day.resize(N, vector<int>(M));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> tomato[i][j];
            day[i][j] = -1;

            if(tomato[i][j] == 1) {
                q.push({i, j});
                day[i][j] = 0;
            }
        }
    }

    bfs();

    int result = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            result = max(result, day[i][j]);
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(tomato[i][j] == 0 && day[i][j] == -1)
                result = -1;
        }
    }

    cout << result << '\n';

    return 0;
}