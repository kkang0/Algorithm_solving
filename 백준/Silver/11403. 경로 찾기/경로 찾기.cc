#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
vector<int> graph[101];
bool visited[101];

void dfs(int cur) {
    for(int next: graph[cur]) {
        if(visited[next]) continue;
        visited[next] = true;
        dfs(next);
    }
}

int main(void) {
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int n;
            cin >> n;
            if(n == 1) {
                graph[i].push_back(j);
            }
        }
    }

    for(int i = 0; i < N; i++) {
        memset(visited, false, sizeof(visited));

        dfs(i);

        for(int j = 0; j < N; j++) {
            cout << visited[j] << " ";
        }
        cout << endl;
    }

    return 0;
}