#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int N, K, M;
    cin >> N >> K >> M;

    vector<int> kimbap;
    for(int i = 0; i < N; i++) {
        int len;
        cin >> len;

        if(len <= K) continue;
        else if(len < 2 * K) kimbap.push_back(len - K);
        else kimbap.push_back(len - 2 * K);
    }

    if (kimbap.empty()) {
        cout << -1 << '\n';
        return 0;
    }


    int left = 1;
    int right = *max_element(kimbap.begin(), kimbap.end());
    while(left <= right) {
        int mid = (left + right) / 2;
        int cnt = 0;
        
        for(int i = 0; i < kimbap.size(); i++) {
            cnt += kimbap[i] / mid;
        }

        if(cnt >= M) left = mid + 1;
        else right = mid - 1;
    }

    if (right == 0) cout << -1 << '\n';
    else cout << right << '\n';

    return 0;
}