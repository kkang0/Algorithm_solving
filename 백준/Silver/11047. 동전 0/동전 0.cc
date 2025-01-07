#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int N, K;
    cin >> N >> K;

    vector<int> value;
    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        if (val <= K) value.push_back(val);
    }

    if (value.empty()) {
        cout << 0 << endl;
        return 0;
    }

    int result = 0;
    for (int i = value.size() - 1; i >= 0; i--) {
        result += K / value[i];
        K %= value[i];
    }

    cout << result << endl;

    return 0;
}