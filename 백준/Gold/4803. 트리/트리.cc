#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[501];
bool visited[501];

bool dfs(int n, int before) {
    visited[n] = true;

    for(int i = 0; i < tree[n].size(); i++) {
        int next = tree[n][i];
        if(next == before) continue;
        if(visited[next]) return false;
        if(!dfs(next, n)) return false;
    }

    return true;
}

int main(void) {
    int num = 0;
    while(true) {
        int n, m;
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        num++;

        for(int i = 1; i <= n; i++) tree[i].clear();

        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;

            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        fill(visited, visited + n + 1, false);

        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(!visited[i]) {
                if(dfs(i, 0)) cnt++;
            }
        }

        cout << "Case " << num << ": ";
        if(cnt > 1) cout << "A forest of " << cnt << " trees." << '\n';
        else if(cnt == 1) cout  << "There is one tree." << '\n';
        else cout << "No trees." << '\n';
    }

    return 0;
}