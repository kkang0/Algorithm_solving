#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[1001][1001];
int dp[1001][1001];
int tmp[1001][2];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    
    dp[0][0] = arr[0][0];

    for(int i = 1; i < M; i++) {
        dp[0][i] = dp[0][i - 1] + arr[0][i];
    }

    for(int i = 1; i < N; i++) {
        tmp[0][0] = dp[i - 1][0] + arr[i][0];
        for(int j = 1; j < M; j++) {
            tmp[j][0] = max(dp[i - 1][j], tmp[j - 1][0]) + arr[i][j];
        }
        
        tmp[M - 1][1] = dp[i - 1][M - 1] + arr[i][M - 1];
        for(int j = M - 2; j >= 0; j--) {
            tmp[j][1] = max(dp[i - 1][j], tmp[j + 1][1]) + arr[i][j];
        }
        for(int j = 0; j < M; j++) {
            dp[i][j] = max(tmp[j][0], tmp[j][1]);
        }
    }

    cout << dp[N - 1][M - 1] << "\n";

    return 0;
}