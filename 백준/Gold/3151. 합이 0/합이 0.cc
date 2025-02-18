#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    long long result = 0;
    for(int i = 0; i < N - 1; i++) {
        for(int j = i + 1; j < N; j++) {
            long long sum = v[i] + v[j];

            int front = lower_bound(v.begin() + j + 1, v.end(), -sum) - v.begin();
            int end = upper_bound(v.begin() + j + 1, v.end(), -sum) - v.begin();

            result += (end - front); 
        }
    }

    cout << result << endl;

    return 0;
}