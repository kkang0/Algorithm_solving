#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> v[100002];
bool visited[100002];
int result[100002];

void dfs(int n) {
    visited[n] = true;

    for(int i = 0; i < v[n].size(); i++) {
        int next = v[n][i];
        if(!visited[next]) {
            result[next] = n;
            dfs(next);
        }
    }
}

int main(void) {
    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1);

    for(int i = 2; i <= N; i++)
        printf("%d\n", result[i]);

    return 0;
}