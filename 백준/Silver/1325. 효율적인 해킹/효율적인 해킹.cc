#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v[10001];
bool visited[10001];
int result[10001];

int dfs(int n) {
    int count = 1;

    for(int i = 0; i < v[n].size(); i++) {
        int cur_n = v[n][i];

        if(!visited[cur_n]) {
            visited[cur_n] = true;
            count += dfs(cur_n);
        }
    }

    return count;
}

int main(void) {
    cin >> N >> M;
    int max_count = 0;

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }

    for(int i = 1; i <= N; i++) {
        fill(visited, visited + N + 1, false);

        visited[i] = true;
        result[i] = dfs(i);
        max_count = max(max_count, result[i]);
    }

    for(int i = 1; i <= N; i++) {
        if(result[i] == max_count)
            cout << i << " ";
    }
    cout << endl;

    return 0;
}