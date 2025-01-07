#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int N;
    cin >> N;

    vector<int> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<int> b(N);
    for(int i = 0; i < N; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end());

    int result = 0;
    for(int i = 0; i < N; i++) {
        result += (a[i] * b[i]);
    }

    cout << result << endl;

    return 0;
}