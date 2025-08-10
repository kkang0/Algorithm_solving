#include <iostream>
#include <vector>
using namespace std;

int N;
vector<string> arr;
vector<vector<bool>> visited;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, char color, bool weak) {
    visited[x][y] = true;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if(visited[nx][ny]) continue;
        if(weak) {
            if((color == 'R' || color == 'G') && (arr[nx][ny] == 'R' || arr[nx][ny] == 'G')) {
                dfs(nx, ny, color, weak);
            } else if(arr[nx][ny] == color) {
                dfs(nx, ny, color, weak);
            }
        } else {
            if(arr[nx][ny] == color) dfs(nx, ny, color, weak);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    arr.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    visited.assign(N, vector<bool>(N, false));
    int acnt = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!visited[i][j]) {
                dfs(i, j, arr[i][j], false);
                acnt++;
            }
        }
    }

    visited.assign(N, vector<bool>(N, false));
    int bcnt = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!visited[i][j]) {
                dfs(i, j, arr[i][j], true);
                bcnt++;
            }
        }
    }

    cout << acnt << ' ' << bcnt << '\n';

    return 0;
}