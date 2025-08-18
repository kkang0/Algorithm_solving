#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> nums(N + 1);
    vector<long long> dp(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        cin >> nums[i];
        dp[i] += dp[i - 1] + nums[i];
    }

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        
        cout << dp[b] - dp[a - 1] << '\n';
    }

    return 0;
}