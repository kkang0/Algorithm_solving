#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int A[100001];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A, A + N);

    cin >> M;
    for(int i = 0; i < M; i++) {
        int b;
        cin >> b;
        if(binary_search(A, A + N, b)) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

    return 0;
}