#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X, N;
    cin >> N >> X;

    vector<int> visitor(N);
    for(int i = 0; i < N; i++) {
        cin >> visitor[i];
    }

    int max_visit = 0;
    int sum = 0;
    map<int, int> m;
    for(int i = 0; i < X; i++) {
        sum += visitor[i];
    }
    max_visit = sum;
    m[max_visit]++;

    for(int i = X; i < N; i++) {
        sum += (visitor[i] - visitor[i - X]);
        max_visit = max(max_visit, sum);
        m[sum]++;
    }

    if(max_visit == 0) {
        cout << "SAD" << "\n";
        return 0;
    }

    cout << max_visit << "\n";
    cout << m[max_visit] << "\n";

    return 0;
}