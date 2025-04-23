#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> v;
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            v.push_back(x);
        }

        long long profit = 0;
        int max_price = -1;
        for (int i = N - 1; i >= 0; i--) {
            max_price = max(max_price, v[i]);
            profit += max_price - v[i];
        }

        cout << profit << "\n";
    }

    return 0;
}