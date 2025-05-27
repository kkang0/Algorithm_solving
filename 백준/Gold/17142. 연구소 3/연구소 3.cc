#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int lab[51][51];
vector<pair<int, int>> pos;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(vector<pair<int, int>> active) {
    vector<vector<int>> visited(N, vector<int>(N, -1));
    queue<pair<int, int>> q;

    for (auto &a : active) {
        q.push(a);
        visited[a.first][a.second] = 0;
    }

    int maxTime = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (lab[nx][ny] == 1 || visited[nx][ny] != -1) continue;

            visited[nx][ny] = visited[x][y] + 1;
            q.push({nx, ny});
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (lab[i][j] == 0) {
                if (visited[i][j] == -1) return -1;
                maxTime = max(maxTime, visited[i][j]);
            }
        }
    }

    return maxTime;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> lab[i][j];
            if (lab[i][j] == 2) {
                pos.push_back({i, j});
            }
        }
    }

    vector<int> select(pos.size(), 0);
    for (int i = 0; i < M; i++) select[i] = 1;

    sort(select.begin(), select.end());

    int result = 1e9;

    do {
        vector<pair<int, int>> active;
        for (int i = 0; i < pos.size(); i++) {
            if (select[i]) {
                active.push_back(pos[i]);
            }
        }

        int time = bfs(active);
        if (time != -1) {
            result = min(result, time);
        }

    } while (next_permutation(select.begin(), select.end()));

    cout << (result == 1e9 ? -1 : result) << '\n';

    return 0;
}