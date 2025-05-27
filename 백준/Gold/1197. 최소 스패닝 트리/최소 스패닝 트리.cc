#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, pair<int, int>>> graph;
int parent[10001];

int findParent(int v) {
    if(parent[v] == v) return v;
    return parent[v] = findParent(parent[v]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    parent[b] = a;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    cin >> V >> E;

    for(int i = 0; i < E; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        graph.push_back({C, {A, B}});
    }
    sort(graph.begin(), graph.end());

    for(int i = 1; i <= V; i++) parent[i] = i;

    int result = 0;
    int edgeCount = 0;

    for(int i = 0; i < graph.size(); i++) {
        int cost = graph[i].first;
        int cur = graph[i].second.first;
        int next = graph[i].second.second;

        if(findParent(cur) == findParent(next)) continue;

        unionParent(cur, next);
        result += cost;
        edgeCount++;

        if(edgeCount == V - 1) break;
    }

    cout << result << '\n';

    return 0;
}