#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<pair<pair<int, int>, int>> house;
int parent[100001];

int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if(a != b) parent[b] = a;
}

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    if(a.second == b.second) {
        if(a.first.first == b.first.first) {
            return a.first.second < b.first.second;
        } else return a.first.first < b.first.first;
    }
    return a.second < b.second;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        house.push_back({{A, B}, C});
    }

    for(int i = 1; i <= N; i++) parent[i] = i;

    sort(house.begin(), house.end(), compare);

    int total = 0;
    int maxEdge = 0;
    for(auto& h: house) {
        int u = h.first.first;
        int v = h.first.second;
        int w = h.second;
        if(find(u) != find(v)) {
            unite(u, v);
            total += w;
            maxEdge = max(maxEdge, w);
        }
    }

    cout << total - maxEdge << '\n';

    return 0;
}