#include <iostream>
using namespace std;

bool isPrime[10001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fill(isPrime, isPrime + 10001, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i <= 10000; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= 10000; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        for (int i = n / 2; i >= 2; i--) {
            if (isPrime[i] && isPrime[n - i]) {
                cout << i << ' ' << (n - i) << '\n';
                break;
            }
        }
    }

    return 0;
}