#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double X, Y;
    cin >> X >> Y;
    int Z = (Y * 100) / X;

    long long start = 0;
    long long end = 1e9;
    while(start <= end) {
        int mid = (start + end) / 2;

        int newZ = ((Y + mid) * 100) / (X + mid);
        if(newZ >= Z + 1) {
            end = mid - 1;
        } else start = mid + 1;
    }

    if(start == 1e9 + 1) cout << -1 << '\n';
    else cout << start << '\n';

    return 0;
}