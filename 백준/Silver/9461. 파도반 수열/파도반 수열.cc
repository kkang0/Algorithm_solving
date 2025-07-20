#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long dp[101];

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;

    for(int i = 5; i <= 100; i++) {
        dp[i] = dp[i - 5] + dp[i - 4] + dp[i - 3];
    }

    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;

        cout << dp[N] << '\n';
    }

    return 0;
}