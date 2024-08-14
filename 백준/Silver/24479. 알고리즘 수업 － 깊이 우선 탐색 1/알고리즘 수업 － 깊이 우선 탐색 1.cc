#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check[200000];
int Count[200000];
vector<int> graph[200000];
int visitOrder = 1;

void dfs(int start) {
    if (check[start]) {
        return;
    }
    check[start] = true;
    Count[start] = visitOrder++;
    
    sort(graph[start].begin(), graph[start].end());

    for (int i = 0; i < graph[start].size(); i++) {
        int next = graph[start][i];
        if (!check[next]) {
            dfs(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, First;
    cin >> n >> m >> First;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(First);

    for (int i = 1; i <= n; i++) {
        cout << Count[i] << '\n';
    }

    return 0;
}
