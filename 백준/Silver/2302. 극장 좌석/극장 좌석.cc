#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N;
    cin >> M;
    vector<int> vip(M);
    for(int i = 0; i < M; i++) {
        cin >> vip[i];
    }

    int dp[41];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= 40; i++) dp[i] = dp[i - 1] + dp[i - 2];

    int result = 1;
    int prev = 0;
    for(int i = 0; i < M; i++) {
        int gap = vip[i] - prev - 1;
        result *= dp[gap];
        prev = vip[i];
    }

    result *= dp[N - prev];

    cout << result << '\n';

    return 0;
}