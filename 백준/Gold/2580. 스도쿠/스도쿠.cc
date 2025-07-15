#include <iostream>
#include <vector>
using namespace std;

int sudoku[9][9];
vector<pair<int, int>> empty_num;
bool row[9][10];
bool col[9][10];
bool box[9][10];
bool flag = false;

int boxIndex(int x, int y) {
    return (x / 3) * 3 + (y / 3);
}

void dfs(int idx) {
    if(flag) return;

    if(idx == empty_num.size()) {
        flag = true;
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cout << sudoku[i][j] << ' ';
            }
            cout << '\n';
        }
        return;
    }

    int x = empty_num[idx].first;
    int y = empty_num[idx].second;
    int nbox = boxIndex(x, y);

    for(int num = 1; num <= 9; num++) {
        if(!row[x][num] && !col[y][num] && !box[nbox][num]) {
            sudoku[x][y] = num;
            row[x][num] = true;
            col[y][num] = true;
            box[nbox][num] = true;
            dfs(idx + 1);

            sudoku[x][y] = 0;
            row[x][num] = false;
            col[y][num] = false;
            box[nbox][num] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
            int num = sudoku[i][j];
            if(num == 0) empty_num.push_back({i, j});
            else {
                row[i][num]= true;
                col[j][num] = true;
                box[boxIndex(i, j)][num] = true;
            }
        }
    }

    dfs(0);

    return 0;
}