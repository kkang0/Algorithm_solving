#include <iostream>
using namespace std;

int main(void) {
    int N;
    cin >> N;

    char c;
    int sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> c;
        sum += c - 48;
    }

    cout << sum << endl;

    return 0;
}