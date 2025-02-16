#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int N, k;
    cin >> N;
    cin >> k;

    int start = 1;
    int end = k;
    while(start < end) {
        int mid = (start + end) / 2;
        int cnt = 0;

        for(int i = 1; i <= N; i++) {
            cnt += min(N, mid / i);
        }

        if(cnt < k) start = mid + 1;
        else end = mid;
    }

    cout << end << endl;

    return 0;
}