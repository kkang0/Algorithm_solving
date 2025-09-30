#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> dvd(N);
    int dvd_sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> dvd[i];
        dvd_sum += dvd[i];
    }

    int start = *max_element(dvd.begin(), dvd.end());
    int end = dvd_sum;
    while(start <= end) {
        int mid = (start + end) / 2;

        int sum = 0;
        int m = 0;
        for(int i = 0; i < N; i++) {
            sum += dvd[i];

            if(sum > mid) {
                m++;
                sum = dvd[i];
            }
        }

        if(m + 1 > M) start = mid + 1;
        else end = mid - 1;
    }

    cout << start << '\n';

    return 0;
}