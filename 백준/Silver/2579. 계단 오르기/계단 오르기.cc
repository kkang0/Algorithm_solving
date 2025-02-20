#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int N;
    cin >> N;

    vector<int> v(N + 1);
    for(int i = 1; i <= N; i++) {
        cin >> v[i];
    }

    int dp[301];
    dp[0] = 0;
    dp[1] = v[1];
    dp[2] = v[1] + v[2];

    for(int i = 3; i <= N; i++) {
        dp[i] = max({dp[i - 3] + v[i - 1] + v[i], dp[i - 2] + v[i]});
    }

    cout << dp[N] << endl;

    return 0;
}