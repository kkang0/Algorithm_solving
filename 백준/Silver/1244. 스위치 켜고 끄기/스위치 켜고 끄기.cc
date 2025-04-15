#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> sw(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> sw[i];
    }

    int S;
    cin >> S;
    for (int i = 0; i < S; i++) {
        int s, num;
        cin >> s >> num;

        if (s == 1) {
            for (int j = num; j <= N; j += num) {
                sw[j] = !sw[j];
            }
        } else if (s == 2) {
            sw[num] = !sw[num];
            for (int j = 1; num - j >= 1 && num + j <= N; j++) {
                if (sw[num - j] != sw[num + j]) break;
                sw[num - j] = !sw[num - j];
                sw[num + j] = !sw[num + j];
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << sw[i] << " ";
        if (i % 20 == 0) cout << "\n";
    }
    cout << "\n";

    return 0;
}