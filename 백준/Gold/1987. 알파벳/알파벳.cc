#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C;
vector<string> alpha;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool used[26];
int result;

void dfs(int x, int y, int cnt) {
    result = max(result, cnt);

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;

        char nc = alpha[nx][ny];
        int idx = nc - 'A';

        if(!used[idx]) {
            used[idx] = true;
            dfs(nx, ny, cnt + 1);
            used[idx] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;
    alpha.resize(R);
    for(int i = 0; i < R; i++) {
        cin >> alpha[i];
    }

    used[alpha[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    cout << result << '\n';

    return 0;
}