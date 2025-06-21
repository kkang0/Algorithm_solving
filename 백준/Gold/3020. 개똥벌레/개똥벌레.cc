#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, H;
vector<int> bottom;
vector<int> top;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> H;
    for(int i = 0; i < N; i++) {
        int h;
        cin >> h;
        if(i % 2 == 0) bottom.push_back(h);
        else top.push_back(h);
    }

    sort(bottom.begin(), bottom.end());
    sort(top.begin(), top.end());

    int min = N;
    int result = 0;
    for(int h = 1; h <= H; h++) {
        int cb = bottom.end() - lower_bound(bottom.begin(), bottom.end(), h);
        int ct = top.end() - lower_bound(top.begin(), top.end(), H - h + 1);

        int total = cb + ct;
        if(total < min) {
            min = total;
            result = 1;
        } else if(total == min) result++;
    }

    cout << min << ' ' << result << '\n';

    return 0;
}