#include <iostream>
#include <algorithm>
using namespace std;

#define inf 0x7fffffff

const int N = 1000000;
int A[1000001];
int Ai[1000001];
int B[1000001];

int LIS(void) {
    for(int i = 1; i <= N; i++) {
        B[i] = inf;
    }

    for(int i = 1; i <= N; i++) {
        Ai[i] = 1;
        int idx = lower_bound(B + 1, B + N + 1, A[i]) - B;
        Ai[i] = idx;
        B[idx] = min(B[idx], A[i]);
    }

    int ans = 0;
    for(int i = 1; i <= N; i++) {
        ans = max(ans, Ai[i]);
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int len, x, ans;

    cin >> len;
    for(int i = 1; i <= len; i++) {
        cin >> x;
        A[i] = x;
    }

    ans = LIS();
    cout << ans << endl;

    return 0;
}