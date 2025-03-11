#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, n;

bool test(vector<string>& v) {
    sort(v.begin(), v.end());

    for (int i = 0; i < n - 1; i++) {
        if (v[i + 1].find(v[i]) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> n;
        vector<string> v(n);

        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        if (test(v)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}