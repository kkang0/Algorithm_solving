#include <iostream>
#include <vector>
using namespace std;

vector<int> neuron[100001];
bool visited[100001];
int result = 0;

void dfs(int n) {
    if(visited[n]) return;
    visited[n] = true;

    for(int next: neuron[n]) {
        dfs(next);
    }
}

int main(void) {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        neuron[u].push_back(v);
        neuron[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i);
            result++;
        }
    }

    cout << (result - 1) + (M + result - 1) - (N - 1) << endl;

    return 0;
}