#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> boxes;
    boxes.resize(n);
    for(int i = 0; i < n; i++) cin >> boxes[i];

    for(int i = 0; i < n; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(boxes[i] > boxes[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << *max_element(dp, dp + 1001) << '\n';

    return 0;
}