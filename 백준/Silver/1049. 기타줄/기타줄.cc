#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    
    int min_package = 1000;
    int min_single = 1000;
    for(int i = 0; i < M; i++) {
        int p, s;
        cin >> p >> s;

        min_package = min(min_package, p);
        min_single = min(min_single, s);
    }

    cout << min({(N / 6 + 1) * min_package, (N / 6) * min_package + (N % 6) * min_single, N * min_single}) << '\n';

    return 0;
}