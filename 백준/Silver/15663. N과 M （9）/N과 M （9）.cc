#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int nums[9];
int tmp[9];
bool visited[9];

void dfs(int cnt) {
    if(cnt == M) {
        for(int i = 0; i < cnt; i++) cout << tmp[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = 0; i < N; i++) {
        if(visited[i]) continue;
        if(i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;
        
        visited[i] = true;
        tmp[cnt] = nums[i];
        dfs(cnt + 1);
        visited[i] = false;
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