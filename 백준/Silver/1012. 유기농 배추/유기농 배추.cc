#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int T, M, N, K;
int graph[51][51];
bool visited[51][51];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y) {
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if(graph[nx][ny] == 1 && !visited[nx][ny]) {
            visited[nx][ny] = true;
            dfs(nx, ny);
        }
    }
}

int main(void) {
    cin >> T;
    while(T--) {
        cin >> M >> N >> K;

        // 초기화
        memset(graph, 0, sizeof(graph));
        memset(visited, false, sizeof(visited));
        
        int result = 0;
        for(int j = 0; j < K; j++) {
            int x, y;
            cin >> x >> y;
            graph[y][x] = 1;
        }

        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                if(graph[j][k] == 1 && !visited[j][k]) {
                    visited[j][k] = true;
                    result++;
                    dfs(j, k);
                }
            }
        }

        cout << result << endl;
    }

    return 0;
}
