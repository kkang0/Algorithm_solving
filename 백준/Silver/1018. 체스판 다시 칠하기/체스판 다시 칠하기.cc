#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int N, M;
char board[51][51];

int getCnt(int x, int y) {
    string chess[2] = {"WBWBWBWB", "BWBWBWBW"};

    int white = 0;

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(board[x + i][y + j] != chess[i % 2][j]) white++;
        }
    }

    return min(white, 64 - white);
}

int main(void) {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> board[i];
    }

    int cnt = INT_MAX;
    for(int i = 0; i <= N - 8; i++) {
        for(int j = 0; j <= M - 8; j++) {
            cnt = min(cnt, getCnt(i, j));
        }
    }

    cout << cnt << endl;
    return 0;
}