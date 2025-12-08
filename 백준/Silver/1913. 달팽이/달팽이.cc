#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<vector<int>> table;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    cin >> K;
    table.resize(N, vector<int>(N));

    int x = N / 2;
    int y = N / 2;
    int num = 1;

    int dir = 0;
    int len = 1;

    int nx = 0;
    int ny = 0;
    
    table[x][y] = 1;
    if(K == 1) {
        nx = x;
        ny = y;
    }

    int cur = 2;
    int step = 1;

    while(cur <= N * N) {
        for(int t = 0; t < 2; t++) {
            for(int i = 0; i < step; i++) {
                x += dx[dir];
                y += dy[dir];

                if(x < 0 || x >= N || y < 0 || y >= N) break;

                table[x][y] = cur;

                if(cur == K) {
                    nx = x;
                    ny = y;
                }
                cur++;
            }
            dir = (dir + 1) % 4;
        }
        step++;
    }


    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << table[i][j] << " ";
        }
        cout << '\n';
    }

    cout << nx + 1 << " " << ny + 1 << '\n';

    return 0;
}