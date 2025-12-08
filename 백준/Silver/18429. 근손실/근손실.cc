#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int kit[9];
bool used[9];
int result;

void dfs(int day, int cur) {
    if(day == N) {
        result++;
        return;
    }

    for(int i = 0; i < N; i++) {
        if(used[i]) continue;

        int next = cur + kit[i] - K;
        if(next < 500) continue;

        used[i] = true;
        dfs(day + 1, next);
        used[i] = false;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    for(int i = 0; i < N; i++) cin >> kit[i];

    dfs(0, 500);

    cout << result << '\n';

    return 0;
}