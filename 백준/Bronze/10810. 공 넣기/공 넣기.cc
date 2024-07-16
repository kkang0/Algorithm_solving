#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int v[101] = {0, };
    int i, j, k;
    for(int m = 0; m < M; m++) {
        cin >> i >> j >> k;
        for(int n = i - 1; n < j; n++) {
            v[n] = k;
        }
    }

    for(int i = 0; i < N; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}