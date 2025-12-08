#include <iostream>
using namespace std;

int dp[1000001];
int prevv[1000001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    dp[1] = 0;

    for(int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + 1;
        prevv[i] = i - 1;

        if(i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
            dp[i] = dp[i / 2] + 1;
            prevv[i] = i / 2;
        }

        if(i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
            dp[i] = dp[i / 3] + 1;
            prevv[i] = i /3;
        }
    }

    cout << dp[N] << '\n';

    int cur = N;
    while(cur) {
        cout << cur << " ";
        if(cur == 1) break;
        cur = prevv[cur];
    }
    cout << '\n';

    return 0;
}