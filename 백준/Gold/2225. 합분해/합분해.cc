#include <iostream>
#include <vector>
using namespace std;

int MAX = 1000000000;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    
    vector<vector<long long>> dp(N + 1, vector<long long>(K + 1, 0));

    for(int i = 1; i <= K; i++) {
        dp[0][i] = 1;
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= K; j++) {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MAX;
        }
    }

    cout << dp[N][K] << '\n';

    return 0;
}