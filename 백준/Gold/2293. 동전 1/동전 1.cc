#include <iostream>
using namespace std;

int n, k;
int coin[101];
int dp[10001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    dp[0] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = coin[i]; j <= k; j++) {
            dp[j] += dp[j - coin[i]];
        }
    }

    cout << dp[k] << '\n';

    return 0;
}