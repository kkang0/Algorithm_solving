#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> study;
vector<vector<int>> dp;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, T;
    cin >> N >> T;
    study.resize(N + 1);
    dp.resize(N + 1, vector<int>(T + 1));
    for(int i = 1; i <= N; i++) {
        int K, S;
        cin >> K >> S;
        study[i] = {K, S};
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= T; j++) {
            int time = study[i].first;
            int score = study[i].second;

            if(time > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - time] + score);
            }
        }
    }

    cout << dp[N][T] << '\n';

    return 0;
}