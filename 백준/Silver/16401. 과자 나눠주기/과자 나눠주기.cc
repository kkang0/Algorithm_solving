#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;
    vector<int> snack(N);
    for(int i = 0; i < N; i++) {
        cin >> snack[i];
    }

    sort(snack.begin(), snack.end());
    int start = 1;
    int end = snack[N - 1];
    int result = 0;
    while(start <= end) {
        int mid = (start + end) / 2;

        int sum = 0;
        for(int i = 0; i < N; i++) {
            sum += snack[i] / mid;
        }

        if(sum >= M) {
            result = mid;
            start = mid + 1;
        } else end = mid - 1;
    }

    cout << result << '\n';

    return 0;
}