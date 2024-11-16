#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int findParent(int node, vector<int>& parent) {
    if (parent[node] == node) return node;
    return parent[node] = findParent(parent[node], parent);
}

void unionNodes(int a, int b, vector<int>& parent) {
    a = findParent(a, parent);
    b = findParent(b, parent);
    if (a != b) parent[a] = b;
}

int solution(int n, vector<vector<int>> costs) {
    sort(costs.begin(), costs.end(), [](vector<int> a, vector<int> b) {
        return a[2] < b[2];
    });

    vector<int> parent(n);
    for (int i = 0; i < n; i++) parent[i] = i;

    int answer = 0;
    for (auto edge : costs) {
        int start = edge[0];
        int end = edge[1];
        int cost = edge[2];

        if (findParent(start, parent) != findParent(end, parent)) {
            unionNodes(start, end, parent);
            answer += cost;
        }
    }

    return answer;
}