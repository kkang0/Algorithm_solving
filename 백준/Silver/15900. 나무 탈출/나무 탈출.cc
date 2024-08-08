#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> graph[500001];
int visited[500001];
int depth = 0;

void dfs(int node, int count) {
    if(graph[node].size() == 1 && node != 1) {
        depth += count;
        return;
    }
    
    for(int i = 0; i < graph[node].size(); i++) {
        if(!visited[graph[node][i]]) {
            visited[graph[node][i]] = true;
            dfs(graph[node][i], count + 1);
            visited[graph[node][i]] = false;
        }
    }
}

int main(void) {
    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    visited[1] = true;
    dfs(1, 0);

    if(depth % 2 == 0) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}