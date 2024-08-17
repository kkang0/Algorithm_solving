#include <iostream>
#include <queue>
using namespace std;

int n, x, y, m;
int relation[101][101];
int visited[101];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (!visited[i] && relation[cur][i]) {
                visited[i] = visited[cur] + 1;
                q.push(i);
            }
        }
    }
}

int main(void) {
    cin >> n;
    cin >> x >> y;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        relation[a][b] = relation[b][a] = 1;
    }

    bfs(x);

    if (visited[y] == 0) 
        cout << -1 << endl;
    else 
        cout << visited[y] << endl;

    return 0;
}
