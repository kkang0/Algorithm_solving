#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> honey(N + 2, 0);
    for (int i = 1; i <= N; i++) cin >> honey[i];

    vector<long long> dp1(N + 2, 0);
    vector<long long> dp2(N + 2, 0);

    for (int i = 1; i <= N; i++) dp1[i] = dp1[i - 1] + honey[i];
    for (int i = N; i >= 1; i--) dp2[i] = dp2[i + 1] + honey[i];

    long long result = 0;

    for (int i = 2; i < N; i++) {
        long long tmp = (dp1[N] * 2) - honey[1] - honey[i] - dp1[i];
        result = max(result, tmp);
    }

    for (int i = N - 1; i >= 2; i--) {
        long long tmp = (dp2[1] * 2) - honey[N] - honey[i] - dp2[i];
        result = max(result, tmp);
    }

    for (int i = 2; i < N; i++) {
        long long tmp = (dp1[i] - dp1[1]) + (dp2[i] - dp2[N]);
        result = max(result, tmp);
    }

    cout << result << "\n";

    return 0;
}