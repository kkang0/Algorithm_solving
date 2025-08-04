#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, cnt;
int board[15];

bool check(int row, int col) {
    for(int i = 0; i < row; i++) {
        if(board[i] == col || abs(board[i] - col) == row - i) return false;
    }
    return true;
}

void nqueen(int row) {
    if(row == N) {
        cnt++;
        return;
    }

    for(int i = 0; i < N; i++) {
        if(check(row, i)) {
            board[row] = i;
            nqueen(row + 1);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    nqueen(0);
    cout << cnt << '\n';

    return 0;
}