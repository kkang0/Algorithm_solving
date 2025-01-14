#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> indegree;
vector<int> result;
vector<vector<int>> graph;

int main(void) {
    cin >> N >> M;

    indegree.assign(N + 1, 0);
    graph.assign(N + 1, vector<int>());

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;

        graph[A].push_back(B);
        indegree[B]++;
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        result.push_back(cur);

        for (int next : graph[cur]) {
            if (--indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    for (int node : result) cout << node << " ";

    return 0;
}
