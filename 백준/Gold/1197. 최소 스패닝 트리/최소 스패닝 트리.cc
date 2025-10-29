#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V, E;
vector<pair<int, pair<int, int>>> graph;
int parent[10001];

int findParent(int x) {
    if(parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    parent[b] = a;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> V >> E;
    for(int i = 0; i < E; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        graph.push_back({C, {A, B}});
    }

    sort(graph.begin(), graph.end());

    for(int i = 1; i <= V; i++) parent[i] = i;

    int result = 0;
    int edgecnt = 0;
    for(int i = 0; i < graph.size(); i++) {
        int cost = graph[i].first;
        int cur = graph[i].second.first;
        int next = graph[i].second.second;

        if(findParent(cur) == findParent(next)) continue;

        unionParent(cur, next);
        result += cost;
        edgecnt++;

        if(edgecnt == V - 1) break;
    }

    cout << result << '\n';

    return 0;
}