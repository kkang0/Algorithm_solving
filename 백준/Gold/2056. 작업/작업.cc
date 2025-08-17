#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[10001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> work(N + 1);
    vector<vector<int>> graph(N + 1);
    for(int i = 1; i <= N; i++) {
        int num;
        cin >> work[i] >> num;
        for(int k = 0; k < num; k++) {
            int n;
            cin >> n;
            graph[i].push_back(n);
        }
    }

    int result = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < graph[i].size(); j++) {
            dp[i] = max(dp[i], dp[graph[i][j]]);
        }
        dp[i] += work[i];
        result = max(result, dp[i]);
    }

    cout << result << '\n';

    return 0;
}