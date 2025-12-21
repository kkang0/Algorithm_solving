#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, N;
    cin >> V >> N;
    vector<int> coins(V);

    for(int i = 0; i < V; i++) cin >> coins[i];

    vector<long long> dp(N + 1);
    dp[0] = 1;
    for(int i = 0; i < V; i++) {
        int c = coins[i];
        for(int j = c; j < N + 1; j++) {
            dp[j] += dp[j - c];
        }
    }

    cout << dp[N] << '\n';

    return 0;
}