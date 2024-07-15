#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int N, x, y;
    cin >> N;

    vector<pair<int, int>> v;
    for(int i = 0; i < N; i++) {
        cin >> x >> y;
        v.push_back(pair<int, int>(y, x));
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < N; i++) {
        cout << v[i].second << " " << v[i].first << '\n';
    }

    return 0;
}