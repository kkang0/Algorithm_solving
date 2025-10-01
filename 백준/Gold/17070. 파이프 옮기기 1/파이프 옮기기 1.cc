#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> pipe;
int dp[17][17][3];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    pipe.resize(N + 1, vector<int>(N + 1, 0));

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> pipe[i][j];
        }
    }

    dp[1][2][0] = 1;

    for(int i = 1; i <= N; i++) {
        for(int j = 2; j <= N; j++) {
            if(pipe[i][j]) continue;

            dp[i][j][0] += dp[i][j-1][0] + dp[i][j-1][2];
            dp[i][j][1] += dp[i-1][j][1] + dp[i-1][j][2];
            if(!pipe[i-1][j] && !pipe[i][j-1])
                dp[i][j][2] += dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
        }
    }

    cout << dp[N][N][0] + dp[N][N][1] + dp[N][N][2] << '\n';
    return 0;
}