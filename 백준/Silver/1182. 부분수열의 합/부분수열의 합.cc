#include <iostream>
using namespace std;

int N, S;
int v[21];
int result;

void dfs(int i, int sum) {
    if(i == N) return;

    if(sum + v[i] == S) result++;

    dfs(i + 1, sum);
    dfs(i + 1, sum + v[i]);
}

int main(void) {
    cin >> N >> S;

    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    dfs(0, 0);

    cout << result << endl;

    return 0;
}