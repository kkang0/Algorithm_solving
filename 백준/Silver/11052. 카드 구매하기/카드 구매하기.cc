#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> cards(N + 1);
    for(int i = 1; i <= N; i++) {
        cin >> cards[i];
    }
    
    vector<int> dp(N + 1, 0);
    dp[1] = cards[1];

    for(int i = 2; i <= N; i++) {
        for(int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], dp[i - j] + cards[j]);
        }
    }

    cout << dp[N] << '\n';
}