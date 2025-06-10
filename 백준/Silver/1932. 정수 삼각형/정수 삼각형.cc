#include <iostream>
#include <algorithm>
using namespace std;

int dp[501][501];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> dp[i][j];
        }
    }

    int result = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0) dp[i][j] = dp[i - 1][j] + dp[i][j];
            else if(i == j) dp[i][j] = dp[i - 1][j - 1] + dp[i][j];
            else dp[i][j] = max(dp[i - 1][j - 1] + dp[i][j], dp[i - 1][j] + dp[i][j]);

            result = max(result, dp[i][j]);
        }
    }

    cout << result << '\n';

    return 0;
}