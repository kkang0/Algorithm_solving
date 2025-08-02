#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K, N;
    cin >> K >> N;

    vector<int> lan;
    lan.resize(K);
    int max_lan = 0;
    for(int i = 0; i < K; i++) {
        cin >> lan[i];
        max_lan = max(max_lan, lan[i]);
    }

    long long start = 1;
    long long end = max_lan;
    long long result = 0;
    while(start <= end) {
        long long mid = (start + end) / 2;

        long long sum = 0;
        for(int i = 0; i < K; i++) {
            sum += (lan[i] / mid);
        }

        if(sum >= N) {
            result = mid;
            start = mid + 1;
        }
        else end = mid - 1;
    }

    cout << result << '\n';

    return 0;
}