#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> arr(N);
    for(int i = 0 ; i < N; i++) {
        cin >> arr[i];
    }

    vector<int> dp(N, 1);
    vector<int> rdp(N, 1);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    for(int i = N - 1; i >= 0; i--) {
        for(int j = N - 1; j >= i; j--) {
            if(arr[j] < arr[i]) {
                rdp[i] = max(rdp[i], rdp[j] + 1);
            }
        }
    }

    int result = 0;
    for(int i = 0; i < N; i++) {
        result = max(result, dp[i] + rdp[i] - 1);
    }

    cout << result << '\n';

    return 0;
}