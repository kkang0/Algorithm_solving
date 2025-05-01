#include <iostream>
#include <vector>
using namespace std;

vector<vector<long long>> dp;

long long combination(int n, int r) {
    if(r == 0 || n == r) return 1;
    if(r > n / 2) r = n - r;
    if(dp[n][r] != -1) return dp[n][r];

    dp[n][r] = (combination(n - 1, r - 1) + combination(n - 1, r)) % 10007;
    return dp[n][r];
}

int main(void) {
    int N;
    cin >> N;

    dp.assign(N + 10, vector<long long>(N + 10, -1));

    cout << combination(N + 9, 9) << "\n";

    return 0;
}