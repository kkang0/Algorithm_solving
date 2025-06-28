#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

string arr[5];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool bfs(vector<int>& pos) {
    vector<vector<bool>> isSelected(5, vector<bool>(5, false));
    for (int p : pos) {
        int x = p / 5;
        int y = p % 5;
        isSelected[x][y] = true;
    }

    queue<pair<int, int>> q;
    vector<vector<bool>> visited(5, vector<bool>(5, false));

    int sx = pos[0] / 5, sy = pos[0] % 5;
    q.push({sx, sy});
    visited[sx][sy] = true;

    int cnt = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
            if (visited[nx][ny]) continue;
            if (isSelected[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                cnt++;
            }
        }
    }

    return cnt == 7;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    vector<int> selected(25, 0);
    fill(selected.begin(), selected.begin() + 7, 1);

    int result= 0;
    do {
        vector<int> pos;
        int scnt = 0;
        for (int i = 0; i < 25; i++) {
            if (selected[i]) {
                pos.push_back(i);
                int x = i / 5;
                int y = i % 5;
                if (arr[x][y] == 'S') scnt++;
            }
        }

        if (scnt >= 4 && bfs(pos)) result++;

    } while (prev_permutation(selected.begin(), selected.end()));

    cout << result << '\n';

    return 0;
}