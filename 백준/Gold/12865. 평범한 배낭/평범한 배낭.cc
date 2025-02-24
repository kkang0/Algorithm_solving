#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[100001];

int main(void) {
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> bag(N);
    for(int i = 0; i < N; i++) {
        cin >> bag[i].first >> bag[i].second;
    }

    int result = 0;
    for(int i = 0; i < N; i++) {
        int w = bag[i].first;
        int v = bag[i].second;

        for(int j = K; j >= w; j--) {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }

    cout << dp[K] << endl;

    return 0;
}