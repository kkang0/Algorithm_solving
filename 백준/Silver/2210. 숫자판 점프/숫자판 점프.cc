#include <iostream>
#include <vector>
#include <set>
using namespace std;

int matrix[5][5];
set<int> result;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, int len, string s) {
    s += to_string(matrix[x][y]);
    len++;

    if(len == 6) {
        result.insert(stoi(s));
        return;
    }

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
        dfs(nx, ny, len, s);
    }
}

int main(void) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> matrix[i][j];
        }
    }

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            dfs(i, j, 0, "");
        }
    }

    cout << result.size() << endl;

    return 0;
}