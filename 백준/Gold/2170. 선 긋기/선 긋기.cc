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
    vector<pair<int, int>> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), compare);

    int start = v[0].first;
    int end = v[0].first;
    int result = 0;
    for(int i = 0; i < N; i++) {
        if(v[i].first <= end) end = max(end, v[i].second);
        else {
            result += (end - start);
            start = v[i].first;
            end = v[i].second;
        }
    }
    
    result += (end - start);
    cout << result << '\n';

    return 0;
}