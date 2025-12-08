#include <iostream>
#include <algorithm>
using namespace std;

int N;
int L[101];
int J[101];
int dp[21][101];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> L[i];
    }

    for(int i = 1; i <= N; i++) {
        cin >> J[i];
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j < 100; j++) {
            if(L[i] <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - L[i]] + J[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[N][99] << endl;

    return 0;
}