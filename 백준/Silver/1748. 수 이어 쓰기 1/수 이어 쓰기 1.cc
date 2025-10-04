#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int result = 0;
    for(int i = 1; i <= N; i *= 10) {
        result += N - i + 1;
    }

    cout << result << '\n';
    
    return 0;
}