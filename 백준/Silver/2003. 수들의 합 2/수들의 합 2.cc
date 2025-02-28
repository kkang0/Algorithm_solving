#include <iostream>
using namespace std;

int main(void) {
    int N, M;
    cin >> N >> M;

    int A[10001];
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int start = 0, end = 0, result = A[0], cnt = 0;
    
    while (end < N) {
        if(result == M) {
            cnt++;
            result += A[++end];
        } else if(result < M) {
            result += A[++end];
        } else {
            result -= A[start++];
        }
    }

    cout << cnt << endl;
    return 0;
}