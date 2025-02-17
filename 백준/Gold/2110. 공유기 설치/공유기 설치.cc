#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n, c;
    cin >> n >> c;

    vector<int> pos(n);
    for(int i = 0; i < n; i++) {
        cin >> pos[i];
    }
    sort(pos.begin(), pos.end());

    int start = 1;
    int end = pos[n - 1] - pos[0];

    int result = 0;
    int point = 0;
    int router;
    while(start <= end) {
        router = 1;
        int mid = (start + end) / 2;
        point = pos[0];

        for(int i = 1; i < n; i++) {
            if(pos[i] - point >= mid) {
                router++;
                point = pos[i];
            }
        }

        if(router >= c) {
            result = max(result, mid);
            start = mid + 1;
        } else end = mid - 1;
    }

    cout << result << endl;

    return 0;
}