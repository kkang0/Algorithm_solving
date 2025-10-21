#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> arr;
    arr.resize(1001, 0);

    int max_height = 0;
    int max_pos = 0;
    for(int i = 0; i < N; i++) {
        int p, h;
        cin >> p >> h;

        arr[p] = h;
        
        if(max_height < h) {
            max_height = h;
            max_pos = p;
        }
    }

    int lh = 0;
    int sum = 0;
    for(int i = 1; i <= max_pos; i++) {
        lh = max(lh, arr[i]);
        sum += lh;
    }

    int size = arr.size();
    int rh = 0;
    for(int i = 1000; i > max_pos; i--) {
        rh = max(rh, arr[i]);
        sum += rh;
    }

    cout << sum << '\n';

    return 0;
}