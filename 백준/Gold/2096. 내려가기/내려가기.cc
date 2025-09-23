#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int maxDP[3], minDP[3], input[3];
    cin >> maxDP[0] >> maxDP[1] >> maxDP[2];
    minDP[0] = maxDP[0];
    minDP[1] = maxDP[1];
    minDP[2] = maxDP[2];

    for (int i = 1; i < N; i++) {
        cin >> input[0] >> input[1] >> input[2];

        int prevMax0 = maxDP[0], prevMax2 = maxDP[2];
        int prevMin0 = minDP[0], prevMin2 = minDP[2];

        maxDP[0] = max(maxDP[0], maxDP[1]) + input[0];
        maxDP[2] = max(maxDP[1], maxDP[2]) + input[2];
        maxDP[1] = max({prevMax0, maxDP[1], prevMax2}) + input[1];

        minDP[0] = min(minDP[0], minDP[1]) + input[0];
        minDP[2] = min(minDP[1], minDP[2]) + input[2];
        minDP[1] = min({prevMin0, minDP[1], prevMin2}) + input[1];
    }

    cout << max({maxDP[0], maxDP[1], maxDP[2]}) << " "
         << min({minDP[0], minDP[1], minDP[2]}) << "\n";

    return 0;
}