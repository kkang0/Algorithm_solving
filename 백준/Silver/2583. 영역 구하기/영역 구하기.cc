#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int M, N, K;
vector<vector<int>> v;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(int x, int y) {
    int count = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    v[x][y] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            if (v[nx][ny] == 0) {
                v[nx][ny] = 1;
                q.push(make_pair(nx, ny));
                count++;
            }
        }
    }
    return count;
}

int main(void) {
    cin >> M >> N >> K;
    v.resize(M, vector<int>(N, 0));
    vector<int> area;

    for (int i = 0; i < K; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = y1; j < y2; j++) {
            for (int k = x1; k < x2; k++) {
                v[j][k] = 1;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (v[i][j] == 0) {
                area.push_back(bfs(i, j));
            }
        }
    }

    sort(area.begin(), area.end());

    cout << area.size() << endl;
    for(int i = 0; i < area.size(); i++)
        cout << area[i] << " ";
    cout << endl;
    
    return 0;
}