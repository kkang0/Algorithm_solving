#include <iostream>
#include <algorithm>
using namespace std;

int dp[21][201];
int day[21];
int page[21];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for(int i = 1; i <= M; i++) {
        cin >> day[i] >> page[i];
    }

    int result = 0;
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            if(j - day[i] >= 0) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - day[i]] + page[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
            result = max(result, dp[i][j]);
        }
    }

    cout << result << '\n';
    
    return 0;
}