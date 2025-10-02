#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<char>> board;

void tree(int y, int x, int n) {
    if(n == 3) {
        board[y][x] = '*';
        board[y + 1][x - 1] = '*';
        board[y + 1][x + 1] = '*';
        for(int i = -2; i <= 2; i++)
            board[y + 2][x - i] = '*';
        return;
    }

    tree(y, x, n / 2);
    tree(y + n / 2, x - n / 2, n / 2);
    tree(y + n / 2, x + n / 2, n / 2);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    board.assign(N, vector<char>(2 * N, ' '));

    tree(0, N - 1, N);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 2 * N - 1; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}