#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C, N;
    cin >> C >> N;
    vector<pair<int, int>> nums(N);
    for(int i = 0; i < N; i++) {
        cin >> nums[i].first >> nums[i].second;
    }

    vector<int> dp(C + 101, INF);
    dp[0] = 0;
    for(int i = 0; i < N; i++) {
        auto [cost, num] = nums[i];
        for(int j = num; j <= C + 100; j++) {
            dp[j] = min(dp[j], dp[j - num] + cost);
        }
    }

    int result = INF;
    for(int i = C; i <= C + 100; i++) result = min(result, dp[i]);

    cout << result << '\n';

    return 0;
}