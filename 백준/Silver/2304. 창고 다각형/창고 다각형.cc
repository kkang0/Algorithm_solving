#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++) {
        int L, H;
        cin >> L >> H;
        v.push_back({L, H});
    }

    sort(v.begin(), v.end(), compare);

    auto it = max_element(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });
    int idx = distance(v.begin(), it);

    int result = 0;

    int max_h = v[0].second;
    int pos = v[0].first;
    for (int i = 1; i <= idx; i++) {
        if (v[i].second >= max_h) {
            result += (v[i].first - pos) * max_h;
            max_h = v[i].second;
            pos = v[i].first;
        }
    }

    max_h = v.back().second;
    pos = v.back().first;
    for (int i = N - 2; i >= idx; i--) {
        if (v[i].second >= max_h) {
            result += (pos - v[i].first) * max_h;
            max_h = v[i].second;
            pos = v[i].first;
        }
    }

    result += v[idx].second;

    cout << result << '\n';

    return 0;
}