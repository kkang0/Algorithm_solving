#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<string> board;
vector<pair<int, int>> group;
bool visited[12][6];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int cnt;

void dfs(int x, int y, int color) {
    visited[x][y] = true;
    group.push_back({x, y});

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
        if(board[nx][ny] == '.') continue;
        if(visited[nx][ny]) continue;
        if(color != board[nx][ny]) continue;

        dfs(nx, ny, color);
    }
}

void bomb() {
    for(int i = 0; i < 6; i++) {
        int emptyRow = 11;
        for(int j = 11; j >= 0; j--) {
            if(board[j][i] != '.') {
                char tmp = board[j][i];
                board[j][i] = '.';
                board[emptyRow][i] = tmp;
                emptyRow--;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    board.resize(12);
    for(int i = 0; i < 12; i++) {
        cin >> board[i];
    }

    int result = 0;

    while(true) {
        bool flag = false;
        memset(visited, 0, sizeof(visited));

        for(int i = 0; i < 12; i++) {
            for(int j = 0; j < 6; j++) {
                if(board[i][j] != '.' && !visited[i][j]) {
                    group.clear();
                    dfs(i, j, board[i][j]);
                    
                    if(group.size() >= 4) {
                        flag = true;
                        for(auto& g: group) {
                            board[g.first][g.second] = '.';
                        }
                    }
                }
            }
        }

        if(!flag) break;
        bomb();
        result++;
    }

    cout << result << '\n';

    return 0;
}