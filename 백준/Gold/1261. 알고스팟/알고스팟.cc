#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int N, M;
vector<string> maze;
vector<vector<int>> dist;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int x, int y) {
    deque<pair<int, int>> dq;
    dq.push_back({x, y});
    dist[x][y] = 0;

    while(!dq.empty()) {
        int cx = dq.front().first;
        int cy = dq.front().second;
        dq.pop_front();

        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            
            int cost = dist[cx][cy];
            if(maze[cx][cy] == '1') cost += 1;
            
            if(dist[nx][ny] > cost) {
                dist[nx][ny] = cost;
                if(maze[nx][ny] == '1') dq.push_back({nx, ny});
                else dq.push_front({nx, ny});
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N;
    maze.resize(N);
    dist.resize(N, vector<int>(M, 1e9));
    for(int i = 0; i < N; i++) {
        cin >> maze[i];
    }

    bfs(0, 0);
    cout << dist[N - 1][M - 1] << '\n';

    return 0;
}