#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<long long>> arr(N, vector<long long>(N));
    vector<vector<long long>> dp(N, vector<long long>(N, 0));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    dp[0][0] = 1;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(dp[i][j] == 0 || (i == N - 1 && j == N - 1)) continue;

            int jump = arr[i][j];
            if(i + jump < N) dp[i + jump][j] += dp[i][j];
            if(j + jump < N) dp[i][j + jump] += dp[i][j];
        }
    }

    cout << dp[N - 1][N - 1] << '\n';
    return 0;
}