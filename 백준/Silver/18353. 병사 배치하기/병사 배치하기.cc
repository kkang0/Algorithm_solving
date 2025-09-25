#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> soldier(N + 1);
    for(int i = 1; i <= N; i++) cin >> soldier[i];

    reverse(soldier.begin() + 1, soldier.end());

    vector<int> dp(N + 1, 1);
    for(int i = 2; i <= N; i++) {
        for(int j = 1; j < i; j++) {
            if(soldier[j] < soldier[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int lis = *max_element(dp.begin(), dp.end());

    cout << N - lis << '\n';

    return 0;
}