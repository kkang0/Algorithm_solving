#include <iostream>
#include <vector>
using namespace std;

int N, M;
int nums[9];
bool visited[9];

void dfs(int num, int cnt) {
    if(cnt == M) {
        for(int i = 0; i < M; i++) cout << nums[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = num; i <= N; i++) {
        visited[num] = true;
        nums[cnt] = i;
        dfs(i + 1, cnt + 1);
        visited[num]= false;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    dfs(1, 0);

    return 0;
}