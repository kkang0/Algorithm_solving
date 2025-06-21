#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> meetings;

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int s, e;
        cin >> s >> e;
        meetings.push_back({s, e});
    }

    sort(meetings.begin(), meetings.end(), compare);

    int last_time = 0;
    int result = 0;
    for(int i = 0; i < N; i++) {
        if(meetings[i].first >= last_time) {
            last_time = meetings[i].second;
            result++;
        }
    }

    cout << result << '\n';

    return 0;
}