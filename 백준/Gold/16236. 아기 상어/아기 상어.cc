#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int N, curx, cury;
int board[21][21];
int visited[21][21];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int cursize = 2;
int eat_cnt = 0;

int bfs() {
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    vector<pair<int, int>> fish;

    q.push({cury, curx});
    visited[cury][curx] = 1;

    int min_dist = -1;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        int dist = visited[y][x];
        q.pop();

        if (board[y][x] > 0 && board[y][x] < cursize) {
            if (min_dist == -1 || dist <= min_dist) {
                min_dist = dist;
                fish.push_back({y, x});
            }
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
            if (visited[ny][nx] || board[ny][nx] > cursize) continue;

            visited[ny][nx] = dist + 1;
            q.push({ny, nx});
        }
    }

    if (fish.empty()) return 0;

    sort(fish.begin(), fish.end());

    int ty = fish[0].first;
    int tx = fish[0].second;

    board[ty][tx] = 0;
    eat_cnt++;
    if (eat_cnt == cursize) {
        cursize++;
        eat_cnt = 0;
    }

    cury = ty;
    curx = tx;
    return visited[ty][tx] - 1;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                cury = i;
                curx = j;
                board[i][j] = 0;
            }
        }
    }

    int result = 0;
    while (true) {
        int time = bfs();
        if (time == 0) break;
        result += time;
    }

    cout << result << endl;
    return 0;
}