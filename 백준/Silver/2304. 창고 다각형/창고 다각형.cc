#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int max_h = 0;
    int max_pos = 0;

    for(int i = 0; i < N; i++) {
        int L, H;
        cin >> L >> H;

        arr[L] = H;

        if(max_h < H) {
            max_h = H;
            max_pos = L;
        }
    }

    int result = 0;
    int lh = 0;
    for(int i = 1; i < max_pos; i++) {
        lh = max(lh, arr[i]);
        result += lh;
    }

    int rh = 0;
    for(int i = 1000; i > max_pos; i--) {
        rh = max(rh, arr[i]);
        result += rh;
    }

    result += max_h;

    cout << result << '\n';

    return 0;
}