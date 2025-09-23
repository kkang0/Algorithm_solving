#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> temp(N);
    for(int i = 0; i < N; i++) {
        cin >> temp[i];
    }

    int sum = 0;
    for(int i = 0; i < K; i++) sum += temp[i];
    int max_sum = sum;

    for(int i = K; i < N; i++) {
        sum -= temp[i - K];
        sum += temp[i];
        max_sum = max(sum , max_sum);
    }

    cout << max_sum << '\n';

    return 0;
}