#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int nums[8];
int tmp[8];

void dfs(int cnt) {
    if(cnt == M) {
        for(int i = 0; i < cnt; i++) cout << tmp[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = 0; i < N; i++) {
        if(i > 0 && nums[i] == nums[i - 1]) continue;
        tmp[cnt] = nums[i];
        dfs(cnt + 1);
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
    dfs(0);

    return 0;
}