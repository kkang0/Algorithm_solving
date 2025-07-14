#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> graph[32001];
vector<int> indegree;
vector<int> result;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    indegree.resize(N + 1, 0);
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;
    for(int i = 1; i <= N; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int n = q.front();
        q.pop();
        
        result.push_back(n);
        for(int i = 0; i < graph[n].size(); i++) {
            int m = graph[n][i];
            if(--indegree[m] == 0) q.push(m);
        }
    }

    for(int r: result) cout << r << ' ';
    cout << '\n';

    return 0;
}