#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int N, K;
    cin >> N >> K;

    vector<int> v(N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }

    sort(v.begin(), v.end());

    cout << v[K - 1] << '\n';

    return 0;
}