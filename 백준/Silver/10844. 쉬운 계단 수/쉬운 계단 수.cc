#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<long long>> dp(N + 1, vector<long long>(10, 0));

    for (int j = 1; j <= 9; j++) dp[1][j] = 1;

    for (int i = 2; i <= N; i++) {
        dp[i][0] = dp[i - 1][1];
        dp[i][9] = dp[i - 1][8];
        for (int j = 1; j <= 8; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
        }
    }

    long long result = 0;
    for (int j = 0; j <= 9; j++) {
        result = (result + dp[N][j]) % MOD;
    }

    cout << result << '\n';
    return 0;
}