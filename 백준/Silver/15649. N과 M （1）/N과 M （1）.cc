#include <iostream>
#include <vector>
using namespace std;

int N, M;
int nums[9];
bool visited[9];

void dfs(int cnt) {
    if(cnt == M) {
        for(int i = 0; i < cnt; i++) cout << nums[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = 1; i <= N; i++) {
        if(!visited[i]) {
            visited[i] = true;
            nums[cnt] = i;
            dfs(cnt + 1);
            visited[i] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    dfs(0);

    return 0;
}