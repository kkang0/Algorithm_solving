#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> route;
vector<bool> visited(201);
vector<int> plan;

void dfs(int cur) {
    visited[cur] = true;
    for(int i = 0; i < N; i++) {
        if(route[cur][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    cin >> M;

    route.resize(N, vector<int>(N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> route[i][j];
        }
    }

    plan.resize(M);
    for(int i = 0; i < M; i++) {
        cin >> plan[i];
        plan[i]--;
    }

    dfs(plan[0]);

    for(int i = 0; i < M; i++) {
        if(!visited[plan[i]]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}