#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[9];
int result[9];
int visited[9];

void dfs(int cnt) {
    if(cnt == M) {
        for(int i = 0; i < M; i++) cout << result[i] << " ";
        cout << "\n";
        return;
    }

    for(int i = 0; i < N; i++) {
        if(!visited[i]) {
            visited[i] = true;
            result[cnt] = arr[i];
            dfs(cnt + 1);
            visited[i] = false;
        }
    }
}

int main(void) {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);
    dfs(0);

    return 0;
}