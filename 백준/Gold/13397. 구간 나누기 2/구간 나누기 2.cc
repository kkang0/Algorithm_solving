#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> arr;

bool check(int mid) {
    int cnt = 1;
    int min_val = arr[0];
    int max_val = arr[0];

    for(int i = 1; i < N; i++) {
        min_val = min(min_val, arr[i]);
        max_val = max(max_val, arr[i]);

        if(max_val - min_val > mid) {
            cnt++;
            min_val = arr[i];
            max_val = arr[i];
        }
    }

    return cnt <= M;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    arr.resize(N);
    int max_num = 0;
    int min_num = 10001;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        max_num = max(max_num, arr[i]);
        min_num = min(min_num, arr[i]);
    }

    int start = 0;
    int end = max_num - min_num;
    int result = end;
    while(start <= end) {
        int mid = (start + end) / 2;
        if(check(mid)) {
            result = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    cout << result << '\n';

    return 0;
}