#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> com[101];
bool visited[101];
int cnt = 0;

void dfs(int cur) {
    for(int next: com[cur]) {
        if(visited[next]) continue;
        visited[next] = true;
        cnt++;
        dfs(next);
    }
}


int main(void) {
    cin >> N;
    cin >> M;
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        com[u].push_back(v);
        com[v].push_back(u);
    }

    visited[1] = true;
    dfs(1);

    cout << cnt << endl;

    return 0;
}