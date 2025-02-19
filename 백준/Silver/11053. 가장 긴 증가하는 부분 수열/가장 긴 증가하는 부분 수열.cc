#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int N;
    cin >> N;

    int A[1001], dp[1001];

    for(int i = 0; i < N; i++) {
        cin >> A[i];
        dp[i] = 1;
    }

    int result = 1;
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(A[j] < A[i]) {  
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        result = max(result, dp[i]);
    }

    cout << result << endl;
    return 0;
}