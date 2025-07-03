#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int nums[9];
int tmp[9];

void dfs(int idx, int cnt) {
    if(cnt == M) {
        for(int i = 0; i < cnt; i++) cout << tmp[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = idx; i < N; i++) {
        tmp[cnt] = nums[i];
        dfs(i + 1, cnt + 1);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    sort(nums, nums + N);
    dfs(0, 0);

    return 0;
}