#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;
    vector<long long> trees(N);
    for(int i = 0; i < N; i++) {
        cin >> trees[i];
    }

    sort(trees.begin(), trees.end());

    long long start = 0;
    long long end = trees[N - 1];
    long long result = 0;
    while(start <= end) {
        long long sum = 0;
        long long mid = (start + end) / 2;

        for(int i = 0; i < N; i++) {
            int height = trees[i];
            
            if(height - mid > 0) {
                sum += trees[i] - mid;
            }
        }

        if(sum < M) {
            end = mid - 1;
        } else {
            result = mid;
            start = mid + 1;
        }
    }

    cout << result << '\n';

    return 0;
}