#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int N;
    cin >> N;

    int dp[1001];

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= N; i++) {
        dp[i] = min(dp[i - 1] + 1, dp[i - 3] + 1);
    }

    if(dp[N] % 2 == 1) cout << "SK" << endl;
    else cout << "CY" << endl;

    return 0;
}