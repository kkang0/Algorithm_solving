#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
vector<vector<int>> cheese;
bool visited[100][100];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int hours, result;

bool bfs() {
    visited[0][0] = true;
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(!visited[nx][ny]) {
                if(cheese[nx][ny] == 0) q.push({nx, ny});
                else {
                    cheese[nx][ny] = 0;
                    cnt++;
                }
                visited[nx][ny] = true;
            }
        }
    }

    if(cnt == 0) {
        cout << hours << '\n' << result << '\n';
        return true;
    } else {
        result = cnt;
        hours++;
        return false;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    cheese.assign(N, vector<int>(M));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> cheese[i][j];
        }
    }

    while(true) {
        if(bfs()) break;
        memset(visited, 0, sizeof(visited));
    }

    return 0;
}