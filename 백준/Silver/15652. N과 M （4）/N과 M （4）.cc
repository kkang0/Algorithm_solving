#include <iostream>
using namespace std;

int N, M;
int nums[9];

void dfs(int num, int cnt) {
    if(cnt == M) {
        for(int i = 0; i < cnt; i++) cout << nums[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = num; i <= N; i++) {
        nums[cnt] = i;
        dfs(i, cnt + 1);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    dfs(1, 0);

    return 0;
}