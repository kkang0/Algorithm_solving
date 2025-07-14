#include <iostream>
using namespace std;

int N;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    int result = 0;

    while(true) {
        if(N % 5 == 0) {
            cout << N / 5 + result << '\n';
            break;
        }

        if(N < 0) {
            cout << -1 << '\n';
            break;
        }

        N -= 3;
        result++;
    }

    return 0;
}