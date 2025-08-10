#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;

        vector<vector<int>> sticker(2, vector<int>(n));
        vector<vector<int>> dp(n, vector<int>(3));
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < n; j++)
                cin >> sticker[i][j];
        }

        dp[0][0] = 0;
        dp[0][1] = sticker[0][0];
        dp[0][2] = sticker[1][0];

        for(int i = 1; i < n; i++) {
            dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + sticker[0][i];
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + sticker[1][i];
        }

        cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << '\n';
    }

    return 0;
}