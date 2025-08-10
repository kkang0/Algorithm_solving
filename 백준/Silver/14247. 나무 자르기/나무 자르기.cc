#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<long long, long long> a, pair<long long, long long> b) {
    return a.second < b.second;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> height(n);
    vector<int> weight(n);
    vector<pair<long long, long long>> tree;
    for(int i = 0; i < n; i++) {
        cin >> height[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    for(int i = 0; i < n; i++) {
        tree.push_back({height[i], weight[i]});
    }

    sort(tree.begin(), tree.end(), compare);

    long long result = 0;
    for(int i = 0; i < n; i++) {
        result += tree[i].first + tree[i].second * i;
    }

    cout << result << endl;

    return 0;
}