#include <iostream>
#include <cstring>
using namespace std;

int N, max_num;
int v[101][101];
bool visited[101][101] = {false};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, int n) {
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if(visited[nx][ny] || v[nx][ny] <= n) continue;
        visited[nx][ny] = true;
        dfs(nx, ny, n);
    }
}


int main(void) {
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> v[i][j];

            if(v[i][j] > max_num) max_num = v[i][j];
        }
    }

    int result = 1;
    for(int n = 0; n < max_num; n++) {
        int num = 0;
        memset(visited, 0, sizeof(visited));

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(!visited[i][j] && v[i][j] > n) {
                    visited[i][j] = true;
                    dfs(i, j, n);
                    num++;
                }
            }
        }

        result = max(result, num);
    }

    cout << result << endl;

    return 0;
}