#include <iostream>
#include <algorithm>
using namespace std;

int N;
int color[1001][1001];
int dp[1001][1001];

int main(void) {
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> color[i][j];
        }
    }

    dp[0][0] = color[0][0];
    dp[0][1] = color[0][1];
    dp[0][2] = color[0][2];

    int sum = 0;
    for(int i = 1; i < N; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + color[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + color[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + color[i][2];
    }

    cout << min({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]}) << endl;

    return 0;
}